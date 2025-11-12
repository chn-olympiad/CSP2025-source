#include<bits/stdc++.h>

using namespace std;

const int N = 25, M = (1 << 18) + 5, mod = 998244353;

int ans, n, m, log_2[M], c[N], dp[M][N];
char opt[N];

int main(){
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    cin >> opt[i];
  }
  for(int i = 0; i < n; ++i){
    cin >> c[i];
  }
  if(n > 18){
    int cnt = 0;
    ans = 1;
    for(int i = 0; i < n; ++i){
      cnt += bool(c[i]);
      ans = 1ll * ans * (i + 1) % mod;
    }
    if(cnt >= m){
      cout << ans;
    }
    else{
      cout << 0;
    }
    return 0;
  }
  dp[0][0] = 1;
  for(int i = 0; i < (1 << n); i++){
    if(i)log_2[i] = log_2[i - (i & -i)] + 1;
    for(int j = 0; j < n; ++j){
      for(int k = 0; k < n; ++k){
        if(i & (1 << k))continue;
        if(opt[log_2[i] + 1] == '1' && j < c[k]){
          dp[i | (1 << k)][j] = (dp[i | (1 << k)][j] + dp[i][j]) % mod;
        }
        else{
          dp[i | (1 << k)][j + 1] = (dp[i | (1 << k)][j + 1] + dp[i][j]) % mod;
        }
      }
    }
  }
  for(int j = 0; j <= n - m; ++j){
    ans = (ans + dp[(1 << n) - 1][j]) % mod;
  }
  cout << ans;
  return 0;
}
