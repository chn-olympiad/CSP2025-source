#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool cmax(T& x, T y) { if (x < y) return x = y, true; return false; }
template<class T> inline bool cmin(T& x, T y) { if (x > y) return x = y, true; return false; }
using u64 = unsigned long long;
mt19937_64 rng(random_device{}());
constexpr int N = 2e5 + 9, L = 5e6 + 9;
constexpr u64 md = (1LL << 61) - 1;
const u64 seed = uniform_int_distribution<u64>(md >> 2, md >> 1)(rng);
int n, q, len[N], lft[N], rht[N];
u64 pw[L];
vector<u64> hsh[N][2], hst[2];
string s[N][2];
map<pair<u64, u64>, vector<int>> mp;
u64 add(u64 x, u64 y) {
  x += y;
  if (x >= md) x -= md;
  return x;
}
u64 sub(u64 x, u64 y) {
  x += md - y;
  if (x >= md) x -= md;
  return x;
}
u64 mul(u64 x, u64 y) {
  __int128 res = (__int128) x * y;
  u64 tmp = u64(res & md) + u64(res >> 61);
  if (tmp >= md) tmp -= md;
  return tmp;
}
u64 get(const vector<u64> &h, int l, int r) {
  return sub(h[r], mul(h[l - 1], pw[r - l + 1]));
}
signed main() {
#ifndef LOCAL
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = pw[0] = 1; i < L; ++i) pw[i] = mul(pw[i - 1], seed);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i][0] >> s[i][1];
    len[i] = s[i][0].size();
    s[i][0] = ' ' + s[i][0];
    s[i][1] = ' ' + s[i][1];
    hsh[i][0].resize(len[i] + 1);
    hsh[i][1].resize(len[i] + 1);
    for (int j = 1; j <= len[i]; ++j) hsh[i][0][j] = add(mul(hsh[i][0][j - 1], seed), s[i][0][j]);
    for (int j = 1; j <= len[i]; ++j) hsh[i][1][j] = add(mul(hsh[i][1][j - 1], seed), s[i][1][j]);
    int l = 1, r = len[i];
    while (l < len[i] && s[i][0][l] == s[i][1][l]) ++l;
    while (r > 1 && s[i][0][r] == s[i][1][r]) --r;
    if (l <= r) mp[{get(hsh[i][0], l, r), get(hsh[i][1], l, r)}].push_back(i);
    lft[i] = l, rht[i] = r;
  }
  for (auto &[x, y] : mp) {
    sort(y.begin(), y.end(), [&](int i, int j) -> bool {
      return len[i] - lft[i] < len[j] - lft[j];
    });
  }
  // return 0;
  while (q--) {
    string t[2];
    cin >> t[0] >> t[1];
    const int m = t[0].size();
    t[0] = ' ' + t[0], t[1] = ' ' + t[1];
    vector<u64> ().swap(hst[0]);
    vector<u64> ().swap(hst[1]);
    hst[0].resize(m + 1), hst[1].resize(m + 1);
    for (int i = 1; i <= m; ++i) hst[0][i] = add(mul(hst[0][i - 1], seed), t[0][i]);
    for (int i = 1; i <= m; ++i) hst[1][i] = add(mul(hst[1][i - 1], seed), t[1][i]);
    int l = 1, r = m;
    while (l < m && t[0][l] == t[1][l]) ++l;
    while (r > 1 && t[0][r] == t[1][r]) --r;
    // cerr << l << ' ' << r << '\n';
    vector<int> id;
    // assert(l <= r);
    id = mp[{get(hst[0], l, r), get(hst[1], l, r)}];
    int ans = 0;
    for (auto i : id) {
      int L = l - lft[i] + 1;
      if (L + len[i] - 1 > m) break;
      if (get(hsh[i][0], 1, len[i]) == get(hst[0], L, L + len[i] - 1)) {
        if (get(hsh[i][1], 1, len[i]) == get(hst[1], L, L + len[i] - 1)) ++ans;
      }
    }
    cout << ans << '\n';
  }
}