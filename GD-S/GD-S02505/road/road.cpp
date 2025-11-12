#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr, ##__VA_ARGS__)
#else
#define debug(...) void(0)
#define endl "\n"
#endif
using LL = long long;
constexpr int N = 1e4 + 100;
template <int N>
struct unionset {
  int fa[N], siz[N];
  unionset() { iota(fa, fa + N, 0), fill(siz, siz + N, 1); }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y], fa[y] = x;
    return true;
  }
};
struct edge {
  int u, v, w, id;
  bool operator<(const edge& rhs) const { return w < rhs.w; }
};
int n, m, k, c[20];
vector<edge> es;
LL solve(int S) {
  unionset<N> dsu;
  LL res = 0;
  for (auto e : es) {
    if (e.id == -1 || (S >> e.id & 1)) {
      if (dsu.merge(e.u, e.v)) res += e.w;
    }
  }
  return res;
}
int main() {
#ifndef LOCAL
#ifndef NF
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
#endif
  cin >> n >> m >> k;
  vector<edge> es0(m);
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    es0[i - 1] = {u, v, w, -1};
  }
  sort(es0.begin(), es0.end());
  unionset<N> dsu0;
  es.reserve(m);
  for (auto e : es0) {
    if (dsu0.merge(e.u, e.v)) es.push_back(e);
  }
  for (int i = 0; i < k; i++) {
    cin >> c[i];
    for (int j = 1, w; j <= n; j++) cin >> w, es.push_back({n + 1 + i, j, w, i});
  }
  sort(es.begin(), es.end());
  LL ans = 1e18;
  for (int S = 0; S < 1 << k; S++) {
    LL sum = 0;
    for (int i = 0; i < k; i++) if (S >> i & 1) sum += c[i];
    ans = min(ans, solve(S) + sum);
  }
  cout << ans << endl;
  return 0;
}

