#include<bits/stdc++.h>
#include<bits/extc++.h>
using ll = long long; using ull = unsigned long long;
#define ld std::cin
#define jyt std::cout
#define cmd std::cerr
#define REQ(i, l, r) for (int i = l; i <  r; ++i)
#define REP(i, l, r) for (int i = l; i <= r; ++i)
#define PER(i, l, r) for (int i = l; i >= r; --i)
namespace JoKing { // JoKing 57min Accepted
   const int N = 2e4 + 7, M = 2e6 + 7, MAXK = 13;
   const ll inf = 2e18 + 7;
   int n, m, q, K, cost[MAXK], a[MAXK][N], d_fa[N], d_sz[N];
   struct Edge {int u, v, w;} e[M], c[M];
   inline int gf(int x) {return (d_fa[x] == x ? x : (d_fa[x] = gf(d_fa[x])));}
   inline void onion(int x, int y) {
      if ((x = gf(x)) == (y = gf(y))) return;
      if (d_sz[x] > d_sz[y]) std::swap(x, y);
      d_fa[x] = y, d_sz[y] += d_sz[x]; 
   }
   signed main() {
      ld >> n >> m >> K;
      REP(i, 1, m) ld >> e[i].u >> e[i].v >> e[i].w;
      std::sort(e + 1, e + m + 1, [](Edge X, Edge Y) {return X.w < Y.w;});
      REP(i, 1, n) d_fa[i] = i, d_sz[i] = 1;
      REP(i, 1, m) {
         if (gf(e[i].u) == gf(e[i].v)) continue;
         onion(e[i].u, e[i].v), c[++q] = e[i];
      }
      REP(i, 1, K) {
         ld >> cost[i];
         REP(j, 1, n) ld >> a[i][j], c[++q] = (Edge) {n + i, j, a[i][j]}; 
      }
      std::sort(c + 1, c + q + 1, [](Edge X, Edge Y) {return X.w < Y.w;});
      ll Ans = inf;
      REP(Mask, 0, (1 << K) - 1) {
         REP(i, 1, n + K) d_fa[i] = i, d_sz[i] = 1;
         int target = n, _ = 1; ll Res = 0; 
         REP(i, 1, K) if (Mask & (1 << (i - 1))) Res += cost[i], ++target;
         REP(i, 1, q) {
            if (c[i].u > n && !(Mask & (1 << (c[i].u - n - 1)))) continue;
            if (gf(c[i].u) == gf(c[i].v)) continue;
            onion(c[i].u, c[i].v), Res += c[i].w, ++_;
            if (target == _ || Res > Ans) break; 
         }
         Ans = std::min(Ans, Res);
      }
      jyt << Ans << '\n';
      return 0;
   }
}
signed main() { // MAX 0.95s EXPECT 0.5s
#ifdef WYY
   freopen("road114.in", "r", stdin);
   // freopen("road114.out", "w", stdout);
#else
   freopen("road.in", "r", stdin);
   freopen("road.out", "w", stdout);
#endif
   std::ios::sync_with_stdio(false), ld.tie(0), jyt.tie(0);
   JoKing::main();
#ifdef WYY
   // while(true);
#endif
   return 0;
}
/*
MST 问题。
但是有一些边需要 c_i 的代价去启用。
暴力是 O(2^10 \times 10^6 \times \alpha(10^5)) 的。
原有的非最小生成树边没有用。
边集优化为 10^5 级别，可以通过。
*/