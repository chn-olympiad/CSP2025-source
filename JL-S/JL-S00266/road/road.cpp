#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL
int n, m, k;
const int maxk = 11;
const int maxn = 1e4 + maxk + 10;   
const int maxm = 1e6 + maxk * maxn + 10; 
struct E {
  int u, v, w;
  inline bool operator < (const E& t) const { return w < t.w;}
} e[maxm], t[maxm];
int tot, c[maxn];
E a[maxk][maxn];
LL ans = 1e18; 
namespace dsu {
  int f[maxn];
  inline void init() {
    for(int i = 1; i <= n + k; ++ i) f[i] = i;
  }
  inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); } 
} using namespace dsu;
inline LL Kruskal(int sum, int sz) { 
  for(int i = 1; i <= tot; ++ i) t[i] = e[i];
  sort(t + 1, t + 1 + tot);
  init();
  LL res = 0; 
  int cnt = 0; 
  for(int i = 1; i <= tot; ++ i) {
    auto [u, v, w] = t[i];
    if(find(u) != find(v)) {
      res += w;
      if(sum + res > ans) return ans + 1;
      u = find(u), v = find(v);
      f[v] = u, sz -- ;
      if(sz == 1) return sum + res;
    }
  } 
}
inline void dfs(int u, int sum, int cnt) {
  if(sum > ans) return ;
  if(u == k + 1) {
    ans = min(ans, Kruskal(sum, cnt)); 
    return ; 
  }
  dfs(u + 1, sum, cnt);
  for(int i = 1; i <= n; ++ i) e[++ tot] = a[u][i];
  dfs(u + 1, sum + c[u], cnt + 1); 
  tot -= n;
}
inline bool check() {
  return *max_element(c + 1, c + 1 + k) == 0;
}
inline void solve2() {
  for(int i = 1; i <= k; ++ i)
    for(int j = 1; j <= n; ++ j) e[++ tot] = a[i][j];
  ans = min(ans, Kruskal(0, n + k)); 
}
signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  tot = m;
  for(int i = 1; i <= m; ++ i) cin >> e[i].u >> e[i].v >> e[i].w;
  for(int i = 1; i <= k; ++ i) {
    cin >> c[i];
    for(int j = 1; j <= n; ++ j) {
      int w; cin >> w;
      a[i][j] = (E){n + i, j, w}; 
    } 
  }
  if(check()) solve2();
  else dfs(1, 0, n);
  cout << ans << '\n'; 
  return 0; 
}