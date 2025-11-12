#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 10;

int n, m, k, c[15];
int to[15][N], fa[N + 15];

struct Edge{
  int u, v, w;
};

bool cmp(const Edge &a, const Edge &b){
  return a.w < b.w;
}

vector<Edge> e, g;

ll ans = LLONG_MAX;

int find(int x){
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin >> n >> m >> k;
  for(int i = 1, u, v, w; i <= m; i++){
    cin >> u >> v >> w;
    e.push_back({u, v, w});
  }
  ll tot = 0;
  for(int i = 1; i <= k; i++){
    cin >> c[i];
    tot += c[i];
    for(int j = 1; j <= n; j++){
      cin >> to[i][j];
    }
  }
  if(tot == 0){
    g = e;
    for(int i = 1; i <= k; i++){
      for(int j = 1; j <= n; j++){
        g.push_back({n + i, j, to[i][j]});
      }
    }
    for(int i = 1; i <= n + k; i++){
      fa[i] = i;
    }
    ll sum = 0;
    sort(g.begin(), g.end(), cmp);
    int cnt = n;
    for(Edge i : g){
      int FA = find(i.u), FB = find(i.v);
      if(FA != FB){
        fa[FA] = FB;
        sum += i.w;
        if(i.u <= n || i.v <= n){
          cnt--;
        }
      }
      if(!cnt) break;
    }
    cout << sum;
    return 0;
  }
  for(int st = 0; st < (1 << k); st++){
    g = e;
    ll sum = 0;
    for(int i = 0; i < k; i++){
      if((st >> i) & 1){
        for(int j = 1; j <= n; j++){
          g.push_back({n + i + 1, j, to[i + 1][j]});
        }
        sum += c[i + 1];
      }
    }
    for(int i = 1; i <= n + k; i++){
      fa[i] = i;
    }
    sort(g.begin(), g.end(), cmp);
    int cnt = n;
    for(Edge i : g){
      int FA = find(i.u), FB = find(i.v);
      if(FA != FB){
        fa[FA] = FB;
        sum += i.w;
        if(i.u <= n || i.v <= n){
          cnt--;
        }
      }
      if(!cnt) break;
    }
    ans = min(ans, sum);
  }
  cout << ans;
  return 0;
}
/*
4 4 1
1 2 1
2 3 2
1 3 4
1 3 3
1 100 100 1 2
*/
