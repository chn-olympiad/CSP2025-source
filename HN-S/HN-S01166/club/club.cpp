#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1e5 + 100;

int t, n;

struct Node {
  int a, b, c, pa, pb, pc;
  const bool operator < (const Node &e) const {
    return a > e.a;
  }
} a[N];

struct Edge {
  int x, id;
  const bool operator < (const Edge &e) const {
    return x > e.x;
  }
};

priority_queue<Edge> q1, q2, q3;

void solve() {
  cin >> n;
  if (n == 2) {
    cin >> a[1].a >> a[1].b >> a[1].c >> a[2].a >> a[2].b >> a[2].c;
    cout << max(a[1].a + a[2].b, max(a[1].a + a[2].c, max(a[1].b + a[2].a, max(a[1].b + a[2].c, max(a[1].c + a[2].a, a[1].c + a[2].b))))) << '\n';
    return ;
  }
  while (!q1.empty()) {
    q1.pop();
  }
  while (!q2.empty()) {
    q2.pop();
  }
  while (!q3.empty()) {
    q3.pop();
  }
  for (int i = 1; i <= n; i++) {
    a[i].pa = a[i].pb = a[i].pc = 0;
  }
  bool vis = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].a >> a[i].b >> a[i].c;
    if (a[i].a >= a[i].b && a[i].a >= a[i].c) {
      a[i].pa = 1;
      a[i].pb = (a[i].b >= a[i].c ? 2 : 3);
      a[i].pc = (a[i].c >= a[i].b ? 2 : 3);
    } else if (a[i].b >= a[i].a && a[i].b >= a[i].c) {
      a[i].pb = 1;
      a[i].pa = (a[i].a >= a[i].c ? 2 : 3);
      a[i].pc = (a[i].c >= a[i].a ? 2 : 3);
    } else {
      a[i].pc = 1;
      a[i].pa = (a[i].a >= a[i].b ? 2 : 3);
      a[i].pb = (a[i].b >= a[i].a ? 2 : 3);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].b != 0 || a[i].c != 0) {
      vis = 0;
      break;
    }
  }
  sort(a + 1, a + n + 1);
  if (vis) {
    int ans = 0;
    for (int i = 1; i <= n / 2; i++) {
      ans += a[i].a;
    }
    cout << ans << '\n';
    return ;
  }
//  cout << "a = \n";
//  for (int i = 1; i <= n; i++) {
//    cout << a[i].a << ' ' << a[i].b << ' ' << a[i].c << '\n';
//  }
//  cout << "---\n";
  int cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].pa == 1) {
      if (cnt1 < n / 2) {
        cnt1++;
        ans += a[i].a;
        q1.push({a[i].a, i});
//        cout << "i = " << i << " ans = " << ans << '\n';
      } else {
        int it = q1.top().id;
        if (a[i].a > a[it].a) {
          ans += a[i].a;
          q1.pop();
          q1.push({a[i].a, i});
        } else if (a[it].b + a[i].a > a[it].a + a[i].b) {
          if (a[it].pb == 2) {
            ans += a[it].b + a[i].a - a[it].a;
          } else {
            ans += a[it].c + a[i].a - a[it].a;
          }
          q1.pop();
        } else if (a[it].c + a[i].a > a[it].a + a[i].c) {
          ans += a[it].c + a[i].a - a[it].a;
          q1.pop();
        } else {
          ans += max(a[it].b, a[it].c);
          q1.pop();
        }
      }
    } else if (a[i].pb == 1) {
      if (cnt2 < n / 2) {
        cnt2++;
        ans += a[i].b;
        q2.push({a[i].b, i});
//        cout << "i = " << i << " ans = " << ans << '\n';
      } else {
        int it = q2.top().id;
        if (a[i].b > a[it].b) {
          ans += a[i].b;
          q2.pop();
          q2.push({a[i].b, i});
        } else if (a[it].a + a[i].b > a[it].b + a[i].a) {
          if (a[it].pa == 2) {
            ans += a[it].a + a[i].b - a[it].b;
          } else {
            ans += a[it].c + a[i].b - a[it].b;
          }
          q2.pop();
        } else if (a[it].c + a[i].b > a[it].b + a[i].c) {
          ans += a[it].c + a[i].b - a[it].b;
          q2.pop();
        } else {
          ans += max(a[it].a, a[it].b);
          q2.pop();
        }
      }
    } else {
      if (cnt3 < n / 2) {
        cnt3++;
        ans += a[i].c;
        q3.push({a[i].c, i});
//        cout << "i = " << i << " ans = " << ans << '\n';
      } else {
        int it = q3.top().id;
        if (a[i].c > a[it].c) {
          ans += a[i].c;
          q3.pop();
          q3.push({a[i].c, i});
        } else if (a[it].a + a[i].c > a[it].c + a[i].a) {
          if (a[it].pa == 2) {
            ans += a[it].a + a[i].c - a[it].c;
          } else {
            ans += a[it].b + a[i].c - a[it].c;
          }
          q3.pop();
        } else if (a[it].b + a[i].c > a[it].c + a[i].b) {
          ans += a[it].b + a[i].c - a[it].c;
          q3.pop();
        } else {
          ans += max(a[it].a, a[it].b);
          q3.pop();
        }
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

/*
1
4
0 2 3
0 2 3
0 2 3
0 2 3
*/

/*
哎，终究没有调出来 T1，那我也就退役了。
AFO on 2025/11/1
对了，今天是我生日。
最后 10 分钟，再玩一次扫雷，致我的 OI 生涯。 
*/
