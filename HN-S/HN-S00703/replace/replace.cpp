#include <fstream>
#include <algorithm>

using namespace std;
using LL = long long;

const LL kMaxN = 5e6 + 5, kB = 29, kMod = 114917813;

ifstream cin("replace.in");
ofstream cout("replace.out");

struct Hash {
  LL len, hsh1, hsh2;
  
  friend bool operator<(const Hash &a, const Hash &b) {
    return a.len < b.len;
  }
} a[kMaxN];

LL pre1[kMaxN], pre2[kMaxN], pw[kMaxN], n, q;
string s, t;

LL query(LL pre[], LL l, LL r) {
  return (pre[r] - pre[l - 1] * pw[r - l + 1] % kMod + kMod) % kMod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  pw[0] = 1;
  for (LL i = 1; i < kMaxN; i++) {
    pw[i] = pw[i - 1] * kB % kMod;
  }
  cin >> n >> q;
  for (LL i = 1; i <= n; i++) {
    cin >> s >> t;
    LL hsh1 = 0, hsh2 = 0;
    for (char c : s) {
      hsh1 = (hsh1 * kB % kMod + c - 'a') % kMod;
    }
    for (char c : t) {
      hsh2 = (hsh2 * kB % kMod + c - 'a') % kMod;
    }
    a[i] = Hash{(LL)s.size(), hsh1, hsh2};
  }
  sort(a + 1, a + n + 1);
  while (q--) {
    cin >> s >> t;
    LL m = s.size();
    s = " " + s;
    t = " " + t;
    for (LL i = 1; i <= m; i++) {
      pre1[i] = (pre1[i - 1] * kB % kMod + s[i] - 'a') % kMod;
    }
    for (LL i = 1; i <= m; i++) {
      pre2[i] = (pre2[i - 1] * kB % kMod + t[i] - 'a') % kMod;
    }
    LL zrr = 1, wyy = m;
    for (; zrr <= m && s[zrr] == t[zrr]; zrr++) { }
    zrr--;
    for (; wyy >= 1 && s[wyy] == t[wyy]; wyy--) { }
    wyy++;
    LL ans = 0;
    for (LL i = 1; i <= zrr + 1 && i <= m; i++) {
      LL p1 = lower_bound(a + 1, a + n + 1, Hash{wyy - i, 0, 0}) - a;
      LL p2 = upper_bound(a + 1, a + n + 1, Hash{m - i + 1, 0, 0}) - a - 1;
      for (LL j = p1; j <= p2; j++) {
        ans += query(pre1, i, i + a[j].len - 1) == a[j].hsh1 &&
               query(pre2, i, i + a[j].len - 1) == a[j].hsh2;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
