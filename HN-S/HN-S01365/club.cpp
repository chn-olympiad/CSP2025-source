/**
 * 年挽红枫，溪傍芦荻
 *
 * @file  club.cpp
 * @data  2025-11-01 14:38:16
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>

#define file(s) \
   std::freopen(#s ".in", "r", stdin), std::freopen(#s ".out", "w", stdout)

constexpr int N = 1e5 + 5;

int n, p[N];
std::pair<int, int> a[N][3];

void work() {
   std::cin >> n;
   for (int i = 1, x; i <= n; ++i) {
      for (int j : {0, 1, 2}) std::cin >> x, a[i][j] = {x, j};
      std::sort(a[i], a[i] + 3);
   }

   std::iota(p, p + n + 1, 0);
   std::sort(p + 1, p + n + 1,
             [](int i, int j) -> bool { return a[i][2] > a[j][2]; });

   int res = 0, cnt[3] = {0, 0, 0};
   std::priority_queue<int> q[3];

   for (int i = 1; i <= n; ++i) {
      int x = p[i];
      auto [w1, j] = a[x][2];
      auto [w2, k] = a[x][1];

      if (cnt[j] == n >> 1) {
         if (w1 + q[j].top() > w2)
            res += w1 + q[j].top(), q[j].pop(), q[j].push(w2 - w1);
         else res += w2;
      } else res += w1, q[j].push(w2 - w1), ++cnt[j];
   }

   std::cout << res << '\n';
}

int main() {
   std::cin.tie(nullptr)->sync_with_stdio(false);

   file(club);
#ifdef DEBUG
   file(cur);
#endif

   int _T;
   for (std::cin >> _T; _T--; ) work();

   return 0;
}
