#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;

const int N = 1e4 + 3, K = 13;

const ll INF = 1e16 + 3;

struct Edge{
  int u, v;
  ll val;
  bool operator< (const Edge &w) const {
    return val > w.val;
  }
};

vector<Edge>a, b[K];

int fa[N + K];

ll c[K];

int n, m, k, kk = 0;

ll ans = INF;

int Fa(int u) { return (u == fa[u] ? u : fa[u] = Fa(fa[u])); }

ll Val(int kc, priority_queue<Edge> &q) {
  ll ansss = 0;
  for (int i = 1; kc; i++, kc >>= 1) {
    for (int j = 0; j < b[i].size() && (kc & 1); j++) {
      q.push(b[i][j]);
    }
    if (kc & 1) ansss += c[i];
  }
  for (int i = 0; i < a.size(); i++) {
    q.push(a[i]);
  }
  return ansss;
}

void bfs(int kc) {
  priority_queue<Edge> q;
  ll anss = Val(kc, q);
  while (q.size()) {
    Edge t = q.top();
    q.pop();
    if (Fa(t.u) != Fa(t.v)) anss += t.val, fa[Fa(t.u)] = Fa(t.v);
  }
  ans = min(ans, anss);
}

void Clear() {
  for (int i = 1; i <= n + k; i++) {
    fa[i] = i;
  }
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    a.push_back({u, v, w});
  }
  for (int i = 1, ab; i <= k; i++) {
    scanf("%d", &c[i]);
    for (int j = 1; j <= n; j++) {
      scanf("%d", &ab);
      b[i].push_back({n + i, j, ab});
    }
  }
  for (int i = 0; i < (1 << k); i++) {
    Clear(), bfs(i);
  }
  printf("%d", ans);
  return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
