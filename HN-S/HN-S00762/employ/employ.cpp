#include<bits/stdc++.h>

using namespace std;

const int MAX = 11, MOD = 998244353;

int s[MAX], c[MAX], f[MAX][1 << MAX][MAX], h[1 << MAX];
string us;

int n, m, ans = 0;

inline void add(int &x, int y){
  if(y < 0) x += y;
  else x = x - MOD + y;
  if(x < 0) x += MOD;
}

inline int wk(int x){
  int uh = 0;
  while(x){++uh, x -= (x & -x);};
  return uh;
}

int main(){
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m;
  cin >> us;
  for(int i = 0; i < (1 << n); i++){
    h[i] = wk(i);
  }
  for(int i = 1; i <= n; i++){
    s[i] = (us[i - 1] == '1');
  }
  for(int i = 1; i <= n; i++){
    cin >> c[i];
  }
  f[0][(1 << n) - 1][0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < (1 << n); j++){
      if(h[j] != n - i + 1) continue;
      for(int z = 1; z <= n; z++){
        if((j & (1 << (z - 1))) == 0) continue;
        for(int u = 0; u <= n; u++){
          if(i - u - 1 >= c[z] || s[i] == 0){
            add(f[i][j ^ (1 << (z - 1))][u], f[i - 1][j][u]);
          }else if(u){
            add(f[i][j ^ (1 << (z - 1))][u], f[i - 1][j][u - 1]);
          }
        }
      }
    }
  }
  add(ans, f[n][0][m]);
  for(int i = 1; i < m; i++) add(ans, -f[n][0][i]);
  cout << ans;
  return 0;
}
