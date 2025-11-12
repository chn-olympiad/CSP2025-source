#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
int n, a[N][3], ans, cnt[3];
vector<int> b[3];

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    ans = 0;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < 3; i++) b[i].clear();
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> a[i][j];
      }
      int z = max_element(a[i], a[i] + 3) - a[i];
      cnt[z]++;
      ans += a[i][z];
      sort(a[i], a[i] + 3);
      b[z].push_back(a[i][2] - a[i][1]);
    }
    int id = -1;
    if (cnt[0] > n / 2) id = 0;
    if (cnt[1] > n / 2) id = 1;
    if (cnt[2] > n / 2) id = 2;
    if (id != -1) {
      sort(b[id].begin(), b[id].end());
      for (int i = 0; i < cnt[id] - n / 2; i++) {
        ans -= b[id][i];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}