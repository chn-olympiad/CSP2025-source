#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 210;

int n, a[N][5], dp[M][M][M];
bool vis[N];
int cnt[5];

bool cmp(const int &a, const int &b){
  return a > b;
}

struct P{
  int v, x, type, id;
};

bool cmp2(const P &a, const P &b){
  if(a.v != b.v) return a.v > b.v;
  return a.x > b.x;
}

void solve(){
  cin >> n;
  int subA = 1, subB = 1;
  vector<int> arrayA;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= 3; j++){
      cin >> a[i][j];
    }
    arrayA.push_back(a[i][1]);
    if(a[i][2] != 0 || a[i][3] != 0){
      subA = 0;
    }
    if(a[i][3] != 0){
      subB = 0;
    }
  }
  if(n <= 200){
    for(int i = 1; i <= n; i++){
      for(int j = 0; j <= n; j++){
        for(int k = 0; k <= n; k++){
          dp[i][j][k] = 0;
        }
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
      for(int j = 0; j <= min(n / 2, i); j++){
        for(int k = 0; k <= min(n / 2, i - j); k++){
          int o = i - j - k;
          if(o < 0 || j + k + o != i || o > n / 2) continue;
          if(j) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
          if(k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
          if(o) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
          ans = max(ans, dp[i][j][k]);
        }
      }
    }
    cout << ans << "\n";
    return ;
  }
  if(subA){
    sort(arrayA.begin(), arrayA.end(), cmp);
    int ans = 0;
    for(int i = 1; i <= n / 2; i++){
      ans += arrayA[i - 1];
    }
    cout << ans << "\n";
    return ;
  }
  if(subB){
    vector<int> arrayB;
    int ans = 0;
    for(int i = 1; i <= n; i++){
      arrayB.push_back(a[i][2] - a[i][1]);
      ans += a[i][1];
    }
    sort(arrayB.begin(), arrayB.end(), cmp);
    for(int i = 1; i <= n / 2; i++){
      ans += arrayB[i - 1];
    }
    cout << ans << "\n";
    return ;
  }
  vector<P> Array;
  for(int i = 1; i <= n; i++){
    Array.push_back({a[i][1] - a[i][2] - a[i][3], a[i][1], 1, i});
    Array.push_back({a[i][2] - a[i][1] - a[i][3], a[i][2], 2, i});
    Array.push_back({a[i][3] - a[i][1] - a[i][2], a[i][3], 3, i});
  }
  sort(Array.begin(), Array.end(), cmp2);
  fill(vis + 1, vis + 1 + n, 0);
  fill(cnt + 1, cnt + 1 + 3, 0);
  int ans = 0;
  for(P i : Array){
    int type = i.type, id = i.id;
    if(vis[id]) continue;
    if(cnt[type] == n / 2) continue;
    cnt[type]++;
    vis[id] = 1;
    ans += a[id][type];
  }
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
