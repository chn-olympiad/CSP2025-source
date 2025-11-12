#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5, maxm = 1e6 + 5;

struct node{
  int u, v, w, f;
  bool operator<(const node i) const{
    return w < i.w;
  }
} a[maxm], p[maxm];

int n, m, k, f1 = 1, fa[maxn];
long long ans, c[15], b[15][maxn], g[maxn];
bool d[15];

int Find(int x){
  return (fa[x] == x ? fa[x] : fa[x] = Find(fa[x]));
}

long long S(){
  long long tot = 0;
  sort(a + 1, a + m + 1);
  for(int i = 1; i <= n + k; i++){
    fa[i] = i;
  }
  for(int i = 1; i <= k; i++){
    g[i + n] = c[i];
  }
  for(int i = 1; i <= m; i++){
    int fu = Find(a[i].u), fv = Find(a[i].v);
//    cout << a[i].f << ' ' << g[a[i].f] << '\n';
    if(fu != fv){
      fa[fu] = fv;
      tot += a[i].w + g[a[i].f];
      if(g[a[i].f]) g[a[i].f] = 0;
    }
  }
  return tot;
}

void F(int x){
  if(x > k){
    int y = m;
    for(int i = 1; i <= k; i++){
      if(d[i]){
        for(int j = 1; j <= n; j++){
          a[++m] = {i + n, j, b[i][j], i + n};
        }
      }
    }
//    for(int i = 1; i <= m; i++){
//      cout << a[i].u << ' ' << a[i].v << ' ' << a[i].w << '\n';
//    }
//  cout << '\n';
    long long h = S();
    ans = min(ans, h);
    m = y;
    for(int i = 1; i <= m; i++){
      a[i] = p[i];
    }
    return;
  }
  d[x] = 1, F(x + 1), d[x] = 0, F(x + 1);
}

int main(){
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++){
    cin >> a[i].u >> a[i].v >> a[i].w;
    a[i].f = 0;
    p[i] = a[i];
  }
  for(int i = 1; i <= n; i++){
    fa[i] = i;
  }
  for(int i = 1; i <= k; i++){
    cin >> c[i];
    g[i + n] = c[i];
    for(int j = 1; j <= n; j++){
      cin >> b[i][j];
    }
  }
  if(k <= 0){
    cout << S();
    return 0;
  }
  ans = S();
  F(1);
  cout << ans;
  return 0;
}
