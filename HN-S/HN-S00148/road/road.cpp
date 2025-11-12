#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;

const int kN = 2e4 + 7, kM = 2e6 + 7;

struct E {
  int u, v;
  LL w;
  friend bool operator < (E x, E y) {
    return x.w < y.w;
  }
} e[kM], e2[kM];

int n, m, k, fa[kN], siz[kN], c[12], a[kN][12], tot, tot2;
LL ans;

int findfa(int x) {
  return ((fa[x] == x) ? x : (fa[x] = findfa(fa[x])));
}

void uni(int u, int v) {
  u = findfa(u), v = findfa(v);
  if (u == v) return;
  if (siz[u] < siz[v]) swap(u, v);
  fa[v] = u, siz[u] += siz[v];
}

LL Kruskal() {
  LL res = 0;
  for (int i = 1; i <= n + k; i++) {
    fa[i] = i, siz[i] = 1;
  }
  for (int i = 1; i <= tot2; i++) {
    e2[i] = e[i];
  }
  sort(e2 + 1, e2 + tot2 + 1);
  for (int i = 1; i <= tot2; i++) {
    if (findfa(e2[i].u) == findfa(e2[i].v)) continue;
    res += e2[i].w, uni(e2[i].u, e2[i].v);
  }
  return res;
}

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> k, ans = 9e18;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    e[++tot] = {u, v, w};
  }
  bool chk = 1;
  for (int i = 1; i <= k; i++) {
    cin >> c[i];
    chk &= (c[i] == 0); 
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  if (chk) {
    tot2 = tot;
    for (int j = 1; j <= k; j++) {
      for (int l = 1; l <= n; l++) {
        if (a[j][l] == 0) {
          for (int p = 1; p <= n; p++) {
            e[++tot2] = {l, p, a[j][p]};
          }
        }
      }
    } 
    cout << Kruskal() << '\n';
    return 0;
  }
  LL sum = 0;
  for (int i = 0; i < (1 << k); i++) {
    sum = 0, tot2 = tot;
    for (int j = 1; j <= k; j++) {
      if ((i >> (j - 1)) & 1) {
        sum += c[j];
        for (int l = 1; l <= n; l++) {
          e[++tot2] = {n + j, l, a[j][l]};
        }
      }
    }
    ans = min(ans, sum + Kruskal());
  }
  cout << ans;

  return 0;
}
