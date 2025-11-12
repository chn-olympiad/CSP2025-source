#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

void file () {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
}

const int kN = 1e4 + 30;
const int kM = 1e6 + 5;
const int K = 10;
const int kC = kN * (K + 1);
const ll infl = 1e18;

int n, m, k, len;
int fa[kN]; 
int c[K];

int find (int x) { 
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}

struct edge {
  int u, v, w; 
} e[kM], e2[kM]; 

void fakemain () { 
  cin >> n >> m >> k;
  {
    for (int i = 1; i <= m; ++i) {
      cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1, e + m + 1, [&](edge a, edge b) -> bool {
      return a.w < b.w;
    });
    for (int i = 1; i <= n; ++i) {
      fa[i] = i;
    }
    int tot = 0;
    for (int i = 1; i <= m; ++i) {
      int u = find(e[i].u), v = find(e[i].v);
      if (u != v) {
        fa[v] = u;
        e2[++tot] = e[i];
      } 
    }
  }
  m = n - 1;
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      e2[++m] = edge({j, i + n + 1, x});
    }
  }
  sort(e2 + 1, e2 + m + 1, [&](edge a, edge b) -> bool {
    return a.w < b.w;
  });
  ll ans = infl;
  for (int s = 0; s < (1 << k); ++s) {
    ll sum = 0; 
    for (int i = 0; i < k; ++i) {
      if ((s >> i) & 1) {
        sum += c[i];
      }
    }
    for (int i = 1; i <= n + k; ++i) {
      fa[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
      int u = e2[i].u, v = e2[i].v, w = e2[i].w;
      if (u > n && !((s >> (u - n - 1)) & 1)) continue;
      if (v > n && !((s >> (v - n - 1)) & 1)) continue;
      u = find(u), v = find(v);
      if (u != v) {
        sum += w;
        fa[v] = u;
      }
    }
    ans = min(ans, sum);
  }
  cout << ans << '\n';
}

int main () {
  file();
  cin.tie(0)->sync_with_stdio(0);
  fakemain();
  return 0;
}