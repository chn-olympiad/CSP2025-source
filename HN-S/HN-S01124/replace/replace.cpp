#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL_IO
#include <iostream>
#else
#include <fstream>

const string kFile = "replace";
ifstream cin(kFile + ".in");
ofstream cout(kFile + ".out");
#endif

const int kN = 2e5 + 1;
const int kB = 11451, kM = 1e9 + 7;

int kP[kN];
struct H {
  int s, l;

  H(int s = 0, int l = 0) : s(s), l(l) {}
  H(char c) : s(c), l(1) {}
  H operator+(const H &o) const {
    return {(1ll * s * kP[o.l] + o.s) % kM, l + o.l};
  }
  H operator<<(int x) const {
    return {1ll * s * kP[x] % kM, l + x};
  }  
} h[kN][2], ht[kN][2];
int n, q, ms[kN];
string s[kN][2], t[kN][2];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = kP[0] = 1; i < kN; ++i) {
    kP[i] = 1ll * kP[i - 1] * kB % kM;
  }
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i][0] >> s[i][1];
    ms[i] = s[i][0].size();
    for (char c : s[i][0]) {
      h[i][0] = h[i][0] + H(c);
    }
    for (char c : s[i][1]) {
      h[i][1] = h[i][1] + H(c);
    }
  }
  for (int i = 1; i <= q; ++i) {
    cin >> t[i][0] >> t[i][1];
    t[i][0] = "#" + t[i][0], t[i][1] = "#" + t[i][1];
    if (t[i][0].size() != t[i][1].size()) {
      cout << 0 << '\n';
      continue;
    }
    int m = t[i][0].size() - 1;
    int l = 1;
    for (; t[i][0][l] == t[i][1][l]; ++l) {
    }
    int r = t[i][0].size() - 1;
    for (; t[i][0][r] == t[i][1][r]; --r) {
    }
    for (int j = 1; j <= m; ++j) {
      ht[j][0] = ht[j - 1][0] + H(t[i][0][j]);
      ht[j][1] = ht[j - 1][1] + H(t[i][1][j]);
    }
    int ans = 0;
    for (int j = 1; j <= l; ++j) {
      for (int k = 1; k <= n; ++k) {
        if (j + ms[k] - 1 >= r && j + ms[k] - 1 <= m) {
          if ((ht[j + ms[k] - 1][0].s - 1ll * ht[j - 1][0].s * kP[ms[k]] % kM + kM) % kM == h[k][0].s) {
            if ((ht[j + ms[k] - 1][1].s - 1ll * ht[j - 1][1].s * kP[ms[k]] % kM + kM) % kM == h[k][1].s) {
              ++ans;
            }
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}