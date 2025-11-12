#include<bits/stdc++.h>

using namespace std;

const int MAX = 2e3 + 1, MOD = 1e9 + 7;

string s1[MAX], s2[MAX], t1, t2;
long long hs1[MAX], hs2[MAX], ths1[MAX], ths2[MAX], pw[MAX];

int n, q, l, r, ans = 0;

inline void solve(){
  cin >> t1 >> t2;
  if(t1.size() != t2.size()){
    cout << 0 <<'\n';
    return;
  }
  ans = 0;
  l = r = -1;
  for(int i = 0; i < t1.size(); i++){
    if(t1[i] != t2[i]){
      if(l == -1) l = i;
      r = i;
    }
    ths1[i] = 1ll * pw[i] * (t1[i] - 'a') % MOD;
    ths2[i] = 1ll * pw[i] * (t2[i] - 'a') % MOD;
    if(i){
      ths1[i] += ths1[i - 1];
      ths2[i] += ths2[i - 1];
    }
  }
  for(int i = r; i < t1.size(); i++){
    for(int j = 1; j <= n; j++){
      if(i - s1[j].size() + 1 > l || i - s1[j].size() + 1 < 0) continue;
      long long u1, u2;
      if(i - s1[j].size() < 0) u1 = ths1[i], u2 = ths2[i];
      else u1 = ths1[i] - ths1[i - s1[j].size()], u2 = ths2[i] - ths2[i - s2[j].size()];
      if(u1 < 0) u1 += MOD;
      if(u2 < 0) u2 += MOD;
      //cout << u1 << ' ' << hs1[j] * pw[i - s1[j].size() + 1] % MOD << '\n';
      if(u1 == hs1[j] * pw[i - s1[j].size() + 1] % MOD && u2 == hs2[j] * pw[i - s1[j].size() + 1] % MOD){
        ++ans;
      }
    }
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  pw[0] = 1;
  for(int i = 1; i < MAX; i++){
    pw[i] = 1ll * pw[i - 1] * 26 % MOD;
  }
  for(int i = 1; i <= n; i++){
    cin >> s1[i] >> s2[i];
    for(int j = 0; j < s1[i].size(); j++){
      hs1[i] = (hs1[i] + 1ll * (s1[i][j] - 'a') * pw[j]) % MOD;
    }
    for(int j = 0; j < s2[i].size(); j++){
      hs2[i] = (hs2[i] + 1ll * (s2[i][j] - 'a') * pw[j]) % MOD;
    }
  }
  while(q--){
    solve();
  }
  return 0;
}
