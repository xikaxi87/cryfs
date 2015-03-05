#pragma once
#ifndef BLOBSTORE_IMPLEMENTATIONS_BLOCKED_BLOBSTOREONBLOCKS_H_
#define BLOBSTORE_IMPLEMENTATIONS_BLOCKED_BLOBSTOREONBLOCKS_H_

#include "../../interface/BlobStore.h"
#include "messmer/blockstore/interface/BlockStore.h"

namespace blobstore {
namespace onblocks {
namespace datatreestore {
class DataTreeStore;
}

class BlobStoreOnBlocks: public BlobStore {
public:
  BlobStoreOnBlocks(std::unique_ptr<blockstore::BlockStore> blockStore, uint32_t blocksizeBytes);
  virtual ~BlobStoreOnBlocks();

  std::unique_ptr<Blob> create() override;
  std::unique_ptr<Blob> load(const blockstore::Key &key) override;

private:
  std::unique_ptr<datatreestore::DataTreeStore> _dataTreeStore;
};

}
}

#endif
