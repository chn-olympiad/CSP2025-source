#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5, mod = 998244353;

int f[N], a[N];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n, less<int>());
  int m = a[n]; f[0] = 1;
  int ans = 0;
  for(int i = 1; i < n; i++) {
    for(int j = m + 1; j >= 0; j--) 
      (f[min(m + 1, j + a[i])] += f[j]) %= mod;
    for(int j = a[i + 1] + 1; j <= m + 1; j++)
      (ans += f[j]) %= mod;
  }
  cout << ans << '\n';
}

signed main() {
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}