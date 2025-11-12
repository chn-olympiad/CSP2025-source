#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL_IO
#include <iostream>
#else
#include <fstream>

const string kFile = "club";
ifstream cin(kFile + ".in");
ofstream cout(kFile + ".out");
#endif

const int kN = 1e5 + 1;

int tt, n, a[kN][3], p[kN], c[3], ans, b[kN], m;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> tt; tt--; ) {
    c[0] = c[1] = c[2] = ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      for (int &j : a[i]) {
        cin >> j;
      }
      ++c[p[i] = max_element(a[i], a[i] + 3) - a[i]];
      ans += a[i][p[i]];
    }
    int mc = max_element(c, c + 3) - c;
    if (c[mc] <= n / 2) {
      cout << ans << '\n';
      continue;
    }
    m = 0;
    for (int i = 1; i <= n; ++i) {
      if (p[i] == mc) {
        int v = 1e9;
        for (int j : {0, 1, 2}) {
          if (j != mc) {
            v = min(v, a[i][mc] - a[i][j]);
          }
        }
        b[++m] = v;
      }
    }
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= c[mc] - n / 2; ++i) {
      ans -= b[i];
    }
    cout << ans << '\n';
  }
  return 0;
}