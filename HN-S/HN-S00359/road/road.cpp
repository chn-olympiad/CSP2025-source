#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 20005, MAXM = 2000005;

struct Edge {
  int u, v, w;
}g[MAXM], g2[MAXM];

int n, m, k, f[MAXN], sz[MAXN], c[MAXN], a[20][MAXN], tot, tot2;
ll ans, res;

int getfa(int u) {
  return (f[u] == u ? u : f[u] = getfa(f[u]));
}

void Merge(int u, int v) {
  u = getfa(u), v = getfa(v);
  if(u != v) {
    if(sz[u] > sz[v]) {
      swap(u, v);
    }
    f[u] = v, sz[v] += sz[u];
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k;
  iota(f + 1, f + n + 1, 1);
  fill(sz + 1, sz + n + 1, 1);
  for(int i = 1; i <= m; ++i) {
    cin >> g[i].u >> g[i].v >> g[i].w;
  }
  for(int i = 1; i <= k; ++i) {
    cin >> c[i];
    for(int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  sort(g + 1, g + m + 1, [](const Edge &a, const Edge &b) {
    return a.w < b.w;
  });
  for(int i = 1; i <= m; ++i) {
    int u = getfa(g[i].u), v = getfa(g[i].v), w = g[i].w;
    if(u != v) {
      ans += w;
      Merge(u, v);
      g[++tot] = g[i];
    }
  }
  for(int i = 1; i < (1 << k); ++i) {
    ll res = 0;
    for(int j = 1; j <= tot; ++j) {
      g2[j] = g[j];
    }
    tot2 = tot;
    for(int j = 1; j <= k; ++j) {
      if((i >> (j - 1)) & 1) {
        res += c[j];
        for(int x = 1; x <= n; ++x) {
          g2[++tot2] = {n + j, x, a[j][x]};
        }
      }
    }
    iota(f + 1, f + n + k + 1, 1);
    fill(sz + 1, sz + n + k + 1, 1);
    sort(g2 + 1, g2 + tot2 + 1, [](const Edge &a, const Edge &b) {
      return a.w < b.w;
    });
    for(int j = 1; j <= tot2; ++j) {
      int u = getfa(g2[j].u), v = getfa(g2[j].v), w = g2[j].w;
      if(u != v) {
        Merge(u, v);
        res += w;
      }
    }
    ans = min(ans, res);
  }
  cout << ans;
  return 0;
}
