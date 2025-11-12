/**
 * 年挽红枫，溪傍芦荻
 *
 * @file  road.cpp
 * @data  2025-11-01 15:18:23
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>

using i64 = long long;

template <class T>
inline void ck_mx(T &x, T y) { x < y && (x = y, 1); }
template <class T>
inline void ck_mn(T &x, T y) { y < x && (x = y, 1); }

#define file(s) \
   std::freopen(#s ".in", "r", stdin), std::freopen(#s ".out", "w", stdout)

namespace DataStruct {

template <int N>
class Disjoint {
 public:
   inline void reset(int n) { std::memset(_fa + 1, 0, n * sizeof(int)); }
   int find(int x) { return _fa[x] ? _fa[x] = find(_fa[x]) : x; }
   inline void merge(int x, int y) { _fa[find(x)] = find(y); }

 private:
   int _fa[N];
};

}  // namespace DataStruct
using namespace DataStruct;

constexpr int N = 1e4 + 5;
constexpr int M = 1e6 + 5;
constexpr int K = 10 + 5;

int n, m, k;
struct Road {
   int u, v, w;

   bool operator <(const Road &r) const { return w < r.w; }
} r[M];
std::pair<int, int> a[K][N];

Disjoint<N + K> dsu;
int p[K];

int main() {
   std::cin.tie(nullptr)->sync_with_stdio(false);

   file(road);
#ifdef DEBUG
   file(cur);
#endif

   std::cin >> n >> m >> k;
   if (n == 1) return std::cout << "0\n", 0;

   for (int i = 1; i <= m; ++i) std::cin >> r[i].u >> r[i].v >> r[i].w;
   for (int i = 1; i <= k; ++i) {
      for (int j = 0, x; j <= n; ++j) std::cin >> x, a[i][j] = {x, j};
      std::sort(a[i] + 1, a[i] + n + 1);
   }

   std::sort(r + 1, r + m + 1);
   i64 res = 0;

   for (int i = 1, cnt = 0; i <= m && cnt < n - 1; ++i) {
      auto [u, v, w] = r[i];
      if (dsu.find(u) ^ dsu.find(v))
         dsu.merge(u, v), res += r[i].w, std::swap(r[i], r[++cnt]);
   }

   for (int S = 1; S < 1 << k; ++S) {
      i64 ans = 0;
      std::priority_queue<std::pair<int, int>> q;

      std::memset(p, 0, (k + 1) * sizeof(int)), q.push({-r[1].w, 0});
      for (int i = 1; i <= k; ++i) if (S >> i - 1 & 1)
         ans += a[i][0].first, q.push({-a[i][1].first, i});

      dsu.reset(n + k);
      for (int cnt = 0 - __builtin_popcount(S); cnt < n - 1; ) {
         int x = q.top().second;
         q.pop();

         if (!x) {
            auto [u, v, w] = r[++p[0]];
            if (dsu.find(u) ^ dsu.find(v)) dsu.merge(u, v), ans += w, ++cnt;

            if (p[0] < n - 1) q.push({-r[p[0] + 1].w, 0});
         } else {
            int u = x + n;
            auto [w, v] = a[x][++p[x]];
            if (dsu.find(u) ^ dsu.find(v)) dsu.merge(u, v), ans += w, ++cnt;

            if (p[x] < n) q.push({-a[x][p[x] + 1].first, x});
         }
      }

      ck_mn(res, ans);
   }

   std::cout << res << '\n';

   return 0;
}
