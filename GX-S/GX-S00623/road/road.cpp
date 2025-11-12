#include <bits/stdc++.h>
#define ll long long
const ll N = 2e4 + 20, K = 20, INF = 1e18;
using namespace std;

struct edge{
  int u, v;
  ll w;
  bool operator < (const edge& a) const {return w < a.w;}
  bool operator > (const edge& a) const {return w > a.w;}
};

int n, m, k;
priority_queue<edge, vector<edge>, greater<edge> >q;
vector<edge>Q;
ll c[K], a[K][N];
int fa[N], cnt[K];
ll ww[K];
ll ans = 0;

int findfa(int x){
  if(x == fa[x]) return x;
  fa[x] = findfa(fa[x]);
  return fa[x];
}

void merge(int x, int y){
  fa[findfa(x)] = findfa(y);
}

void input(){
  cin>>n>>m>>k;
  for(int i = 1; i <= m; i ++){
    int u, v;
    ll w;
    cin>>u>>v>>w;
    q.push({u, v, w});
  }
  for(int i = 1; i <= k; i ++){
    cin>>c[i];
    for(int j = 1; j <= n; j ++) cin>>a[i][j];
  }

  for(int i = 1; i <= n; i ++) fa[i] = i;
  int lst = n;
  while(!q.empty()){
    int u = q.top().u, v = q.top().v, w = q.top().w;
    q.pop();
    if(findfa(u) == findfa(v)) continue;
    merge(u, v);
    lst --;
    Q.push_back({u, v, w});
    ans += w;
    if(lst == 0) break;
  }
}

void calc(int x){
  priority_queue<edge, vector<edge>, greater<edge> >().swap(q);
  for(auto ed : Q){
    q.push(ed);
  }

  ll res = 0;
  for(int i = 1; i <= n + k; i ++) fa[i] = i;
  for(int i = 1; i <= k; i ++) cnt[i] = ww[i] = 0;

  for(int i = 1; i <= k; i ++){
    if( ((1 << (i - 1)) & x) == 0 ) continue;
    res += c[i];
    for(int j = 1; j <= n; j ++) q.push({n + i, j, a[i][j]});
  }
  int lst = n;
  while(!q.empty()){
    int u = q.top().u, v = q.top().v;
    ll w = q.top().w;
    q.pop();
    if(findfa(u) == findfa(v)) continue;
    if(findfa(u) <= n) lst --;
    if(u <= n) res += w;
    else{
      if(cnt[u - n] == 0) ww[u - n] = w;
      else if(cnt [u - n] == 1) res += w + ww[u - n];
      else res += w;
      cnt[u - n] ++;
    }
    if(res >= ans) return;
    merge(u, v);
    if(lst == 0) break;
  }
  ans = min(ans, res);
}

void solve(){
  input();
  for(int i = 1; i < (1 << k); i ++)
    calc(i);
  cout<<ans<<"\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  solve();

  return 0;
}
