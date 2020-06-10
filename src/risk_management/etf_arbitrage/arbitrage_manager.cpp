// Copyright [2020] <Copyright Kevin, kevin.lau.gd@gmail.com>

#include "risk_management/etf_arbitrage/arbitrage_manager.h"

#include "risk_management/etf_arbitrage/etf_table.h"

namespace ft {

bool ArbitrageManager::init(const Config& config, Account* account,
                            Portfolio* portfolio,
                            std::map<uint64_t, Order>* order_map,
                            const MdSnapshot* md_snapshot) {
  if (config.arg0.empty() || config.arg1.empty()) return false;

  account_ = account;
  portfolio_ = portfolio;
  order_map_ = order_map;
  md_snapshot_ = md_snapshot;

  return EtfTable::init(config.arg0, config.arg1);
}

int ArbitrageManager::check_order_req(const Order* order) { return NO_ERROR; }

}  // namespace ft
