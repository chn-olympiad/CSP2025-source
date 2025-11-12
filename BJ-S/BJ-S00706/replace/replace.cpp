#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5, M = 5e6 + 5, P = 998244353;
long long n, q, b = 19491001, sl[N], pw[M], hu[M], hv[M];
pair<long long, long long> s[N];
long long calc(string u) {
  long long ans = 0;
  for (int i = 0; i < u.size(); i++) {
    ans += pw[i] * (u[i] - 'a') % P, ans %= P;
  }
  return ans;
}
int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * b % P;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    string u, v; cin >> u >> v;
    s[i] = {calc(u), calc(v)};
    sl[i] = u.size();
  }
  while (q--) {
    string u, v; cin >> u >> v;
    if (u.size() != v.size()) {
      cout << 0 << '\n';
      continue;
    }
    int len = u.size();
    hu[0] = u[0] - 'a';
    hv[0] = v[0] - 'a';
    for (int i = 1; i < len; i++) {
      hu[i] = hu[i - 1] + pw[i] * (u[i] - 'a') % P, hu[i] %= P;
      hv[i] = hv[i - 1] + pw[i] * (v[i] - 'a') % P, hv[i] %= P;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = sl[i] - 1; j < len; j++) {
        long long su = hu[j] - (j == sl[i] - 1 ? 0 : hu[j - sl[i]]) + P;
        long long sv = hv[j] - (j == sl[i] - 1 ? 0 : hv[j - sl[i]]) + P;
        su %= P, sv %= P;
        if (su != s[i].fi * pw[j - sl[i] + 1] % P) continue;
        long long val = hu[len - 1] - (s[i].fi - s[i].se + P) * pw[j - sl[i] + 1] % P;
        val += P, val %= P;
        if (val == hv[len - 1]) ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}