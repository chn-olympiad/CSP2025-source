#include<bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = (1 << 18) + 5;
const int K = 20;
const int mod = 998244353;

long long pl[N];
int n, m, c[N], cnt[N], cc[N][N], dp[M][K], f[N][N];
string s;

void Solve(){
  dp[0][0] = 1;
  for(int i = 0; i < (1 << n); i++){
    if(i == (1 << n) - 1) break;
    int num = 1;
    for(int j = 0; j < n; j++){
      if((i >> j) & 1) num++;
    }
    for(int j = 0; j < n; j++){
      if((i >> j) & 1) continue;
      for(int k = 0; k < num; k++){
        if(s[num] == '0'){
          dp[i | (1 << j)][k] += dp[i][k];
          if(dp[i | (1 << j)][k] >= mod) dp[i | (1 << j)][k] -= mod;
        }
        else{
          if(num - 1 - k >= c[j + 1]){
            dp[i | (1 << j)][k] += dp[i][k];
            if(dp[i | (1 << j)][k] >= mod) dp[i | (1 << j)][k] -= mod;
          }
          else{
            dp[i | (1 << j)][k + 1] += dp[i][k];
            if(dp[i | (1 << j)][k + 1] >= mod) dp[i | (1 << j)][k + 1] -= mod;
          }
        }
      }
    }
  }
  int ans = 0;
  for(int i = m; i <= n; i++){
    ans += dp[(1 << n) - 1][i];
  }
  cout << ans;
}

long long solve2(){
  f[0][0] = 1;
  int su = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      for(int k = 0; k <= cnt[i - 1] && k <= j; k++){
        if(s[i] == '0'){
          f[i][j] += 1ll * f[i - 1][j - k] * cc[cnt[i - 1]][k] % mod;
        }
        else{
          f[i][j] += 1ll * f[i - 1][j - k] * cc[cnt[i - 1]][k] % mod * (0ll + j - (i - su - 1)) % mod;
        }
        if(f[i][j] >= mod) f[i][j] -= mod;
      }
    }
    su += (s[i] == '0');
  }
  return f[n][n - su - cnt[n]] * pl[su] % mod;
}

long long solve3(){
  f[0][0] = 1;
  int su = 0;
  for(int i = n; i >= 1; i--){
    for(int j = 1; j <= n; j++){
      for(int k = 0; k <= cnt[i] && k <= j; k++){
        if(s[i] == '0'){
          f[i][j] += 1ll * f[i - 1][j - k] * cc[cnt[i - 1]][k] % mod;
        }
        else{
          f[i][j] += 1ll * f[i - 1][j - k] * cc[cnt[i - 1]][k] % mod * (0ll + j - (i - su - 1)) % mod;
        }
        if(f[i][j] >= mod) f[i][j] -= mod;
      }
    }
    su += (s[i] == '0');
  }
  return f[n][n - su - cnt[n]] * pl[su] % mod;
}

bool Check_A(){
  for(int i = 1; i <= n; i++){
    if(s[i] == '0') return 0;
  }
  return 1;
}

bool Check_B(){
  return m == 1;
}

int main(){
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> s;
  s = ' ' + s;
  for(int i = 1; i <= n; i++){
    cin >> c[i];
    cnt[c[i]]++;
  }
  for(int i = 0; i <= n; i++){
    cc[i][0] = 1;
    for(int j = 1; j <= i; j++){
      cc[i][j] = cc[i - 1][j] + cc[i - 1][j - 1];
      if(cc[i][j] >= mod) cc[i][j] -= mod;
    }
  }
  pl[0] = 1;
  for(int i = 1; i <= n; i++){
    pl[i] = pl[i - 1] * i % mod;
  }
  if(n <= 18){
    Solve();
    return 0;
  }
  if(Check_A()){
    long long ans = 1;
    for(int i = 1; i <= n; i++){
      ans = ans * i % mod;
    }
    cout << ans;
    return 0;
  }
  if(Check_B()){
    long long ans = 1;
    for(int i = 1; i <= n; i++){
      ans = ans * i % mod;
    }
    cout << (ans - solve2() + mod) % mod;
    return 0;
  }
  return 0;
}
