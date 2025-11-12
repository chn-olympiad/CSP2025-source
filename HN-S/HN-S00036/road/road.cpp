#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e4 + 15;

struct Edge {
  int u, v, w;
  bool operator<(const Edge &oth) const {
    return w < oth.w;
  }
};

int n, m, k, fa[MAXN], sz[MAXN], mi[MAXN];
vector<Edge> e;

int Find(int x) {
  return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void Merge(int x, int y) {
  x = Find(x), y = Find(y);
  if (sz[x] > sz[y]) swap(x, y);
  if (x != y) {
    fa[x] = y, sz[y] += sz[x];
  }
}

namespace MST {
  void Solve() {
    iota(fa + 1, fa + n + 1, 1);
    fill(sz + 1, sz + n + 1, 1);
    sort(e.begin(), e.end());
    ll ans = 0;
    for (Edge &i : e) {
      if (Find(i.u) == Find(i.v)) continue;
      Merge(i.u, i.v);
      ans += i.w;
    }
    cout << ans;
  }
}

namespace Special {
  int deg[MAXN];
  void Solve() {
    iota(fa + 1, fa + n + k + 1, 1);
    fill(sz + 1, sz + n + k + 1, 1);
    sort(e.begin(), e.end());
    ll ans = 0;
    for (Edge &i : e) {
      if (Find(i.u) == Find(i.v)) continue;
      Merge(i.u, i.v);
      deg[i.u] += i.u > n;
      deg[i.v] += i.v > n;
      ans += i.w;
    }
    for (int i = n + 1; i <= n + k; i++) {
      if (deg[i] == 1) ans -= mi[i];
    }
    cout << ans;
  }
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    e.push_back({u, v, w});
  }
  if (k == 0) {
    MST::Solve();
    return 0;
  }
  bool flag = 1;
  for (int i = n + 1, c; i <= n + k; i++) {
    cin >> c;
    flag &= !c;
    mi[i] = INT_MAX;
    for (int j = 1, w; j <= n; j++) {
      cin >> w;
      e.push_back({i, j, w});
      mi[i] = min(mi[i], w);
    }
  }
  if (flag) {
    Special::Solve();
    return 0;
  }
  return 0;
}

