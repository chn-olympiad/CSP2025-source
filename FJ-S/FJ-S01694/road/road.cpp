#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

constexpr int N = 1e4 + 10, K = 12;
int c[N], a[K][N];

int read() {
  int r = 0;
  char c = getchar();
  
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) r = r * 10 + c - '0', c = getchar();
  
  return r;
}

struct edge {
  int u, v, w;
  
  bool operator<(const edge &d) const {
    return w > d.w;
  }
};
priority_queue<edge> e, f;

struct UnionFind {
  int anc[N + K];
  
  void init(int n) {
    iota(anc + 1, anc + n + 1, 1);
  }
  
  int find(int p) {
    return anc[p] == p ? p : anc[p] = find(anc[p]);
  }
  
  void merge(int u, int v) {
    anc[find(u)] = find(v);
  }
} D;

i64 Kruskal(int n) {
  D.init(n);
  int cnt = 0;
  i64 res = 0;
  while (f.size()) {
    edge g = f.top();
    f.pop();
    
    if (D.find(g.u) == D.find(g.v)) continue;
    
    D.merge(g.u, g.v);
    res += g.w;
    if (++cnt == n - 1) break;
  }
  
  return res;
}

signed main() {  
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
   
  int n = read(), m = read(), k = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), w = read();
    e.push({u, v, w});
  }
  
  for (int i = 1; i <= k; i++) {
    c[i] = read();
    for (int j = 1; j <= n; j++) a[i][j] = read();
  }
  
  if (accumulate(c + 1, c + k + 1, 0) == 0) {
    for (int i = 1; i <= k; i++) {
      int pos;
      for (int j = 1; j <= n; j++)
        if (a[i][j] == 0) {
          pos = j;
          break;
        }
      
      for (int j = 1; j <= n; j++)
        if (pos != j) e.push({pos, j, a[i][j]});
    }
    
    f = e;
    cout << Kruskal(n);
    
    return 0;
  }
  
  i64 v = 1e18;
  for (int S = 0; S < 1 << k; S++) {
    f = e;
    
    int n2 = n;
    i64 res = 0;
    for (int i = 1; i <= k; i++)
      if (S & 1 << (i - 1)) {
        res += c[i], n2++;
        for (int j = 1; j <= n; j++) {
          f.push({n2, j, a[i][j]});
        }
      }
    
    v = min(v, res + Kruskal(n2));
  }
  
  cout << v;
}
