/*
Coder : CJSY242203 CXM
tips : 033999
Password : Ren5Jie4Di4Ling5%
Pass all simple On :
*/
#include <bits/stdc++.h>

#define int long long

using namespace std;
using ll = long long;
using pii = pair<pair<pair<int, int>, pair<int, int> >, pair<int, int> >;

const int N = 5e6 + 5, b1 = 9999049;

struct Ques {
  string s, t;
  int id;
} qu[N];

int Test, n, q;
unsigned long long H[N], S[N], p[N];
string s, t;
pii a[N];

int get_H (int l, int r) {
  return H[r] - H[l - 1] * p[r - l + 1];
}

int get_S (int l, int r) {
  return S[r] - S[l - 1] * p[r - l + 1];
}

void solve () {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> s >> t, s = " " + s, t = " " + t;
    int l = 1;
    unsigned long long hs = 0, sh = 0, hs1 = 0, sh1 = 0;
    for (; s[l] == t[l]; ++l) {
      hs1 = hs1 * b1 + s[l];
    }
    int r = s.size () - 1;
    for (; s[r] == t[r]; --r) {
      sh1 = sh1 * b1 + t[r];
    }
    string tmp1 = "", tmp2 = "";
    for (int j = l; j <= r; ++j) {
      tmp1 += s[j], tmp2 += t[j];
    }
    for (int j = 0; j < tmp1.size (); ++j) {
      hs = hs * b1 + tmp1[j];
    }
    for (int j = 0; j < tmp2.size (); ++j) {
      sh = sh * b1 + tmp2[j];
    }
    a[i] = {{{hs1, l}, {sh1, s.size () - r}}, {hs, sh}};
  }
  for (int i = 1; i <= q; ++i) {
    cin >> qu[i].s >> qu[i].t, qu[i].id = i;
    if (qu[i].s.size () != qu[i].t.size ()) {
      qu[i].s = "-1";
    }
  }
  p[0] = 1;
  for (int i = 1; i < N; ++i) {
    p[i] = p[i - 1] * b1;
  }
  for (int i = 1; i <= q; ++i) {
    if (qu[i].s == "-1") {
        cout << 0 << '\n';
        continue;
    }
    s = qu[i].s, t = qu[i].t, s = " " + s, t = " " + t;
    if (s.size () != t.size ()) {
      continue;
    }
    int l = 1;
    for (; s[l] == t[l]; ++l) {
    }
    int r = s.size () - 1;
    for (; s[r] == t[r]; --r) {
    }
    for (int j = 1; j < s.size (); ++j) {
      H[j] = H[j - 1] * b1 + s[j];
      S[j] = S[j - 1] * b1 + t[j];
    }
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
      if (a[j].second.first == get_H (l, r) && a[j].second.second == get_S (l, r)) {
        if (a[j].first.first.first == get_H (l - a[j].first.first.second + 1, l - 1)) {
          if (a[j].first.second.first == get_S (r + 1, r + a[j].first.second.second - 1)) {
            ++ans;
          }
        }
      }
    }
    cout << ans << '\n';
  }
}

signed main () {
  freopen ("replace.in", "r", stdin);
  freopen ("replace.out", "w", stdout);
  ios :: sync_with_stdio (0), cin.tie (0);
  for (Test = 1; Test--; solve ()) {
  }
  return 0;
}
/*
4 1
aa bb
a b
aaa bbb
a b
caa bbc

// freopen ()
  this is a never gonna give you up sentence.
  to day (11.1) is cxm's birthday, and I hope :
  CSP_J = 400, CSP_S = max (CSP_S, 300), rp += inf;
*/
