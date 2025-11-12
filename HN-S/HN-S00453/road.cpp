#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int kN = 1e4 + 25, kM = 2e6 + 5, kL = 12, kS = (1 << 10) + 5;
int n, m, k, e;
ll cost[kL], res[kS];

struct Edge {
  int u, v, w;
  Edge() { }
  Edge(int _u, int _v, int _w) {
    u = _u;
    v = _v;
    w = _w;
  }
} edge[kM];

struct DSU {
  int fa[kN], siz[kN];
  void Init() {
    iota(fa + 1, fa + n + k + 3, 1);
    fill(siz + 1, siz + n + k + 3, 1);
  }
  int Find(int x) {
    return (fa[x] == x) ? x : (fa[x] = Find(fa[x]));
  }
  bool Merge(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x == y) return 0;
    if(siz[x] < siz[y]) swap(x, y);
    fa[y] = x;
    siz[x] += siz[y];
    return 1;
  }
} dsu[kS];

void Link(int d, int s, int u, int v, int w) {
  if(!dsu[s].Merge(u, v)) return ;
  res[s] += w;
  for(int i = d; i < k; i++) {
    if(!((s >> i) & 1)) {
      Link(i + 1, s | (1 << i), u, v, w);
    }
  }
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge[++e] = Edge(u, v, w);
  }
  for(int i = 0; i < k; i++) {
    cin >> cost[i];
    for(int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      edge[++e] = Edge(n + i + 1, j, x);
    }
  }
  sort(edge + 1, edge + e + 1,
    [&](Edge x, Edge y) { return x.w < y.w; });
  for(int i = 0; i < (1 << k); i++) {
    dsu[i].Init();
    for(int j = 0; j < k; j++) {
      res[i] += ((i >> j) & 1) * cost[j];
    }
  }
  for(int i = 1; i <= e; i++) {
    int u = edge[i].u;
    int v = edge[i].v;
    int w = edge[i].w;
    if(u <= n) {
      Link(0, 0, u, v, w);
    }else {
      Link(0, 1 << (u - n - 1), u, v, w);
    }
  }
  cout << *min_element(res, res + (1 << k)) << "\n";
  return 0;
}