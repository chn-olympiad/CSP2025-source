#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int MAXN = 2e5 + 10, MAXL = 5e6 + 10;
const int Base[] = {78, 91};
const int Mod[] = {998244353, 19260817};

struct Hash {
  vector<ll> p[2], h[2];
  void init(string &s) {
    int n = s.size();
    for (int _ : {0, 1}) {
      p[_].assign(n + 5, 0); p[_][0] = 1;
      h[_].assign(n + 5, 0);
      for (int i = 1; i <= n; i++) {
        p[_][i] = p[_][i - 1] * Base[_] % Mod[_];
      }
      for (int i = 0; i < n; i++) {
        h[_][i + 1] = (h[_][i] * Base[_] + s[i] - 'a' + 1) % Mod[_];
      }
    }
  }
  pll gethash(int l, int r) {
    if (l > r) return {0, 0};
    ll res[2];
    for (int _ : {0, 1}) {
      res[_] = ((h[_][r] - h[_][l - 1] * p[_][r - l + 1] % Mod[_]) % Mod[_] + Mod[_]) % Mod[_];
    }
    return {res[0], res[1]};
  }
  pll gethash(string &s) {
    ll res[] = {0, 0};
    for (int _ : {0, 1}) {
      for (char c : s) {
        res[_] = (res[_] * Base[_] + c - 'a' + 1) % Mod[_];
      }
    }
    return {res[0], res[1]};
  }
} H1, H2;

int n, q;
pair<string, string> a[MAXN];
pair<pll, pll> h[MAXN];

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    h[i].first = H1.gethash(a[i].first);
    h[i].second = H1.gethash(a[i].second);
  }
  for (int i = 1; i <= q; i++) {
    string t1, t2;
    cin >> t1 >> t2;
    if (t1.size() != t2.size()) {
      cout << 0 << '\n';
      continue;
    }
    H1.init(t1); H2.init(t2);
    int nowlen = t1.size(), ans = 0;
    for (int j = 1; j <= n; j++) {
      int len = a[j].first.size();
      for (int k = 1; k <= nowlen - len + 1; k++) {
        ans += (H1.gethash(k, k + len - 1) == h[j].first && H2.gethash(k, k + len - 1) == h[j].second && H1.gethash(1, k - 1) == H2.gethash(1, k - 1) && H1.gethash(k + len, nowlen) == H2.gethash(k + len, nowlen));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
