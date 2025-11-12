#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int T, n;
int a[N][3], dp[210][110][110];

void solve() {
  cin >> n;
  int flag1 = 1, flag2 = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> a[i][j];
    }
    if (a[i][2] != 0)
      flag1 = 0;
    if (a[i][3] != 0)
      flag2 = 0;
  }
  if (n <= 200) {
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= n / 2; j++) {
        for (int k = 0; k <= n / 2; k++) {
          int tmp = i - j - k;
          if (tmp > n / 2)
            continue;
          if (j != 0 && dp[i - 1][j - 1][k] != -1)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
          if (k != 0 && dp[i - 1][j][k - 1] != -1)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
          if (tmp <= n / 2 && dp[i - 1][j][k] != -1)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
        }
      }
    }
    for (int i = 0; i <= n / 2; i++) {
      for (int j = 0; j <= n / 2; j++) {
        int tmp = n - i - j;
        if (tmp <= n / 2) {
          ans = max(ans, dp[n][i][j]);
        }
      }
    }
    cout << ans << '\n';
    return;
  }
  if (flag1) {
    vector<int> v;
    v.push_back(0);
    for (int i = 1; i <= n; i++)
      v.push_back(a[i][1]);
    sort(v.begin() + 1, v.end(), greater<int>());
    int ans = 0;
    for (int i = 1; i <= n / 2; i++)
      ans += v[i];
    cout << ans << '\n';
    return;
  }
  if (flag2) {
    priority_queue<pii, vector<pii>, greater<pii> > q1, q2;
    for (int i = 1; i <= n; i++) {
      if (a[i][1] < a[i][2]) {
        if (q2.size() < n / 2) {
          q2.push({a[i][2], i});
        } else {
          int sum = q2.top().first, id = q2.top().second;
          int tmp = a[id][1] - sum + a[i][2];
          if (tmp > a[i][1]) {
            q2.pop();
            q1.push({a[id][1], id});
            q2.push({a[i][2], i});
          } else {
            q1.push({a[i][1], i});
          }
        }
      } else {
        if (q1.size() < n / 2) {
          q1.push({a[i][1], i});
        } else {
          int sum = q1.top().first, id = q1.top().second;
          int tmp = a[id][2] - sum + a[i][1];
          if (tmp > a[i][2]) {
            q1.pop();
            q2.push({a[id][2], id});
            q1.push({a[i][1], i});
          } else {
            q2.push({a[i][2], i});
          }
        }
      }
    }
    int ans = 0;
    while (!q1.empty()) {
      ans += q1.top().first;
      q1.pop();
    }
    while (!q2.empty()) {
      ans += q2.top().first;
      q2.pop();
    }
    cout << ans << '\n';
    return;
  }
  cout << "0\n";
}

signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
