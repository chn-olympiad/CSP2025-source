// BLuemoon_
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 1e5 + 5;
const LL kP = 1e9 + 7;

struct P {
  LL x, id, typ;
  bool operator<(const P &o) const { return x > o.x; }
};

LL T = 1, n, a[kMaxN][3], ans, c[3], mx[kMaxN], smx[kMaxN], mn[kMaxN];
priority_queue<P> q[3];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
  for (cin >> T; T; T--, ans = c[0] = c[1] = c[2] = 0) {
    cin >> n;
    for (; !q[0].empty(); q[0].pop()) {
    }
    for (; !q[1].empty(); q[1].pop()) {
    }
    for (; !q[2].empty(); q[2].pop()) {
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
      if (a[i][0] >= a[i][1] && a[i][1] >= a[i][2]) {
        mx[i] = 0, smx[i] = 1, mn[i] = 2;
      } else if (a[i][0] >= a[i][2] && a[i][2] >= a[i][1]) {
        mx[i] = 0, smx[i] = 2, mn[i] = 1;
      } else if (a[i][1] >= a[i][0] && a[i][0] >= a[i][2]) {
        mx[i] = 1, smx[i] = 0, mn[i] = 2;
      } else if (a[i][1] >= a[i][2] && a[i][2] >= a[i][0]) {
        mx[i] = 1, smx[i] = 2, mn[i] = 0;
      } else if (a[i][2] >= a[i][0] && a[i][0] >= a[i][1]) {
        mx[i] = 2, smx[i] = 0, mn[i] = 1;
      } else {
        mx[i] = 2, smx[i] = 1, mn[i] = 0;
      }
      c[mx[i]]++, ans += a[i][mx[i]], q[mx[i]].push({a[i][mx[i]] - a[i][smx[i]], i, 1});
    }
    for (; c[0] > n / 2 || c[1] > n / 2 || c[2] > n / 2;) {
      if (c[0] > n / 2) {
        P u = q[0].top();
        q[0].pop(), ans -= u.x, c[0]--;
        if (u.typ == 1) {
          q[smx[u.id]].push({a[u.id][smx[u.id]] - a[u.id][mn[u.id]], u.id, 2}), c[smx[u.id]]++;
        } else {
          c[mn[u.id]]++;
        }
      }
      if (c[1] > n / 2) {
        P u = q[1].top();
        q[1].pop(), ans -= u.x, c[1]--;
        if (u.typ == 1) {
          q[smx[u.id]].push({a[u.id][smx[u.id]] - a[u.id][mn[u.id]], u.id, 2}), c[smx[u.id]]++;
        } else {
          c[mn[u.id]]++;
        }
      }
      if (c[2] > n / 2) {
        P u = q[2].top();
        q[2].pop(), ans -= u.x, c[2]--;
        if (u.typ == 1) {
          q[smx[u.id]].push({a[u.id][smx[u.id]] - a[u.id][mn[u.id]], u.id, 2}), c[smx[u.id]]++;
        } else {
          c[mn[u.id]]++;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
// ulimit -s 102400 && g++ club.cpp -o club -O2 -std=c++14 -Wall && ./club