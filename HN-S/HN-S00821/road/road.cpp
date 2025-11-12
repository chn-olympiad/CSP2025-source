#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e4 + 100, M = 1e6 + 5, K = 15;

struct E {
  int u, v, w;
} e[M], a[N], v[N * 2];

int n, m, k, fa[N], cnt, b[K][N], g[N], w[N], su, sc[K][K];
ll h, rs = 1e18;

int F(int x) {
  return fa[x] == x ? x : fa[x] = F(fa[x]);
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(0)->ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  stable_sort(e + 1, e + m + 1, [](E x, E y) { return x.w < y.w; });
  iota(fa, fa + n + 1, 0);
  for (int i = 1; i <= m; i++) {
    if (F(e[i].u) != F(e[i].v)) {
      fa[F(e[i].u)] = F(e[i].v);
      a[++cnt] = e[i];
      h += e[i].w;
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j <= n; j++) {
      cin >> b[i][j];
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      sc[i][j] = 1e9;
    }
  }
  for (int i = 1; i < (1 << k); i++) {
    ll d = 0;
    fill(g, g + n + 1, 1e9);
    iota(fa, fa + n + k + 1, 0);
    for (int j = 0; j < k; j++) {
      if (i >> j & 1) {
        d += b[j][0];
        for (int o = 1; o <= n; o++) {
          if (g[o] > b[j][o]) {
            g[o] = b[j][o];
            w[o] = j;
          }
        }
      }
    }
    for (int j = 1; j <= n; j++) {
      v[j] = {n + w[j] + 1, j, g[j]};
    }
    for (int j = 1; j < n; j++) {
      v[n + j] = a[j];
    }
    su = 2 * n;
    for (int j = 0; j < k; j++) {
      if (i >> j & 1) {
        for (int o = 1; o <= n; o++) {
          sc[j][w[o]] = min(sc[j][w[o]], b[j][o]);
        }
        for (int o = 0; o < k; o++) {
          if (i >> o & 1) {
            v[su++] = {n + j + 1, n + o + 1, sc[j][o]};
            sc[j][o] = 1e9;
          }
        }
      }
    }
    stable_sort(v + 1, v + su, [](E x, E y) { return x.w < y.w; });
    for (int j = 1; j < su; j++) {
      if (F(v[j].u) != F(v[j].v)) {
        fa[F(v[j].u)] = F(v[j].v);
        d += v[j].w;
      }
    }
    rs = min(rs, d);
  }
  cout << min(rs, h);
  return 0;
}
/*
g++ road.cpp -o road -std=c++14 -O2 && ./road
 */