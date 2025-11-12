#include <bits/stdc++.h>

using namespace std;

ifstream fin("employ.in");
ofstream fout("employ.out");

const int kMaxN = 501, kMidN = 18, kM = 998244353;

int f[1 << kMidN][kMidN + 1], c[kMaxN], n, m, ans, ok;
string s;

void Solve1() {
  f[0][0] = 1;
  for (int i = 0; i < 1 << n; i++) {
    int ci = __builtin_popcount(i);
    for (int j = 0; j <= n; j++) {
      if (f[i][j]) {
        for (int k = 0; k < n; k++) {
          if (!(i >> k & 1)) {
            int j2 = j + (ci - j < c[k] && s[ci] == '1');
            f[i | 1 << k][j2] = (f[i | 1 << k][j2] + f[i][j]) % kM;
          }
        }
      }
    }
  }
  for (int j = m; j <= n; j++) {
    ans = (ans + f[(1 << n) - 1][j]) % kM;
  }
  fout << ans;
}

void Solve2() {
  ans = 1, ok = 1;
  for (int i = 1; i <= n; i++) {
    ok &= s[i - 1] == '1' && c[i - 1];
    ans = 1LL * ans * i % kM;
  }
  fout << (ok ? ans : 0);
}

void Solve3() {
  int ans1 = 1, ans2 = 1, c1 = 0;
  sort(c, c + n);
  for (int i = 0, j = 0; i < n; i++) {
    if (s[i] == '1') {
      for (; j < n && c[j] <= i; j++) {
      }
      ans2 = 1LL * ans2 * max(j - c1, 0) % kM;
      c1++;
    }
    ans1 = 1LL * ans1 * (i + 1) % kM;
  }
  for (int i = 1; i <= n - c1; i++) {
    ans2 = 1LL * ans2 * i % kM;
  }
  fout << (ans1 + kM - ans2) % kM;
}

int main() {
  fin >> n >> m >> s;
  for (int i = 0; i < n; i++) {
    fin >> c[i];
  }
  // Solve1();
  // fout << '\n';
  // Solve3();
  if (n <= kMidN) {
    Solve1();
  } else if (m == n) {
    Solve2();
  } else if (m == 1) {
    Solve3();
  }
  return 0;
}