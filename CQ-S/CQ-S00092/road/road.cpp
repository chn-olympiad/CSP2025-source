#include <bits/stdc++.h>

using ll = long long;

constexpr int N = 1e4 + 20;
constexpr int M = 1e6 + 10;
constexpr int K = 10;

struct edge {
  int u, v, w;
  inline bool operator < (const edge &o) const {
    return w < o.w;
  }
};
edge e[M];

int co[K], wei[K][N];

namespace dsu {
  int fa[N];
  inline void init() {
    std::iota(fa + 1, fa + N, 1);
  }
  inline int find(int x) {
    while (fa[x] != x) {
      x = fa[x] = fa[fa[x]];
    }
    return x;
  }
  inline bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
      fa[x] = y;
      return true;
    }
    return false;
  }
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);

  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
  }
  std::sort(e + 1, e + m + 1);
  dsu::init();
  for (int i = 1, j = 0; i <= m && j < n - 1; i++) {
    if (dsu::merge(e[i].u, e[i].v)) {
      e[++j] = e[i];
    }
  }
  m = n - 1;
  for (int i = 0; i < k; i++) {
    scanf("%d", &co[i]);
    for (int j = 1; j <= n; j++) {
      m++, e[m].u = n + i + 1, e[m].v = j;
      scanf("%d", &e[m].w);
    }
  }
  std::sort(e + 1, e + m + 1);
  ll ans = (ll)1e18;
  for (int s = 0; s < (1 << k); s++) {
    dsu::init();
    ll res = 0;
    for (int i = 1; i <= m; i++) {
      if (e[i].u <= n || (e[i].u > n && (s >> (e[i].u - n - 1) & 1))) {
        if (dsu::merge(e[i].u, e[i].v)) {
          res += e[i].w;
        }
      }
    }
    for (int i = 0; i < k; i++) {
      if (s >> i & 1) {
        res += co[i];
      }
    }
    ans = std::min(ans, res);
  }
  printf("%lld\n", ans);

  return 0;
}