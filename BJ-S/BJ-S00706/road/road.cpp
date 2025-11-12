#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e7 + 5, K = 15;
int n, m, k, b[N], a[K][N];
long long ans;
struct node {
  int u, v, w;
  bool operator < (const node& rhs) const {
    return w < rhs.w;
  }
} r[M];
struct dsu {
  int fa[N];
  void init(int sz) {
    for (int i = 1; i <= sz; i++) fa[i] = i;
  }
  int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
  }
  bool merge(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu == fv) return 0;
    fa[fu] = fv;
    return 1;
  }
} t;
int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v, w; cin >> u >> v >> w;
    r[i] = {u, v, w};
  }
  fill(b + 1, b + n + 1, (int) 1e9);
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      int x; cin >> x;
      a[i][j] = x;
      b[j] = min(b[j], x);
    }
  }
  if (k > 0) {
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= n; j++) {
        r[++m] = {j, n + i, a[i][j]};
      }
    }
    t.init(n + k);
  }
  else t.init(n);
  sort(r + 1, r + m + 1);
  for (int i = 1; i <= m; i++) {
    int u = r[i].u, v = r[i].v, w = r[i].w;
    if (t.merge(u, v)) {
      ans += w;
    }
  }
  cout << ans << '\n';
  return 0;
}