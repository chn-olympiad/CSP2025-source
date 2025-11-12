#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>
#define _for(i, a, b) for (int i = (a); i <= (b); i++)
#define _pfor(i, a, b) for (int i = (a); i >= (b); i--)

int read() {
  char c;
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}

void wr(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) wr(x / 10);
  putchar(x % 10 + '0');
}

const int N = 505, mod = 998244353;

int n, m, sum[N], c[N], pos[N], id[N], p[N], f[1 << 20][20];
char a[N];

signed main() {
//  freopen("employ4.in", "r", stdin);
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> (a + 1);
  _for(i, 1, n) cin >> c[i];
  if (n <= 18) {
    f[0][0] = 1;
    _for(i, 0, (1 << n) - 1) {
      _for(j, 0, n - 1) {
        _for(k, 0, n - 1) {
          if (!(i >> k & 1)) {
            int day = __builtin_popcount(i) + 1;
            f[i | (1 << k)][j + (j >= c[k + 1] || a[day] == '0')] = (f[i | (1 << k)][j + (j >= c[k + 1] || a[day] == '0')] + f[i][j]) % mod;
          }
        }
      }
    }
    int ans = 0;
    _for(i, 0, n - m) ans = (ans + f[(1 << n) - 1][i]) % mod;
    cout << ans << endl;
    return 0;
  }
  if (m == n) {
    int flg = 1;
    _for(i, 1, n) flg &= (c[i] > 0);
    if (flg == 0) puts("0");
    else {
      flg = 1;
      _for(i, 1, n) flg &= (a[i] == '1');
      if (flg == 0) puts("0");
      else {
        int res = 1;
        _for(i, 1, n) res = res * i % mod;
        cout << res << endl;
      }
    } 
    return 0;
  }
  if (m == 1) {
    int flg = 1;
    _for(i, 1, n) flg &= (c[i] == 0);
    if (flg == 1) puts("0");
    else {
      int res = 1;
      _for(i, 1, n) res = res * i % mod;
      cout << res << endl;
    }
  }
}
/*
10 10
1111111111
6 1 4 2 1 2 5 4 3 3

*/
