// connection.h
// Author: Allen Porter <allen@thebends.org> (pin)
// Much code in this module was based on the iPhoneInterface tool by:
//   geohot, ixtli, nightwatch, warren, nail, Operator
// See http://iphone.fiveforty.net/wiki/

#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#include <string>
#include <vector>

namespace iphonedisk {

// Implementations of the Connection class must be threadsafe.
class Connection {
 public:
  virtual ~Connection() { }

  // Should be invoked before using the connection
  virtual void WaitUntilConnected() = 0;

  virtual bool IsDirectory(const std::string& path) = 0;

  virtual bool IsFile(const std::string& path) = 0;

  virtual bool Unlink(const std::string& path) = 0;

  virtual bool Mkdir(const std::string& path) = 0;

  virtual bool ListFiles(const std::string& dir,
                         std::vector<std::string>* files) = 0;

  virtual bool ReadFileToString(const std::string& path,
                                std::string* data) = 0;

  virtual bool WriteStringToFile(const std::string& path,
                                 const std::string& datas) = 0;

 protected:
  // cannot be instantiated directly
  Connection() { }
};

// Not thread safe
Connection* GetConnection();

}  // namespace

#endif