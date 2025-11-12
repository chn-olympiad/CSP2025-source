#include <bits/stdc++.h>
using namespace std;
void File(){
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
}
using ll = long long;
const int kN = 2e4 + 7;
const int kM = 2e6 + 7;
struct DSU{
  int fa[kN];
  int find(int x){return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);}
  void merge(int x, int y){
    x = find(x), y = find(y);
    if(x ^ y){
      fa[x] = y;
    }
  }
}dsu;
struct node{
  int u, v;
  ll w;
  bool friend operator < (node a, node b){
    return a.w < b.w;
  }
}e[kM], ne[kM];
int n, m, k, vis[kM];
ll a[13][kN], c[13], ans;
signed main(){
  File();
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) dsu.fa[i] = i;
  for(int i = 1; i <= m; i++){
    cin >> e[i].u >> e[i].v >> e[i].w;
  } 
  for(int i = 1; i <= k; i++){
    cin >> c[i];
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
    }
  }
  sort(e + 1, e + m + 1);
  for(int i = 1; i <= m; i++){
    if(dsu.find(e[i].u) != dsu.find(e[i].v)){
      dsu.merge(e[i].u, e[i].v);
      ans += e[i].w;
      vis[i] = 1;
    }
  }
  int _ = m; m = 0;
  for(int i = 1; i <= _; i++) ne[i] = e[i];
  for(int i = 1; i <= _; i++){
    if(vis[i]) e[++m] = ne[i];
    vis[i] = 0;
  }
  _ = m;
  for(int s = 0; s < (1 << k); s++){
    ll sum = 0; m = _;
    for(int i = 1; i <= n + k; i++) dsu.fa[i] = i;
    for(int i = 1; i <= m; i++) ne[i] = e[i];
    int _n = n;
    for(int i = 0; i < k; i++){
      if((s >> i) & 1){
        sum += c[i + 1]; 
        _n++;
        for(int j = 1; j <= n; j++){
          ne[++m] = {_n, j, a[i + 1][j]};
        }
      }
    }
    stable_sort(ne + 1, ne + m + 1);
    for(int i = 1; i <= m; i++){
      if(dsu.find(ne[i].u) != dsu.find(ne[i].v)){
        sum += ne[i].w;
        dsu.merge(ne[i].u, ne[i].v);
      }
    }
    ans = min(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}