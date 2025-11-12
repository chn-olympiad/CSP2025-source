#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e4 + 1, MAXK = 15, MAXM = 2e6 + 1;

struct edge{
  int u, v, w;
  inline bool operator<(const edge &i) const{
    return w < i.w;
  }
}g[MAXM], g2[MAXM];

int n, m, k, cnt, tot, fa[MAXN + MAXK], sz[MAXN + MAXK], c[MAXK], a[MAXK][MAXN];
ll ans;
bool flag = 1;

inline int Find(int x){
  return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

inline void Merge(int x, int y){
  if(sz[x] > sz[y]){
    swap(x, y);
  }
  fa[x] = y, sz[y] += sz[x], cnt--;
}

inline void Solve(int s){
  ll sum = 0;
  cnt = n + k, tot = m;
  for(int i = 1; i <= m; i++){
    g[i] = g2[i];
  }
  for(int i = 1; i <= k; i++){
    if((s >> (i - 1)) & 1){
      sum += c[i];
      if(sum >= ans){
        return;
      }
      for(int j = 1; j <= n; j++){
        g[++tot] = {i + n, j, a[i][j]};
      }
    }
  }
  sort(g + 1, g + 1 + tot);
  for(int i = 1; i <= n + k; i++){
    fa[i] = i, sz[i] = 1;
  }
  for(int i = 1; i <= tot && cnt != 1; i++){
    int u = Find(g[i].u), v = Find(g[i].v);
    if(u == v){
      continue;
    }
    Merge(u, v);
    sum += g[i].w;
    if(sum >= ans){
      return;
    }
  }
  ans = sum;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k;
  ans = LLONG_MAX;
  for(int i = 1; i <= m; i++){
    cin >> g[i].u >> g[i].v >> g[i].w;
  }
  for(int i = 1; i <= m; i++){
    g2[i] = g[i];
  }
  for(int i = 1; i <= k; i++){
    cin >> c[i];
    flag &= (!c[i]);
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
    }
  }
  if(flag){
    Solve((1 << k) - 1);
    cout << ans;
    return 0;
  }
  for(int i = 0; i < (1 << k); i++){
    Solve(i);
  }
  cout << ans;
  return 0;
}
