#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL mod = 998244353;
const int MAXN = 100 + 3;

LL qpow(LL A, LL B){
  LL ret = 1;
  while(B > 0){
    if(B & 1) ret = ret * A % mod;
    A = A * A % mod, B >>= 1;
  }
  return ret;
}

string ss;
int n, m, cc[MAXN], mp[MAXN], _mp[MAXN];
LL dp[1 << 18][20];

inline void ADD(LL &x, LL y){ x = (x + y) % mod; }

// g++ employ.cpp -o run -std=c++14 -O2 -g -Wall -Wextra -fsanitize=address,undefined && time ./run < employ1.in
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("employ.in", r, stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> ss;
  m = n - m;
  for(int i = 1; i <= n; i++) cin >> cc[i], cc[i]++, mp[cc[i]]++;
  _mp[0] = mp[0];
  for(int i = 1; i <= n; i++) _mp[i] = _mp[i - 1] + mp[i];
  dp[0][0] = 1;
  for(int s = 0; s < (1 << n) - 1; s++){
    int pc = 0;
    for(int i = 0; i < n; i++) pc += (s >> i) & 1;
    for(int w = 0; w <= n; w++){
        if(dp[s][w] == 0) continue;
        for(int j = 1; j <= n; j++){
          if((s >> (j - 1)) & 1) continue;
          ADD(dp[s | (1 << (j-1))][w + (cc[j] <= w || ss[pc] == '0')], dp[s][w]);
        }
    }
  }
  LL ans = 0;
  for(int w = 0; w <= m; w++){
    cout << dp[(1 << n) - 1][w] << "\n";
    ADD(ans, dp[(1 << n) - 1][w]);
  }
  cout << ans;
  return 0;
}