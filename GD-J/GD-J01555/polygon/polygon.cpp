#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int X = 5e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int n, a[X];
ll p[X], f[X][X], ans;

int main() {
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  cfor (i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);

  p[0] = 1;
  cfor (i, 1, n) p[i] = (p[i - 1] * 2) % mod;

  cfor (j, 0, a[n]) f[0][j] = 1;
  cfor (i, 1, n) {
    cfor (j, 0, a[n]) {
      f[i][j] = f[i - 1][j];
      if (j - a[i] >= 0) f[i][j] += f[i - 1][j - a[i]];
      f[i][j] %= mod;
    }
  }

  cfor (i, 3, n) {
    ans += (p[i - 1] - f[i - 1][a[i]] + mod) % mod;
    ans %= mod;
  }
  cout << ans;
  return 0;
}