#include <bits/stdc++.h>
using ll = long long;

template <class T>
using V = std::vector<T>;

int main() {
  std::cin.tie(0)->sync_with_stdio(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  int n, m, k;
  std::cin >> n >> m >> k;
  V<int> c(k + 1);
  V<V<int>> d(k + 1, V<int>(n + 1)), p(k + 1, V<int>(n));
  auto merge = [&](V<std::tuple<int, int, int>> e, int q, V<std::tuple<int, int, int>> &re) {
    V<int> fa(n + k + 1);
    std::iota(fa.begin(), fa.end(), 0);
    auto find = [&](int u) {
      while (fa[u] != u) u = fa[u] = fa[fa[u]];
      return u;
    };
    re.clear();
    auto add_edge = [&](int u, int v, int w) {
      if (find(u) != find(v)) {
        re.emplace_back(w, u, v);
        fa[find(u)] = v;
      }
    };
    int i = 0;
    for (auto &[w, u, v] : e) {
      if (q) while (i < n && d[q][p[q][i]] < w) add_edge(n + q, p[q][i], d[q][p[q][i]]), i++;
      add_edge(u, v, w);
    }
  };
  V<std::tuple<int, int, int>> e(m);
  for (auto &[w, u, v] : e) std::cin >> u >> v >> w;
  for (int i = 1; i <= k; i++) {
    std::cin >> c[i];
    for (int j = 1; j <= n; j++) std::cin >> d[i][j], p[i][j - 1] = j;
    std::sort(p[i].begin(), p[i].end(), [&](int x, int y) { return d[i][x] < d[i][y]; });
  }
  V<V<std::tuple<int, int, int>>> sk(k + 1);
  std::sort(e.begin(), e.end());
  merge(e, 0, sk[0]);
  
  ll ans = 1e18;
  auto dfs = [&](auto &self, int u, ll ec) -> void {
    if (u == k + 1) {
      ll sum = 0;
      for (auto &[w, u, v] : sk.back()) sum += w;
      ans = std::min(ans, ec + sum);
      return;
    }
    sk[u] = sk[u - 1];
    self(self, u + 1, ec);
    merge(sk[u - 1], u, sk[u]);
    self(self, u + 1, ec + c[u]);
  };
  dfs(dfs, 1, 0);
  std::cout << ans << '\n';
}