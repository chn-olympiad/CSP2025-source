#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll kM = 505, mod = 998244353;
ll n, m, c[kM], fr[kM], cnt, p[kM], vis[kM], ans, tt;
string s;
void check(){
  ll cnt = 0, tt = 0;
  for(int i = 1; i <= n; i++){
    if(s[i] == '1' && c[p[i]] > cnt) tt++;
    else cnt++;
  }
  if(tt >= m) ans++;
  return;
}
void dfs(int k){
  if(k == n + 1){
    check();
    return;
  }
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      vis[i] = 1;
      p[k] = i;
      dfs(k + 1);
      vis[i] = 0;
    }
  }
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> s;
  s = " " + s;
  fr[0] = 1;
  for(int i = 1; i <= n; i++){
    cin >> c[i];
    fr[i] = fr[i - 1] * i % mod;
    cnt += (s[i] == '1');
  }
  if(n <= 10){
    dfs(1);
    cout << ans;
    return 0;
  }
  if(cnt < m){
    cout << 0;
    return 0;
  }
  cout << fr[n];
  return 0;
}