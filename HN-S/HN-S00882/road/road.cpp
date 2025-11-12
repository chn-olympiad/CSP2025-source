#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
   freopen("road.in", "r", stdin);
   freopen("road.out", "w", stdout);
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n, m, k;
   cin >> n >> m >> k;
   vector<tuple<int, int, int>> e;
   vector<vector<tuple<int, int, int>>> g(k + 1);
   for (int i = 1, x, y, w; i <= m; i++) cin >> x >> y >> w, e.emplace_back(w, x, y);
   vector<int> c(k + 1);
   for (int i = 1; i <= k; i++) {
      cin >> c[i];
      for (int j = 1, x; j <= n; j++) cin >> x, g[i].emplace_back(x, n + i, j);
      sort(g[i].begin(), g[i].end());
   }
   sort(e.begin(), e.end());
   vector<int> fa(n + k + 1);
   iota(fa.begin(), fa.end(), 0);
   function<int(int)> find = [&](int x) { return fa[x] ^ x ? fa[x] = find(fa[x]) : x; };
   auto merge = [&](int x, int y) -> bool {
      x = find(x), y = find(y);
      if (x == y) return 0;
      return fa[x] = y, 1;
   };
   for (auto [w, x, y] : e)
      if (merge(x, y))
         g[0].emplace_back(w, x, y);
   int ans = 1e18;
   for (int i = 0; i < 1 << k; i++) {
      vector<int> pos(k + 1);
      int cnt = 0, res = 0;
      iota(fa.begin(), fa.end(), 0);
      while (cnt < n + __builtin_popcount(i) - 1) {
         int p = -1;
         for (int j = 0; j <= k; j++) {
            if (j && !(i >> j - 1 & 1)) continue;
            if (pos[j] < g[j].size() && (!~p || get<0>(g[j][pos[j]]) < get<0>(g[p][pos[p]]))) p = j;
         }
         auto [w, x, y] = g[p][pos[p]];
         if (merge(x, y)) cnt++, res += w;
         pos[p]++;
      }
      for (int j = 1; j <= k; j++)
         if (i >> j - 1 & 1)
            res += c[j];
      ans = min(ans, res);
   }
   cout << ans;
   return 0;
}