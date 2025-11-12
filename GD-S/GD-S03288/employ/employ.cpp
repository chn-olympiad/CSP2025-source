#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ep emplace
#define eb emplace_back
#define fr(a,b,c) for(int (a) = (b);(a) <= (c);a ++) 
using namespace std;
const int N = 600;
const ll MOD = 998244353;
int n,m,c[N];
ll fct[N];
string s;
void workD(){
  fr(i,1,n){
    if(s[i] == '0' || c[i] == 0){
      printf("0");
      return;
    }
  }
  ll ans = 1;
  fr(i,1,n) ans = ans * i % MOD;
  printf("%lld\n",ans);
}
void workC(){
  vector<int> S(N,0);
  fct[0] = 1;
  fr(i,1,N - 1) fct[i] = fct[i - 1] * i % MOD;
  ll ans = 0;
  fr(i,1,n) S[c[i]] ++;
  fr(i,1,n) S[i] += S[i - 1];
  fr(i,1,n){
    int cnt = 0;
    ll tmp = S[n] - S[i - 1];
    if(s[i] == '0') continue;
    fr(j,1,i - 1) if(s[j] == '1') tmp = tmp * max(0,S[j - 1] - cnt) % MOD,cnt ++;
    cnt ++;
    ans = (ans + tmp * fct[n - cnt]) % MOD;
  }
  printf("%lld\n",ans);
}
void work1(){
  vector<vector<ll>> f(262200,vector<ll> (20,0));   
  f[0][0] = 1;
  fr(st,1,(1 << n) - 1){
    int bt = __builtin_popcount(st);
    fr(j,0,bt){
      fr(lst,1,n){
        int p = 1 << lst - 1;
        if(!(st & p)) continue;
        if(j && (s[bt] == '0' || c[lst] < j)) f[st][j] = (f[st][j] + f[st - p][j - 1]) % MOD;
        if(s[bt] == '1' && c[lst] > j) f[st][j] = (f[st][j] + f[st - p][j]) % MOD; 
      }
    }
  }
  ll ans = 0;
  fr(i,m,n) ans = (ans + f[(1 << n) - 1][n - i]) % MOD;
  printf("%lld\n",ans);
}
// void workB(){
//   fct[0] = 1;
//   fr(i,1,N - 1) fct[i] = fct[i - 1] * i % MOD;
//   ll ans = 0;
//   vector<int> pu,S(N,0);
//   fr(i,1,n) S[c[i]] ++;
//   fr(i,1,n) S[i] += S[i - 1];
//   fr(i,1,n) if(s[i] == '1') pu.eb(i);
//   int x = pu.size();
//   fr(i,0,(1 << x) - 1){
//     if(__builtin_popcount(i) < m) continue;
//     int cnt = 0;
//     ll tmp = 1;
//     fr(j,0,x - 1){
//       if(x & (1 << j)) cnt ++;
//       else tmp = tmp * max(0,S[pu[j] - 1 - cnt]) % MOD;
//     }
//     cnt = __builtin_popcount(i) - 1;
//     for(int j = x - 1;~j;j --){
//       if(x & (1 << j)) tmp = tmp * max(0,S[n] - S[pu[j] - 1 - cnt]) % MOD,cnt --;
//     }
//     ans = (ans + tmp * fct[n - x]) % MOD;
//   }
//   printf("%lld\n",ans);
// }
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  cin >> s,s = " " + s;
  fr(i,1,n) cin >> c[i];
  if(m == n){workD();return 0;}
  if(m == 1){workC();return 0;}
  if(n <= 18){work1();return 0;}
  // int sum_s = 0;
  // fr(i,1,n) sum_s += s[i] - '0';
  // if(sum_s <= 18){workB();return 0;}
  printf("0\n");
  return 0;
}
