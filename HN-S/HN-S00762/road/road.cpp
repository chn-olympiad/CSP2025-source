#include<bits/stdc++.h>

using namespace std;

inline int read(){
  int rt = 0;
  char c = getchar();
  while(c < '0' || '9' < c) c = getchar();
  while('0' <= c && c <= '9') rt = rt * 10 + c - '0', c = getchar();
  return rt;
}

const int MAX = 1e4 + 105, MAXM = 1e6 + 1, MAXK = 11;

struct op{
  int u, v, w;
}p[MAXM];

priority_queue<pair<int, pair<int, int> > , vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > d;

vector<op> pp;

int c[MAXK], a[MAXK][MAX], b[MAX];

int n, m, k;
long long ans = 1e18;

inline bool cmp(op x, op y){
  return x.w < y.w;
}

inline int fd(int x){
  return (b[x] == x ? x : b[x] = fd(b[x]));
}

inline void wk(int ux){
  long long u = 0;
  for(int i = 0; i < pp.size(); i++){
    d.push({pp[i].w, {pp[i].u, pp[i].v}});
  }
  for(int i = 1; i <= n + k; i++) b[i] = i;

  for(int i = 1; ux; i++, ux >>= 1){
    if(ux & 1){
      u += c[i];
      for(int j = 1; j <= n; j++){
        d.push({a[i][j], {n + i, j}});
      }
    }
  }

  while(d.size()){
    pair<int, pair<int, int > > x = d.top();
    d.pop();
    if(fd(x.second.first) == fd(x.second.second)) continue;
    u += x.first;
    b[fd(x.second.first)] = fd(x.second.second);
  }
  ans = min(ans, u);
}

int main(){
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  //cin >> n >> m >> k;
  n = read(), m = read(), k = read();
  for(int i = 1; i <= n; i++) b[i] = i;
  for(int i = 1; i <= m; i++){
    p[i] = {read(), read(), read()};
  }
  sort(p + 1, p + 1 + m, cmp);
  for(int i = 1; i <= m; i++){
    if(fd(p[i].u) == fd(p[i].v)) continue;
    b[fd(p[i].u)] = fd(p[i].v);
    pp.push_back(p[i]);
  }
  for(int i = 1; i <= k; i++){
    c[i] = read();
    //cin >> c[i];
    for(int j = 1; j <= n; j++){
      a[i][j] = read();
      //cin >> a[i][j];
    }
  }
  for(int i = 0; i < (1 << k); i++){
    wk(i);
  }
  cout << ans;
  return 0;
}
