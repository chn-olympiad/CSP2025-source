#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e4 + 15;
int n, m, k, fa[1025][N], cnt, a[15], U, V;
ll ans[1025];
int get(int x, int v) {
  return fa[v][x] == x ? x : fa[v][x] = get(fa[v][x], v);
}
inline void merge(int x, int y, int v) {
  x = get(x, v), y = get(y, v);
  fa[v][x] = y;
}
struct edge {
  int u, v, w, ty;
  friend bool operator<(const edge& a, const edge& b) {
    return a.w < b.w;
  }
} g1[1000005], g2[120005];
int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 0; i < 1 << k; i++) for (int j = 1; j <= n + 12; j++) {
    fa[i][j] = j;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g1[i] = {u, v, w, -1};
  }
  sort(g1 + 1, g1 + m + 1);
  for (int i = 1; i <= m; i++) {
    auto [u, v, w, t] = g1[i];
    if ((U = get(u, 0)) != (V = get(v, 0))) {
      merge(U, V, 0);
      g2[++cnt] = {u, v, w, -1};
      ans[0] += w;
    }
  }
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    for (int j = 1; j <= n; j++) {
      int w;
      cin >> w;
      g2[++cnt] = {n + i + 1, j, w, i};
    }
  }
  sort(g2 + 1, g2 + cnt + 1);
  for (int i = 1; i <= cnt; i++) {
    auto [u, v, w, t] = g2[i];
    if (t == -1) {
      for (int msk = 1; msk < 1 << k; msk++) {
        if ((U = get(u, msk)) != (V = get(v, msk))) {
          merge(U, V, msk);
          ans[msk] += w;
        }
      }
    } else {
      for (int msk = 1; msk < 1 << k; msk++) if (msk >> t & 1) {
        if ((U = get(u, msk)) != (V = get(v, msk))) {
          merge(U, V, msk);
          ans[msk] += w;
        }
      }
    }
  }
  for (int i = 0; i < k; i++) for (int msk = 0; msk < 1 << k; msk++) if (msk >> i & 1) ans[msk] += a[i];
  ll res = 1e18;
  for (int i = 0; i < 1 << k; i++) res = min(res, ans[i]);
  cout << res << endl;
}