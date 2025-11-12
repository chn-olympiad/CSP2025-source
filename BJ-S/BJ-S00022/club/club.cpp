#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 100005;
int T, n, a[N][3], d[N], stk[N], stkc;

inline void solve() {
  cin >> n;
  // 求出人最多的社团
  int cnt[3] = {0, 0, 0};
  i64 ans = 0;
  for (int i = 1; i <= n; i++) {
    d[i] = 0; // 记得清空
    for (int j = 0; j <= 2; j++) {
      cin >> a[i][j];
      if (a[i][j] > a[i][d[i]]) d[i] = j;
    }
    cnt[d[i]]++;
    ans += a[i][d[i]];
  }
  // 超过一半就往外踢
  int pt = 0;
  for (int j = 0; j <= 2; j++)
    if (cnt[j] > cnt[pt]) pt = j;
  if (cnt[pt] > n / 2) {
    stkc = 0;
    for (int i = 1; i <= n; i++) {
      int cost = (int)1E9;
      if (d[i] == pt) {
        for (int j = 0; j <= 2; j++)
          if (j != d[i])
            cost = min(cost, a[i][d[i]] - a[i][j]);
        stk[++stkc] = cost;
      }
    }
    assert(stkc == cnt[pt]);
    sort(&stk[1], &stk[stkc + 1]);
    for (int i = 1; i <= cnt[pt] - n / 2; i++) ans -= stk[i];
  }
  cout << ans << "\n";
}
int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  while (T--) solve();
  return 0;
}