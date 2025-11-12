#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("employ.in");
ofstream fout("employ.out");

const int kN = 501, kV = 18, kM = 998244353;

int n, m, fl = 1, c[kN], f[2][19][1 << kV];
string t;

int main() {
  fin.tie(0)->sync_with_stdio(0);
  fin >> n >> m >> t, t = ' ' + t;
  for (int i = 1; i <= n; i++)
    fl &= t[i] == '1';
  for (int i = 1; i <= n; i++)
    fin >> c[i];
  if (fl) {
    int ans = 1;
    for (int i = 2; i <= n; i++)
      ans = 1ll * ans * i % kM;
    fout << ans;
  } else if (n <= 18) {
    f[0][0][0] = 1;
    int o = 1;
    for (int i = 1; i <= n; i++, o ^= 1) {
      for (int j = 0; j <= i; j++)
        for (int k = 0; k < 1 << kV; k++)
          f[o][j][k] = 0;
      for (int s = 0; s < 1 << n; s++) {
        if (__builtin_popcount(s) != i - 1)
          continue;
        for (int j = 1; j <= n; j++) {
          if (s & (1 << (j - 1)))
            continue;
          int _s = s | (1 << (j - 1));
          for (int k = 0; k < i; k++) {
            if (c[j] > k && t[i] == '1')
              f[o][k][_s] = (f[o ^ 1][k][s] + f[o][k][_s]) % kM;
            else
              f[o][k + 1][_s] = (f[o ^ 1][k][s] + f[o][k + 1][_s]) % kM;
          }
        }
      }
    }
    int ans = 0;
    o ^= 1;
    for (int i = 0; i <= n - m; i++)
        ans = (ans + f[o][i][(1 << n) - 1]) % kM;
    fout << ans;
  } else
    fout << 0;
  return 0;
}