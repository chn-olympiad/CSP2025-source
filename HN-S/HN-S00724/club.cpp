#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N][3];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  priority_queue<int> s1, s2, s3;
  for (int i = 1; i <= n; i++) {
    if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
      s1.push(max(a[i][2], a[i][3]) - a[i][1]);
      ans += a[i][1];
    } else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
      s2.push(max(a[i][1], a[i][3]) - a[i][2]);
      ans += a[i][2];
    } else {
      s3.push(max(a[i][1], a[i][2]) - a[i][3]);
      ans += a[i][3];
    }
  }
  while (s1.size() > n / 2) {
    ans += s1.top();
    s1.pop();
  }
  while (s2.size() > n / 2) {
    ans += s2.top();
    s2.pop();
  }
  while (s3.size() > n / 2) {
    ans += s3.top();
    s3.pop();
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
// Bei dabai le.