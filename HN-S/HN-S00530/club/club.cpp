#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e2 + 1;

int t, n, d1, d2, d3, ans, dp[MAXN][MAXN][MAXN];
bool f = 1;

vector<int> vt;

inline void solve1(){
  for(int i = 1; i <= n; i++){
    cin >> d1 >> d2 >> d3;
    for(int j = i; j >= 0; j--){
      for(int k = i; k >= 0; k--){
        if(j <= n / 2 && j){
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + d1);
        }
        if(k <= n / 2 && k){
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + d2);
        }
        if(i - j - k <= n / 2 && i - j - k){
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + d3);
        }
      }
    }
  }
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      ans = max(ans, dp[n][i][j]);
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= n; j++){
      for(int k = 0; k <= n; k++){
        dp[i][j][k] = 0;
      }
    }
  }
  cout << ans << '\n';
  ans = 0;
}

inline void Solve(){
  cin >> n;
  if(n <= 200){
    solve1();
    return;
  }
  for(int i = 1; i <= n; i++){
    cin >> d1 >> d2 >> d3;
    f &= (!d2 && !d3);
    vt.push_back(d1);
  }
  if(f){
    sort(vt.begin(), vt.end());
    int cnt = 0;
    for(const auto &v : vt){
      ans += v;
      cnt++;
      if(cnt == n / 2){
        break;
      }
    }
    cout << ans;
    return;
  }
  f = 1;
  vt.clear();
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin >> t;
  while(t--){
    Solve();
  }
  return 0;
}
