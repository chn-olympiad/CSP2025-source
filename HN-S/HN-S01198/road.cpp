#include<bits/stdc++.h>
#define int long long

using namespace std;
const int MAXN = 1e4 + 50;
int n, m, k, fa[MAXN], ANS = 4e18;
struct Node{
  int u, v, w;
  bool operator<(const Node &i)const{
    return w < i.w;
  }
};
struct bNode{
  int c, w[MAXN];
}ctst[15];
vector<Node> Graph;
vector<int> g[MAXN];
int find(int x){
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void Solve_k_is_zero(){
  for (int i = 1; i <= n; i++){
    fa[i] = i;
  }
  sort(Graph.begin(), Graph.end());
  int ans = 0;
  for (auto v : Graph){
    if (find(v.u) != find(v.v)){
      ans += v.w;
      fa[find(v.u)] = find(v.v);
    }
  }
  cout << ans << '\n';
  exit(0);
}
int Solve_k_is_zero(int cnt, vector<Node> g){
  for (int i = 1; i <= n + cnt; i++){
    fa[i] = i;
  }
  auto T = Graph;
  for (auto v : g){
    T.push_back(v);
  }
  sort(T.begin(), T.end());
  int ans = 0;
  for (auto v : T){
    if (find(v.u) != find(v.v)){
      ans += v.w;
      fa[find(v.u)] = find(v.v);
    }
  }
  return ans;
}  

void dfs(int x, int cnt, int awa, vector<Node> g){
  if (x == k + 1){
//    cerr << awa << ' ' << Solve_k_is_zero(cnt, g) << '\n';
//    for (auto v : Graph){
//      cerr << v.u << ' ' << v.v << ' ' << v.w << '\n';
//    }
//    cerr << '\n';
    ANS = min(ANS, Solve_k_is_zero(cnt, g) + awa);
    return ;
  }
  dfs(x + 1, cnt, awa, g);
  for (int i = 1; i <= n; i++){
    g.push_back({n + cnt + 1, i, ctst[x].w[i]});
  }
  dfs(x + 1, cnt + 1, awa + ctst[x].c, g);
  for (int i = 1; i <= n; i++){
    g.pop_back();
  }
}
signed main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  #ifndef QWQ
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  #endif
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    Graph.push_back({u, v, w});
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= k; i++){
    cin >> ctst[i].c;
    for (int j = 1; j <= n; j++){
      cin >> ctst[i].w[j];
    }
  }
  
  if (!k){
    Solve_k_is_zero();
  }
  vector<Node> g;
  dfs(1, 0, 0, g);
  cout << ANS;
  return 0;
}
/*
第二题也被创s了 

开了最小生成树的 20 分

然后尝试了一些神奇方法，或许能多一点点分 
*/
