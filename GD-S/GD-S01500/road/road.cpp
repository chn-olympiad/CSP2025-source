#include<bits/stdc++.h>
#define ll long long
#define db double
#define pir pair<int, int> 
#define mkpir make_pair
#define pb push_back
#define umap unordered_map
#define fi first
#define se second
using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10, K = 15;
const ll mod = 998244353, INF = 1e18;

/*
struct edge{
  int v, next;
}edges[M << 1];
int head[N], idx;

void add_edge(int u, int v){
  edges[++idx] = {v, head[u]};
  head[u] = idx;
}*/

void chkmax(ll& x, ll y){if(y > x) x = y;}
void chkmin(ll& x, ll y){if(y < x) x = y;}
void chkmax(int& x, int y){if(y > x) x = y;}
void chkmin(int& x, int y){if(y < x) x = y;}
void ADD(ll& x, ll y){x += y; (x >= mod) ? (x -= mod) : 0ll;}
void MUL(ll& x, ll y){x = x * y % mod;}

ll qpow(ll x, int y){
  ll ret = 1;
  for(; y; y >>= 1, x = x * x % mod) if(y & 1) ret = ret * x % mod;
  return ret;
}
//#define int long long

struct Edge{
  int x, y; ll w;
}E[M], G[M], a[K][N], tmp[M];

int n, m, k, fa[N], siz[N], tot;
ll c[N];

int findfa(int x){return (fa[x] = (fa[x] != x) ? findfa(fa[x]) : x);}

void merge(int x, int y){
  x = findfa(x); y = findfa(y);
  if(siz[x] < siz[y]) swap(x, y);
  fa[y] = x; siz[x] += siz[y];
}

bool cmp(struct Edge e1, struct Edge e2){return e1.w < e2.w;}

signed main(){
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= m; i++){
    int x, y; ll w; cin >> x >> y >> w;
    E[i] = (Edge){x, y, w};
  }
  for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  sort(E + 1, E + m + 1, cmp); ll ans = 0;
  for(int i = 1; i <= m; i++){
    if(tot == n - 1) break;
    if(findfa(E[i].x) == findfa(E[i].y)) continue;
    tmp[++tot] = E[i]; ans += E[i].w; merge(E[i].x, E[i].y);
  } 
  for(int i = 1; i < n; i++) E[i] = G[i]; 
  for(int i = 0; i < k; i++){
    cin >> c[i];
    for(int j = 1; j <= n; j++) cin >> a[i][j].w, a[i][j].x = n + i + 1, a[i][j].y = j;
    sort(a[i] + 1, a[i] + n + 1, cmp);
  }
  for(int S = 1; S < (1 << k); S++){
    tot = n - 1; ll sum = 0, cnt = n - 1;
    for(int i = 1; i < n; i++) E[i] = tmp[i];
    for(int i = 0; i < k; i++) if(S & (1 << i)){
      sum += c[i]; cnt++;
      int now = 1, qwq = 0;
      for(int j = 1; j <= tot; j++) G[j] = E[j];
      for(int j = 1; j <= n; j++){
        while(now <= tot && G[now].w <= a[i][j].w) E[++qwq] = G[now], now++;
        E[++qwq] = a[i][j];
      } tot = qwq;
    }
    for(int i = 1; i <= n + k; i++) fa[i] = i, siz[i] = 1;
    for(int i = 1; i <= tot; i++){
      if(cnt == 0) break; 
      if(findfa(E[i].x) == findfa(E[i].y)) continue;
      sum += E[i].w; merge(E[i].x, E[i].y); cnt--;
    } chkmin(ans, sum);
  } cout << ans;

  return 0;
}
