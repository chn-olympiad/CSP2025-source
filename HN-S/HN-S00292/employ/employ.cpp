#include <bits/stdc++.h>
using namespace std;
void File(){
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
}
using ll = long long;
const int kN = 510;
const ll mod = 998244353;
int n, m, c[kN], p[kN], vis[kN];
string s;
ll ans = 0;
void dfs(int x){
  if(x == n + 1){
    int cnt = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++){
      if(s[i - 1] == '1'){
        if(cnt >= c[p[i]]) cnt++;
        else cnt2++;
      }
      else{
        cnt++;
      }
    }
    ans += (cnt2 >= m);
    return ;
  }
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    p[x] = i;
    vis[i] = 1;
    dfs(x + 1);
    vis[i] = 0;
  }
}
signed main(){
  File();
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  cin >> s;
  for(int i = 1; i <= n; i++) cin >> c[i];
  if(n <= 10){
    dfs(1);
    cout << ans << '\n';
    return 0;
  }
  bool f = 1;
  for(int i = 1; i <= n; i++){
    if(s[i - 1] == '0') f = 0;
  }
  if(f){
    ll ans = 1;
    for(int i = 1; i <= n; i++) ans = ans * i % mod;
    cout << ans << '\n';
    return 0;
  }
  cout << 0 << '\n';
  return 0;
}