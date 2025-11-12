#include<bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 1e4 + 15;

struct Edge{
  int u, v, w;
};

int fa[N], sz[N], n, m, k, x, c[N], u, v, w;
LL ans;
vector<Edge>e, ex[20], cyx;

int Find(int x){
  int y = x;
  for(; fa[y] != y; y = fa[y]){
  }
  for(int last; fa[x] != x; last = x, x = fa[x], fa[last] = y){
  }
  return y;
}

void MMr(int u, int v){
  if(sz[u] > sz[v])swap(u, v);
  fa[u] = v;
  sz[v] += sz[u];
}

vector<Edge> Mr(vector<Edge> a, vector<Edge> b){
  vector<Edge>c;
  for(int i = 0, j = 0; i < a.size() || j < b.size(); ){
    if(j == b.size() || i < a.size() && a[i].w < b[j].w){
      c.push_back(a[i]);
      i++;
    }
    else{
      c.push_back(b[j]);
      j++;
    }
  }
  return c;
}

void dfs(int p, int x, vector<Edge> e, LL now){
  if(p == k){
    for(int i = 1; i <= n + k; ++i){
      fa[i] = i, sz[i] = 1;
    }
    //cout << x << '\n';
    for(auto [u, v, w] : e){
      if(Find(u) == Find(v))continue;
      MMr(Find(u), Find(v));
      now += w;
    }
    ans = min(ans, now);
    return ;
  }
  //cout << p << ' ' << x << ' ' << (1 << p) << '\n';
  dfs(p + 1, x, e, now);
  dfs(p + 1, (x | (1 << p)), Mr(e, ex[p]), now + c[p]);
}

int main(){
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= m; ++i){
    cin >> u >> v >> w;
    cyx.push_back({u, v, w});
  }
  sort(cyx.begin(), cyx.end(), [](const Edge &i, const Edge &j){  return i.w < j.w; });
  for(int i = 1; i <= n; ++i){
    fa[i] = i, sz[i] = 1;
  }
  for(auto [u, v, w] : cyx){
    if(Find(u) == Find(v))continue;
    MMr(Find(u), Find(v));
    e.push_back({u, v, w});
  }
  for(int i = 0; i < k; ++i){
    cin >> c[i];
    for(int j = 1; j <= n; ++j){
      cin >> x;
      ex[i].push_back({i + n + 1, j, x});
    }
    sort(ex[i].begin(), ex[i].end(), [](const Edge &i, const Edge &j){  return i.w < j.w; });
  }
  ans = 1e18;
  dfs(0, 0, e, 0);
  cout << ans;
  return 0;
}
