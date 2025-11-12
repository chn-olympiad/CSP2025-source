// g++ -std=c++14 -O2 -fsanitize=address,undefined -o gen gen.cpp && ./gen
#include <bits/stdc++.h>

// #define int int64_t

std::mt19937 rnd(std::random_device{}());

void dickdreamer() {
  int n = 1e4, m = 1e6, k = 10;
  std::cout << n << ' ' << m << ' ' << k << '\n';
  for (int i = 1; i <= m; ++i) {
    int u = rnd() % n + 1, v = rnd() % n + 1, w = rnd() % 1000000001;
    std::cout << u << ' ' << v << ' ' << w << '\n';
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) std::cout << rnd() % 1000000001 << " \n"[j == n];
  }
}

int32_t main() {
  freopen("road.in", "w", stdout);
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  // std::cin >> T;
  while (T--) dickdreamer();
  // std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}