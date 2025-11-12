#include <bits/stdc++.h>
#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
using namespace std;
using LL = long long;
using Pii = pair<int, int>;

ifstream fin("road.in");
ofstream fout("road.out");

const int kMaxM = 2e6 + 5, kMaxN = 1e4 + 5, kMaxK = 15; 

struct E {
  int u, v, w;
} e[kMaxM];

int n, m, k, cnt, c[kMaxK], fa[kMaxN], a[kMaxK][kMaxN];
LL ans;
vector<E> edge;

int Find(int x) {
  return (fa[x] == x ? x : fa[x] = Find(fa[x]));
} 

void Union(int x, int y) {
  x = Find(x), y = Find(y);
  if(x != y) {
    fa[x] = y;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  fin >> n >> m >> k;
  for(int i = 1; i <= m; i++) {
    fin >> e[i].u >> e[i].v >> e[i].w;
  }
  sort(e + 1, e + m + 1, [](E x, E y) {
    return x.w < y.w;
  });
  iota(fa + 1, fa + n + 1, 1);
  for(int i = 1; i <= m; i++) {
    if(Find(e[i].u) != Find(e[i].v)) {
      Union(e[i].u, e[i].v);
      ans += e[i].w;
      edge.emplace_back(e[i]);
    }
  }
  for(int i = 0; i < k; i++) {
    fin >> c[i];
    for(int j = 1; j <= n; j++) {
      fin >> a[i][j];
    }
  }
  for(int i = 0; i < (1 << k); i++) {
    int pos = 0;
    for(auto j : edge) {
      e[++pos] = j;
    }
    LL sum = 0;
    for(int j = 0; j < k; j++) {
      if(i & (1 << j)) {
        for(int p = 1; p <= n; p++) {
          e[++pos] = (E){n + 1 + j, p, a[j][p]};
        }
        sum += c[j];
      }
    }
    sort(e + 1, e + pos + 1, [](E x, E y) {
      return x.w < y.w;
    });
    iota(fa + 1, fa + n + k + 2, 1);
    for(int j = 1; j <= pos; j++) {
      if(Find(e[j].u) != Find(e[j].v)) {
        Union(e[j].u, e[j].v);
        sum += e[j].w;
      }
    }
    ans = min(ans, sum);
  }
  fout << ans << endl;
  return 0;
}

