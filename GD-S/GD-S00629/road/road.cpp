#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k, tot, cnt, sum, ans = 1e18, fa[10010], a[11][10010], c[11];
int find (int x) {
  return fa[x] == x ? x : fa[x] = find (fa[x]);
}
struct edge {
  int u, v, w;
} e[1000010], g[1000010];
bool cmp (edge a, edge b) {
  return a.w < b.w;
}
signed main() {
  freopen ("road.in", "r", stdin);
  freopen ("road.out", "w", stdout);
  scanf ("%lld%lld%lld", &n, &m, &k);
  for (int i = 1; i <= m; i++)
    scanf ("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
  for (int i = 1; i <= k; i++) {
    scanf ("%lld", &c[i]);
    for (int j = 1; j <= n; j++)
      scanf ("%lld", &a[i][j]);
  }
  sort (e + 1, e + m + 1, cmp);
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  tot = n;
  for (int i = 1; i <= m; i++)
    if (find (e[i].u) != find (e[i].v)) {
      fa[find (e[i].v)] = e[i].u;
      g[++cnt] = e[i];
      tot--;
      if (tot == 1)
        break;
    }
  for (int i = 0; i < (1 << k); i++) {
    sum = cnt = 0;
    tot = n;
    for (int j = 1; j < n; j++)
      e[++cnt] = g[j];
    for (int j = 1; j <= k; j++)
      if (i & (1 << j - 1)) {
        tot++;
        sum += c[j];
        for (int v = 1; v <= n; v++)
          e[++cnt] = {tot, v, a[j][v]};
      }
    sort (e + 1, e + cnt + 1, cmp);
    for (int j = 1; j <= tot; j++)
      fa[j] = j;
    for (int j = 1; j <= cnt; j++)
      if (find (e[j].u) != find (e[j].v)) {
        fa[find (e[j].v)] = e[j].u;
        sum += e[j].w;
        tot--;
        if (tot == 1)
          break;
      }
    ans = min (ans, sum);
  }
  printf ("%lld\n", ans);
  return 0;
}


