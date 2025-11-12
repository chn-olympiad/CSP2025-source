#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 105;
const int K = 12, S = 1025;
bool in(int i, int s) {
  return (s >> i) & 1;
}
struct edge {
  int u, v, w;
};
vector<edge> e, E;
vector<edge> ek[K], es[S];
bool wup(edge x, edge y) {
  return x.w < y.w;
}
int fa[N];
int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int c[K], a[K][N];
signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios :: sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    e.push_back({u, v, w});
  }
  sort(e.begin(), e.end(), wup);
  for (int i = 1; i <= k; ++i) {
    cin >> c[i];
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      ek[i].push_back({n + i, j, x});
    }
    sort(ek[i].begin(), ek[i].end(), wup);
  }
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  int cnt = 0;
  ll res, ans = 0;
  for (edge p : e) {
    int u = p.u, v = p.v, w = p.w;
    int x = find(u), y = find(v);
    if (x != y) {
      fa[x] = y;
      E.push_back(p);
      ans += w;
      if (++cnt == n - 1) break;
    }
  }
  res = ans;
  int lene = E.size();
  for (int s = 1; s < (1 << k); ++s) {
    int l = 0;
    for (; l < k; ++l) {
      if (in(l, s)) break;
    }
    ++l;
    int tot = n + __builtin_popcount(s);
    int p = 0, q = 0, t = s - (1 << l - 1);
    int lent = es[t].size(), lenl = ek[l].size();
    vector<edge> vt;
    while (p < lent && q < lenl) {
      if (es[t][p].w < ek[l][q].w) vt.push_back(es[t][p++]);
      else vt.push_back(ek[l][q++]);
    }
    while (p < lent) vt.push_back(es[t][p++]);
    while (q < lenl) vt.push_back(ek[l][q++]);
    p = 0, q = 0;
    int lenv = vt.size();
    while (p < lenv && q < lene) {
      if (vt[p].w < E[q].w) es[s].push_back(vt[p++]);
      else es[s].push_back(E[q++]);
    }
    while (p < lenv) es[s].push_back(vt[p++]);
    while (q < lene) es[s].push_back(E[q++]);
    for (int i = 1; i <= n + k; ++i) fa[i] = i;
    cnt = ans = 0;
    for (int i = 0; i < k; ++i) {
      if (in(i, s)) ans += c[i + 1];
    }
    for (edge z : es[s]) {
      int u = z.u, v = z.v, w = z.w;
      int x = find(u), y = find(v);
      if (x != y) {
        fa[x] = y;
        ans += w;
        if (++cnt == tot - 1) break;
      }
    }
    res = min(res, ans);
  }
  cout << res << '\n';
  return 0;
}