#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> bel(n + 1), cnt(3), r(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int p = 0;
      vector<pair<int, int>> num(3);
      for (int j = 0; j < 3; j++) {
        cin >> num[j].fi;
        num[j].se = j;
      }
      sort(num.begin(), num.end());
      cnt[bel[i] = num[2].se]++;
      ans += num[2].fi;
      r[i] = num[1].fi - num[2].fi;
    }
    int flag = -1;
    if (cnt[0] > n / 2) flag = 0;
    if (cnt[1] > n / 2) flag = 1;
    if (cnt[2] > n / 2) flag = 2;
    if (flag >= 0) {
      priority_queue<int> q;
      for (int i = 1; i <= n; i++) {
        if (bel[i] != flag) continue;
        q.push(r[i]);
      }
      while (cnt[flag] > n / 2) {
        cnt[flag]--;
        ans += q.top(), q.pop();
      }
    }
    cout << ans << '\n';
  }
  return 0;
}