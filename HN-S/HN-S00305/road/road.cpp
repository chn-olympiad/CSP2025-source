#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4, MAXM = 4e6 + 10, MAXK = 20;

int n, m, k, a[MAXK][MAXN], fa[MAXN], cnt, c[MAXK];
bool f, v[MAXN], f1 = 1;
long long ans;

struct E{
  int u, v, w;
  bool c;
  bool operator< (const E &i) const{
    return w < i.w;
  }
} g1[MAXM];
priority_queue<E> g[MAXM];

int Find(int x){
  return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void Solve1(){
  for(int i = 1; i <= n; i++) fa[i] = i;
  sort(g1 + 1, g1 + m + 1);
  for(int i = 1; i <= m; i++){
    int u = g1[i].u, v = g1[i].v, w = g1[i].w;
    u = Find(u), v = Find(v);
    if(u != v){
      fa[u] = v, ans += w;
    }
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k;

  for(int i = 1, u, v, w; i <= m; i++){
    cin >> u >> v >> w;
    g1[i] = {u, v, w};
  }

  int _n = n;

  for(int i = 1; i <= k; i++){
    cin >> c[i];
    n++, f1 &= (c[i] == 0);
    for(int j = 1, x; j <= _n; j++){
      cin >> a[i][j];
      g1[++m] = {n, j, a[i][j]};
    }
  }

  if(f1){
    Solve1();
    return 0;
  }
  return 0;
}

