// BLuemoon_
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 2e5 + 5, kMaxM = 5e6 + 5;
const LL kP[2] = {998244853, 1000000007}, kB[2] = {41, 89};

LL T = 1, n, q, a[kMaxN], ans, b[2][kMaxM], sz[kMaxN], h[2][kMaxN], g[2][kMaxN], c[2][kMaxM], v[2][kMaxM];
string l[kMaxN], r[kMaxN], s, t;

LL Calcc(int o, int l, int r) { return (c[o][r] - (c[o][l - 1] * b[o][r - l + 1] % kP[o]) + kP[o]) % kP[o]; }
LL Calcv(int o, int l, int r) { return (v[o][r] - (v[o][l - 1] * b[o][r - l + 1] % kP[o]) + kP[o]) % kP[o]; }

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
  for (; T; T--, ans = 0) {
    cin >> n >> q, b[0][0] = b[1][0] = 1;
    for (int i = 1; i < kMaxM; i++) {
      b[0][i] = b[0][i - 1] * kB[0] % kP[0], b[1][i] = b[1][i - 1] * kB[1] % kP[1];
    }
    for (int i = 1; i <= n; i++) {
      cin >> l[i] >> r[i], sz[i] = l[i].size(), l[i] = ' ' + l[i], r[i] = ' ' + r[i];
      for (int j = 1; j <= sz[i]; j++) {
        h[0][i] = (h[0][i] * kB[0] + l[i][j] - 'a' + 1) % kP[0];
        h[1][i] = (h[1][i] * kB[1] + l[i][j] - 'a' + 1) % kP[1];
        g[0][i] = (g[0][i] * kB[0] + r[i][j] - 'a' + 1) % kP[0];
        g[1][i] = (g[1][i] * kB[1] + r[i][j] - 'a' + 1) % kP[1];
      }
    }
    for (; q; q--, ans = 0) {
      cin >> s >> t, sz[0] = s.size(), s = ' ' + s, t = ' ' + t;
      for (int i = 1; i <= sz[0]; i++) {
        c[0][i] = (c[0][i - 1] * kB[0] + s[i] - 'a' + 1) % kP[0];
        c[1][i] = (c[1][i - 1] * kB[1] + s[i] - 'a' + 1) % kP[1];
        v[0][i] = (v[0][i - 1] * kB[0] + t[i] - 'a' + 1) % kP[0];
        v[1][i] = (v[1][i - 1] * kB[1] + t[i] - 'a' + 1) % kP[1];
      }
      for (int i = 1; i <= n; i++) {
        if (sz[i] <= sz[0]) {
          for (int j = sz[i]; j <= sz[0]; j++) {
            int C[2] = {Calcc(0, j - sz[i] + 1, j), Calcc(1, j - sz[i] + 1, j)};
            int V[2] = {Calcv(0, j - sz[i] + 1, j), Calcv(1, j - sz[i] + 1, j)};
            if (C[0] == h[0][i] && C[1] == h[1][i] && V[0] == g[0][i] && V[1] == g[1][i]) {
              if ((c[0][sz[0]] - (C[0] * b[0][sz[0] - j] % kP[0]) + kP[0]) % kP[0] == (v[0][sz[0]] - (V[0] * b[0][sz[0] - j] % kP[0]) + kP[0]) % kP[0]) {
                if ((c[1][sz[0]] - (C[1] * b[1][sz[0] - j] % kP[1]) + kP[1]) % kP[1] == (v[1][sz[0]] - (V[1] * b[1][sz[0] - j] % kP[1]) + kP[1]) % kP[1]) {
                  ans++;
                }
              }
            }
          }
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
// ulimit -s 102400 && g++ replace.cpp -o replace -O2 -std=c++14 -Wall && ./replace