#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  freopen("road.in", "r", stdin),
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  using tuple3 = tuple<int, int, int>;
  vector<tuple3> edge(m), e;
  for (auto &[u, v, w] : edge) cin >> u >> v >> w;
  sort(edge.begin(), edge.end(), [&](tuple3 a, tuple3 b) {
    return get<2>(a) < get<2>(b);
  });
  vector<int> fa(n + 15); iota(fa.begin(), fa.end(), 0);
  function<int(int)> find = [&](int u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
  };
  int ans = 0;
  for (auto &[u, v, w] : edge) {
    int fu = find(u), fv = find(v);
    if (fu == fv) continue;
    fa[fu] = fv, e.push_back({u, v, w}), ans += w;
  }
  vector<int> c(k);
  vector<vector<int>> a(k, vector<int>(n + 1));
  for (int i = 0; i < k; i++) {
    cin >> c[i];
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  }

  //cerr << ans << endl;

  for (int i = 0; i < (1 << k); i++) if(i) {
    auto g = e;
    int res = 0;
    for (int j = 0; j < k; j++) if (i & (1 << j)) {
      int u = j + n + 1; res += c[j];
      for (int v = 1; v <= n; v++)
        g.push_back({u, v, a[j][v]});
    }
    sort(g.begin(), g.end(), [&](tuple3 a, tuple3 b) {
      return get<2>(a) < get<2>(b);
    });
    iota(fa.begin(), fa.end(), 0);
    for (auto &[u, v, w] : g) {
      //cerr << u << ' ' << v << ' ' << w << endl;
      int fu = find(u), fv = find(v);
      if (fu == fv) continue;
      fa[fu] = fv, res += w;
    }
    //cerr << i << ' ' << res << endl;
    ans = min(ans, res);
  }
  cout << ans << endl;
  return 0;
}