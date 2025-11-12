#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e4 + 3, MAXK = 10, INF = 1e9 + 5;

int n, m, k, fa[MAXN + MAXK], c[MAXK];
ll ans;

int read(){
  char ch = getchar();
  int res = 0;
  for(; ch < '0' || ch > '9'; ch = getchar());
  for(; ch >= '0' && ch <= '9'; res = (res << 1) + (res << 3) + ch - '0', ch = getchar());
  return res;
}

struct Edge{
  int u, v, w;
  bool operator < (const Edge &i) const{
    return w < i.w;
  }
};
vector<Edge> e, edge;

int Find(int x){
  return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

ll Kruskal(int s, int state){
  ll ans = 0;
  for(int i = 1; i <= s; i++) fa[i] = i;
  for(const Edge &x : edge){
    if(x.u > n && !(state >> (x.u - n - 1) & 1)) continue;
    int fu = Find(x.u), fv = Find(x.v);
    if(fu != fv){
      ans += x.w;
      fa[fu] = fv;
      if(!state) e.push_back(x);
    }
  }
  return ans;
}

int main(){
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  n = read(), m = read(), k = read();
  for(int i = 1, u, v, w; i <= m; i++){
    u = read(), v = read(), w = read();
    edge.push_back({u, v, w});
  }
  sort(edge.begin(), edge.end());
  ans = Kruskal(n + k, 0);
  edge = e;
  for(int i = 0; i < k; i++){
    c[i] = read();
    for(int j = 1, x; j <= n; j++){
      x = read();
      edge.push_back({n + i + 1, j, x});
    }
  }
  sort(edge.begin(), edge.end());
  for(int i = 1; i < 1 << k; i++){
    ll sum = 0;
    for(int j = 0; j < k; j++){
      if(i >> j & 1) sum += c[j];
    }
    ans = min(ans, Kruskal(n + k, i) + sum);
  }
  cout << ans;
  return 0;
}
