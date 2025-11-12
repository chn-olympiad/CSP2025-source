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

const int N = 2e5 + 10, M = 5e6 + 10;
const ll mod = 1e9 + 7, INF = 1e18, bas = 1331, basinv = 197005781;

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

int n, Q;
ll ans[N];
struct dt{
  ll S, T;
  string str;
}a[N];

bool cmp(dt d1, dt d2){
  if(d1.S == d2.S) return d1.T < d2.T;
  return d1.S < d2.S;
}

struct query{
  ll S, T, pre, suf;
  string str;
  int id;
}q[N];

bool cmp2(query q1, query q2){
  if(q1.S == q2.S) return q1.T < q2.T;
  return q1.S < q2.S;
}

struct acam{
  int son[M][26], tot = 1, fail[M], sum[M];
  acam(){memset(son, 0, sizeof son); memset(fail, 0, sizeof fail); sizeof(sum, 0, sizeof sum);}
  void clr(){
    for(int i = 1; i <= tot; i++) for(int j = 0; j < 26; j++) son[i][j] = sum[i] = 0;
    tot = 1;
  }
  void insert(string str){
    int p = 1;
    for(int i = 0; i < str.size(); i++){
      int c = str[i] - 'a';
      if(!son[p][c]) son[p][c] = ++tot;
      p = son[p][c];
    } sum[p]++; //cerr << str << " " << p << "\n";
  }
  void build(){
    queue<int> Q;
    for(int i = 0; i < 26; i++){
      if(son[1][i]) fail[son[1][i]] = 1, Q.push(son[1][i]);
      else son[1][i] = 1; 
    }
    while(!Q.empty()){
      int u = Q.front(); Q.pop();
      sum[u] += sum[fail[u]];
      for(int i = 0; i < 26; i++){
        if(son[u][i]) Q.push(son[u][i]), fail[son[u][i]] = son[fail[u]][i];
        else son[u][i] = son[fail[u]][i];
      }
    }
  }
  ll calc(string str, int len){
    ll ret = 0, p = 1;
    for(int i = 0; i < len; i++){
      p = son[p][str[i] - 'a'];
      ret += sum[p]; //cerr << p << " " << sum[p] << "\n";
    } return ret;
  } 
}tr, Rtr;

ll calc(query q){
  string s = q.str; reverse(s.begin(), s.end());
  //cerr << tr.calc(q.str, q.str.size()) << " " << tr.calc(q.str, q.pre - 1) << " " << Rtr.calc(s, q.suf);
  return tr.calc(q.str, q.str.size()) - tr.calc(q.str, q.pre - 1) - Rtr.calc(s, q.suf);
}

signed main(){
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> Q; int tn = 0, tq = 0; tr.clr(); Rtr.clr();
  for(int i = 1; i <= n; i++){
    string s1, s2; cin >> s1 >> s2; int len = s1.size();
    if(s1 == s2) continue; int pre = 0, suf = 0;
    for(int i = 0; i < len; i++) if(s1[i] != s2[i]){pre = i; break;}
    for(int i = len - 1; i >= 0; i--) if(s1[i] != s2[i]){suf = i; break;}
    ll S = 0, T = 0;
    for(int i = pre; i <= suf; i++) S = (S * bas % mod + ('z' - s1[i] + 1)) % mod, T = (T * bas % mod + ('z' - s2[i] + 1)) % mod;
    a[++tn] = (dt){S, T, s1};
  } n = tn; sort(a + 1, a + n + 1, cmp);
  for(int i = 1; i <= Q; i++){
    string s1, s2; cin >> s1 >> s2; int len = s1.size();
    if(s1.size() != s2.size()) continue;
    if(s1 == s2) continue; int pre = 0, suf = 0;
    for(int i = 0; i < len; i++) if(s1[i] != s2[i]){pre = i; break;}
    for(int i = len - 1; i >= 0; i--) if(s1[i] != s2[i]){suf = i; break;}
    ll S = 0, T = 0, V = 0;
    for(int i = pre; i <= suf; i++) S = (S * bas % mod + ('z' - s1[i] + 1)) % mod, T = (T * bas % mod + ('z' - s2[i] + 1)) % mod;
    q[++tq] = (query){S, T, pre, len - suf - 1, s1, i};
  } sort(q + 1, q + tq + 1, cmp2);
  int now = 1;
  for(int i = 1; i <= tq; i++){
    if(q[i].S != q[i - 1].S || q[i].T != q[i - 1].T){
      tr.clr(); Rtr.clr();
      while(now <= n && (a[now].S < q[i].S || (a[now].S == q[i].S && a[now].T < q[i].T))) now++;
      while(now <= n && a[now].S == q[i].S && a[now].T == q[i].T){
        string s = a[now].str; reverse(s.begin(), s.end());
        tr.insert(a[now].str); Rtr.insert(s); now++;
      }
      tr.build(); Rtr.build();
    } ans[q[i].id] = calc(q[i]); //cerr << now << "\n";
  }
  for(int i = 1; i <= Q; i++) cout << ans[i] << "\n";

  return 0;
}
