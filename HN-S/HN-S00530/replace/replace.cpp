#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 1, MAXL = 5e6 + 1;
const int base = 128;
const int mod = 998244853;

int n, q, ans, h1[MAXN], h2[MAXN], p[MAXL];
string t1, t2, s1[MAXN], s2[MAXN];

inline void Solve(){
  cin >> t1 >> t2;
  for(int i = 1; i <= n; i++){
    int pos = 0;
    while(int(t1.find(s1[i], pos)) != -1){
      int pos2 = t1.find(s1[i], pos);
      string str1 = t1.substr(0, pos2), str2 = t1.substr(pos2 + s1[i].size());
      if(str1 + s2[i] + str2 == t2){
        ans++;
      }else{
        break;
      }
      pos = pos2 + 1;
    }
  }
  cout << ans << '\n';
  ans = 0;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  p[0] = 1;
  for(int i = 1; i < MAXL; i++){
    p[i] = 1ll * p[i - 1] * base % mod;
  }
  for(int i = 1; i <= n; i++){
    cin >> s1[i] >> s2[i];
    for(int j = 0; j < s1[i].size(); j++){
      h1[j] = (1ll * h1[j] * base + s1[i][j]) % mod;
    }
    for(int j = 0; j < s2[i].size(); j++){
      h2[j] = (1ll * h2[j] * base + s2[i][j]) % mod;
    }
  }
  while(q--){
    Solve();
  }
  return 0;
}
