#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = ll(1e15);
const int MAXN = 1e4 + 15, MAXM = 1e6 + 5;

struct Edge {
  int u, v, w;
  bool operator <(const Edge &i) const {
    return w < i.w;
  }
} e[MAXM], t[MAXM], g[MAXN], eg[11][MAXN];

ll sum, ans = INF;
int n, m, k, T, fa[MAXN], cost[MAXN];

int getf(int u) {
  return (fa[u] ? fa[u] = getf(fa[u]) : u);
}

bool Merge(int u, int v) {
  u = getf(u), v = getf(v);
  if (u == v) return 0;
  fa[u] = v; return 1;
}

ll Solve(bool f, ll sum) {
  fill(fa + 1, fa + n + T + 1, 0);
  for (int i = 1; i <= m; i++) {
    if (Merge(e[i].u, e[i].v)) {
      sum += e[i].w;
      if (f) g[++k] = e[i];
    }
  }
  return sum;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> T;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  sort(e + 1, e + m + 1), ans = Solve(1, 0);
  for (int i = 0; i < T; i++) {
    cin >> cost[i];
    for (int x = 1, w; x <= n; x++) {
      cin >> w, eg[i][x] = {i + n + 1, x, w};
    }
    sort(eg[i] + 1, eg[i] + n + 1);
  }
  //cout << ans << ' ' << k << '\n';
  for (int p = 0; p < (1 << T); p++) {
    m = n - 1;
    for (int i = 1; i <= m; i++) e[i] = g[i];
    ll sum = 0;
    for (int x = 0; x < T; x++) {
      if (((p >> x) & 1) ^ 1) continue;
      k = 0, sum += cost[x];
      for (int i = 1, j = 1; i <= n && j <= m; ) {
        if (i <= n && (j > m || eg[x][i].w < e[j].w)) {
          t[++k] = eg[x][i], i++;
        } else t[++k] = e[j], j++;
      }
      m = k;
      for (int i = 1; i <= m; i++) e[i] = t[i];
    }
    ans = min(ans, Solve(0, sum));
    //if (Solve(0, sum) == 11) cout << m << ' ' << bitset<4>(p) << '\n';
  }
  cout << ans;
  return 0;
}
