// g++ -std=c++14 -O2 -fsanitize=address,undefined -o gen gen.cpp && ./gen
#include <bits/stdc++.h>

// #define int int64_t

std::mt19937 rnd(std::random_device{}());

void dickdreamer() {
  int n = 2e5, m = 2e5;
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= m; ++i) {
    int len = 25, p = rnd() % len + 1;
    for (int j = 1; j <= len; ++j) std::cout << (j == p ? 'b' : 'a');
    std::cout << ' ';
    for (int j = 1; j <= len; ++j) std::cout << (j == p ? 'c' : 'a');
    std::cout << '\n';
  }
  for (int i = 1; i <= m; ++i) {
    int len = 25, p = rnd() % len + 1;
    for (int j = 1; j <= len; ++j) std::cout << (j == p ? 'b' : 'a');
    std::cout << ' ';
    for (int j = 1; j <= len; ++j) std::cout << (j == p ? 'c' : 'a');
    std::cout << '\n';
  }
}

int32_t main() {
  freopen("replace.in", "w", stdout);
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  // std::cin >> T;
  while (T--) dickdreamer();
  // std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}