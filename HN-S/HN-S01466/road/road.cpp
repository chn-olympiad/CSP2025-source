#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int MAXN = 2e6 + 3;

struct Edge{
  int u, v, w;
}eg[MAXN];

int n, m, k, c[MAXN], fa[MAXN];

int Getf(int x){ return fa[x] == x ? x : fa[x] = Getf(fa[x]); }

// g++ run.cpp -o run -std=c++14 -O2 -g -Wall -Wextra -fsanitize=address,undefined && time ./run < road1.in
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++){
    cin >> eg[i].u >> eg[i].v >> eg[i].w;
  }
  for(int i = 1; i <= n; i++) fa[i] = i;
  sort(eg + 1, eg + 1 + m, [](Edge i, Edge j){ return i.w < j.w; });
  int _m = 0;
  for(int i = 1; i <= m; i++){
    int fx = Getf(eg[i].u), fy = Getf(eg[i].v);
    if(fx != fy) fa[fx] = fy, eg[++_m] = eg[i];
  }
  m = _m;
  for(int i = 1; i <= k; i++){
    cin >> c[i];
    for(int j = 1, w; j <= n; j++) cin >> w, eg[++m] = {j, n + i, w};
  }
  sort(eg + 1, eg + 1 + m, [](Edge i, Edge j){ return i.w < j.w; });
  LL ANS = 1e18;
  for(int s = 0; s < (1 << k); s++){
    LL ans = 0;
    for(int i = 1; i <= n + k; i++) fa[i] = i;
    for(int i = 1; i <= m; i++){
      if(eg[i].v > n && (s >> (eg[i].v-n-1)) % 2 == 0){
        continue;
      }
      int fx = Getf(eg[i].u), fy = Getf(eg[i].v);
      if(fx != fy) ans += eg[i].w, fa[fx] = fy;
    }
    for(int i = 0; i < k; i++) if((s >> i) & 1) ans += c[i + 1];
    ANS = min(ANS, ans);
  }
  cout << ANS;
  return 0;
}