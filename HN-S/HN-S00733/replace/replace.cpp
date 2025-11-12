#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e6 + 5;

int n, q, cnt, p[N][3][2], sum[3][N][2];

int c[2] = {157, 251}, mod[2] = {998244353, 1000000007};

string a[N][3];

int mypow(int a, int b, int op) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = 1ll * ans * a % mod[op];
    }
    a = a * a % mod[op];
    b >>= 1;
  }
  return ans;
}

int query(int l, int r, int res, int op) {
  if (l > r) {
    return 0;
  }
  return (sum[res][r][op] - 1ll * sum[res][l - 1][op] * mypow(c[op], r - l + 1, op) % mod[op] + mod[op]) % mod[op];
}

int Get(int op, int i, int j, int len2, int len) {
  return (sum[1][i - 1][op] * mypow(c[op], len - i + 1, op) % mod[op] + p[j][2][op] * mypow(c[op], len - (i + len2 - 1), op) % mod[op] + query(i + len2, len, 1, op) % mod[op]) % mod[op];
}

void Solve1() {
  while (q--) {
    string s, t;
    int len, ans = 0;
    cin >> s >> t;
    len = s.size();
    s = " " + s, t = " " + t;
    for (int i = 1; i <= len; i++) {
      for (auto op : {0, 1}) {
        sum[1][i][op] = (1ll * sum[1][i - 1][op] * c[op] % mod[op] + (int)(s[i] - 'a' + 1)) % mod[op];
      }
      for (auto op : {0, 1}) {
        sum[2][i][op] = (1ll * sum[2][i - 1][op] * c[op] % mod[op] + (int)(t[i] - 'a' + 1)) % mod[op];
      }
    }
    for (int i = 1; i <= len; i++) {
      for (int j = 1; j <= n; j++) {
        if (i + a[j][1].size() - 1 <= len) {
          int len2 = a[j][1].size();
          int tmp1 = query(i, i + len2 - 1, 1, 0), tmp2 = query(i, i + len2 - 1, 1, 1);
          //cout << Get(0, i, j, len2, len) << "\n";
          if (tmp1 == p[j][1][0] && tmp2 == p[j][1][1] && Get(0, i, j, len2, len) == sum[2][len][0] && Get(1, i, j, len2, len) == sum[2][len][1]) {
            ans++;
          }
        }
      }
    }
    cout << ans << "\n";
  }
}

signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1] >> a[i][2];
    for (int j = 1; j <= 2; j++) {
      for (auto op : {0, 1}) {
        int sum = 0;
        for (auto cur : a[i][j]) {
          sum = (1ll * sum * c[op] % mod[op] + (int)(cur - 'a' + 1)) % mod[op];
        }
        p[i][j][op] = sum;
      }
    }
    //cout << p[i][1][0] << " " << p[i][1][1] << " " << p[i][2][0] << " " << p[i][2][1] << "\n";
    cnt += a[i][1].size();
  }
  Solve1();
  return 0;
}
