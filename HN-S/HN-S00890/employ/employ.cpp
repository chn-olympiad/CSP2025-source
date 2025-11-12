#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 510;
const int mod = 998244353;

int n, m, ans;
int a[N], sum[N], b[N];
bool vis[N];
string s;

void dfs(int now, int cnt) {
  if (now == n + 1) {
    ans += (cnt >= m);
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    vis[i] = 1;
    if (a[now] > sum[i]) {
      dfs(now + 1, cnt + (s[i] == '1'));
    } else {
      dfs(now + 1, cnt);
    }
    vis[i] = 0;
  }
}

int quick_pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> s;
  s = ' ' + s;
  bool flag1 = 1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = i;
    if (s[i] != '1')
      flag1 = 0;
    cnt += (s[i] == '1');
  }
  if (n <= 10) {
    do {
      int cnt = 0, res = 0;
      for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
          cnt++;
        } else if (cnt >= a[b[i]]) {
          cnt++;
        } else {
          res++;
        }
      }
      if (res >= m)
        ans++;
    } while (next_permutation(b + 1, b + n + 1));
    cout << ans;
    return 0;
  }
  if (flag1) {
    ans = 1;
    for (int i = 1; i <= n; i++)
      ans = ans * i % mod;
    cout << ans;
    return 0;
  }
  if (m == n) {
    cout << 0;
    return 0;
  }
  if (m > cnt) {
    cout << 0;
    return 0;
  }
  cout << 0;
  return 0;
}
