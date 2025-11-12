#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kN = 507;

int n, m, a[kN], ans, d[kN], chk = 1;
bool b[kN];
char tmp;

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout); 
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> tmp, b[i] = (tmp == '1');
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    chk &= (a[i] == 1);
    d[i] = i;
  }
  int fail = 0;
  if (chk) {
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      if (b[i]) tot++;
      else break;
    }
    if (tot < m) {
      cout << 0;
      return 0;
    }
    int nans = 1, mod = 998244353;
    for (int i = 1; i <= n; i++) {
      nans = nans * i % mod;
    }
    cout << nans << '\n';
    return 0;
  }
  do {
    fail = 0;
    for (int i = 1; i <= n; i++) {
      fail += (fail >= a[d[i]] || b[i] == 0);
    }
    ans += (n - fail >= m);
  } while (next_permutation(d + 1, d + n + 1));
  cout << ans;

  return 0;
}
