#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool cmax(T& x, T y) { if (x < y) return x = y, true; return false; }
template<class T> inline bool cmin(T& x, T y) { if (x > y) return x = y, true; return false; }
constexpr int N = 509, md = 998244353;
int n, m, c[N], p[N];
string s;
signed main() {
#ifndef LOCAL
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> s;
  s = ' ' + s;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  iota(p + 1, p + n + 1, 1);
  int ans = 0;
  do {
    int ct = 0;
    for (int i = 1, cnt = 0; i <= n; ++i) {
      if (s[i] == '0' || cnt >= c[p[i]]) ++cnt;
      else ++ct; 
    }
    if (ct >= m) {
      ++ans;
      // for (int i = 1; i <= n; ++i) cerr << p[i] << ' ';
    }
  } while (next_permutation(p + 1, p + n + 1));
  cout << ans;
}