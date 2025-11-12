#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N][3];
signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios :: sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> v[3];
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      int k = 0;
      for (int j = 0; j < 3; ++j) {
        cin >> a[i][j];
        if (a[i][j] > a[i][k]) k = j;
      }
      v[k].push_back(i);
      res += a[i][k];
    }
    for (int j = 0; j < 3; ++j) {
      int l = v[j].size();
      if (l <= n / 2) continue;
      vector<int> d;
      for (int i : v[j]) {
        int newx = -1;
        for (int k = 0; k < 3; ++k) {
          if (k != j) newx = max(newx, a[i][k]);
        }
        d.push_back(newx - a[i][j]);
      }
      sort(d.begin(), d.end(), greater<int>());
      for (int i = 0; i < l - n / 2; ++i) {
        res += d[i];
      }
    }
    cout << res << '\n';
  }
  return 0;
}