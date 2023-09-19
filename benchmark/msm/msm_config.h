#ifndef BENCHMARK_MSM_MSM_CONFIG_H_
#define BENCHMARK_MSM_MSM_CONFIG_H_

#include <stdint.h>

#include <string>
#include <vector>

namespace tachyon {

class MSMConfig {
 public:
  enum class Vendor {
    kArkworks,
    kBellman,
  };

  struct Options {
    bool include_vendors = false;
    bool include_algos = false;
  };

  static std::string VendorToString(Vendor vendor);

  MSMConfig() = default;
  MSMConfig(const MSMConfig& other) = delete;
  MSMConfig& operator=(const MSMConfig& other) = delete;

  const std::vector<uint64_t>& degrees() const { return degrees_; }
  const std::vector<Vendor>& vendors() const { return vendors_; };
  int algorithm() const { return algorithm_; }
  bool check_results() const { return check_results_; }

  bool Parse(int argc, char** argv, const Options& options);

  std::vector<uint64_t> GetPointNums() const;

 private:
  std::vector<uint64_t> degrees_;
  std::vector<Vendor> vendors_;
  int algorithm_ = 0;
  bool check_results_ = false;
};

}  // namespace tachyon

#endif  // BENCHMARK_MSM_MSM_CONFIG_H_
