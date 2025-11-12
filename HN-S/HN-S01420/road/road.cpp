#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int kM = 2e4 + 5, kN = 2e6 + 5;
int n, m, k, f[kM], c[100], sz[kM], a[15][kM], tot;
ll ans, cnt;
struct E{
  int u, v, o;
  ll w;
}e[kN];
int find(int x){
  return f[x] == x ? x : f[x] = find(f[x]);
}
bool cmp(E a, E b){
  if(a.o == b.o) return a.w < b.w;
  return a.o > b.o;
}
bool cmp2(E a, E b){
  return a.w < b.w;
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++){
    cin >> e[i].u >> e[i].v >> e[i].w;
    e[i].o = 0;
  }
  for(int i = 1; i <= n; f[i] = i, i++);
  sort(e + 1, e + 1 + m, cmp);
  for(int i = 1; i <= m; i++){
    ll u = e[i].u, v = e[i].v;
    if(find(u) == find(v)) continue;
    f[find(u)] = f[find(v)];
    ans += e[i].w, e[i].o = 1;
  }
  sort(e + 1, e + 1 + m, cmp);
  m = n - 1;
  for(int i = 1; i <= k; i++){
    cin >> c[i];
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 1; i < (1 << k); i++){
    tot = m, cnt = 0;
    for(int i = 1; i <= n + k; f[i] = i, sz[i] = 1, i++);
    for(int j = 1; j <= k; j++){
      if((i >> (j - 1)) & 1){
        cnt += c[j];
        for(int p = 1; p <= n; p++){
          e[++tot].u = n + j, e[tot].v = p, e[tot].o = 0, e[tot].w = a[j][p];
        }
      }
    }
    stable_sort(e + 1, e + 1 + tot, cmp2);
    for(int j = 1; j <= tot; j++){
      ll u = find(e[j].u), v = find(e[j].v);
      if(u == v) continue;
      if(sz[u] > sz[v]) swap(u, v);
      f[u] = f[v], sz[v] += sz[u];
      cnt += e[j].w;
    }
    ans = min(ans, cnt);
    ll tt = 0;
    for(ll i = 1; i <= tot;i++){
      if(e[i].o == 1) swap(e[i], e[++tt]);
    }
  }
  cout << ans;
  return 0;
}