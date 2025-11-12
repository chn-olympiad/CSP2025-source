#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL_IO
#include <iostream>
#else
#include <fstream>

const string kFile = "employ";
ifstream cin(kFile + ".in");
ofstream cout(kFile + ".out");
#endif

const int kN = 501, kM = 998244353;

int n, m, s[kN], c[kN], b[kN], bs[kN], fc[kN], ic[kN], f[kN][kN][kN];

int P(int b, int e) {
  int s = 1;
  for (; e; e >>= 1, b = 1ll * b * b % kM) {
    (e & 1) && (s = 1ll * s * b % kM);
  }
  return s;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = fc[0] = 1; i < kN; ++i) {
    fc[i] = 1ll * fc[i - 1] * i % kM;
  }
  ic[kN - 1] = P(fc[kN - 1], kM - 2);
  for (int i = kN - 1; i; --i) {
    ic[i - 1] = 1ll * ic[i] * i % kM;
  }
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    char ch;
    cin >> ch;
    s[i] = ch - '0';
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    ++b[c[i]];
  }
  for (int i = 1; i <= n; ++i) {
    bs[i] = bs[i - 1] + b[i - 1];
  }
  f[0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int k = j; k <= i; ++k) {
        for (int l = 0; l <= i - j; ++l) {
          for (int p = 0; p <= min(k, b[j - 1]); ++p) {
            if (i - l - j - (bs[j] - k) >= 0) {
              f[i][j][k] = (f[i][j][k] + 1ll * (k - j + 1) * fc[i - l - j - (bs[j - 1] - (k - p))] % kM * ic[i - l - j - (bs[j] - k)] % kM * f[i - l - 1][j - 1][k - p]) % kM;
            }
          }
        }
        // cerr << f[i][j][k] << ' ';
      }
      // cerr << '\n';
    }
    // cerr << '\n';
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n - m; ++j) {
      if (b[j] <= i - j) {
        ans = (ans + 1ll * f[i][j][j] * fc[i - bs[j]] % kM * ic[i - bs[j + 1]] % kM * fc[n - i]) % kM;
      }
    }
  }
  cout << ans;
  return 0;
}