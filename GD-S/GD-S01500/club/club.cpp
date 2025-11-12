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

const int N = 2e5 + 10, M = 1e6 + 10;
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

int n, a[N][3], chos[N], kil[N];

struct qwq{
  int val, id;
}b[N];

bool cmp(struct qwq q1, struct qwq q2){return q1.val < q2.val;}

void solve(){
  cin >> n; int cnt[3]; cnt[0] = cnt[1] = cnt[2] = 0;
  for(int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    int bst = 0;
    if(a[i][1] > a[i][bst]) bst = 1;
    if(a[i][2] > a[i][bst]) bst = 2;
    cnt[bst]++; ans += a[i][bst]; chos[i] = bst;
  }
  int bst = 0, tot = 0, id[2]; id[0] = 1; id[1] = 2;
  if(cnt[1] > cnt[bst]) bst = 1, id[0] = 0, id[1] = 2;
  if(cnt[2] > cnt[bst]) bst = 2, id[0] = 0, id[1] = 1;
  for(int i = 1; i <= n; i++){
    if(chos[i] == bst){
      b[++tot] = (qwq){a[i][bst] - a[i][id[0]], i};
      b[++tot] = (qwq){a[i][bst] - a[i][id[1]], i};
    }
  } sort(b + 1, b + tot + 1, cmp); int gg = max(cnt[bst] - n / 2, 0);
  for(int i = 1; i <= tot; i++){
    if(!gg) break;
    if(!kil[b[i].id]) ans -= b[i].val, gg--, kil[b[i].id] = 1;
  } cout << ans << "\n";
}

void clr(){
  for(int i = 1; i <= n; i++) kil[i] = 0;
}

signed main(){
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout); 
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int T = 1; cin >> T; while(T--) solve(), clr();

  return 0;
}
