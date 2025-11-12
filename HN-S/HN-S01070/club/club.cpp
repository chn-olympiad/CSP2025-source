#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5;

int a[MAXN][3], maxn, cnt[3], n, dp[MAXN][3];

void dfs(int t, int sum){
  if(t == n + 1){
    maxn = max(maxn, sum);
  }
  if(cnt[0] < n / 2){
    cnt[0]++;
    dfs(t + 1, sum + a[t][0]);
    cnt[0]--;
  }
  if(cnt[1] < n / 2){
    cnt[1]++;
    dfs(t + 1, sum + a[t][1]);
    cnt[1]--;
  }
  if(cnt[2] < n / 2){
    cnt[2]++;
    dfs(t + 1, sum + a[t][2]);
    cnt[2]--;
  }
}

void Solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 3; j++){
      cin >> a[i][j];
    }
  }
  maxn = 0;
  dfs(1, 0);
  cout << maxn << '\n';
}

int main(){
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  short T;
  cin >> T;
  while(T--){
    Solve();
  }
  return 0;
}
