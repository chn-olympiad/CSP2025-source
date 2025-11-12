#include <bits/stdc++.h>
using namespace std;
#define int long long
template<class T> inline bool cmax(T& x, T y) { if (x < y) return x = y, true; return false; }
template<class T> inline bool cmin(T& x, T y) { if (x > y) return x = y, true; return false; }
constexpr int N = 1e5 + 9;
int n, a[N][4], pep[4][N], cnt[4], ans, bel[N];
signed main() {
#ifndef LOCAL
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i][1] >> a[i][2] >> a[i][3];
    cnt[1] = cnt[2] = cnt[3] = ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) pep[1][++cnt[1]] = i, a[i][2] -= a[i][1], a[i][3] -= a[i][1], ans += a[i][1], bel[i] = 1;
      else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) pep[2][++cnt[2]] = i, a[i][1] -= a[i][2], a[i][3] -= a[i][2], ans += a[i][2], bel[i] = 2;
      else pep[3][++cnt[3]] = i, a[i][1] -= a[i][3], a[i][2] -= a[i][3], ans += a[i][3], bel[i] = 3;
    }
    int id = 0;
    if (cnt[1] > n / 2) id = 1;
    if (cnt[2] > n / 2) id = 2;
    if (cnt[3] > n / 2) id = 3;
    if (id) {
      priority_queue<tuple<int, int, int>> q;
      for (int i = 1; i <= cnt[id]; ++i)
        for (int j = 1; j <= 3; ++j)
          if (j != id) q.emplace(a[pep[id][i]][j], pep[id][i], j);
      while (!q.empty() && cnt[id] > n / 2) {
        auto [x, y, z] = q.top();
        q.pop();
        if (bel[y] != id) continue;
        bel[y] = z, --cnt[id];
        ans += x;
      }
    }
    cout << ans << '\n';
  }
}