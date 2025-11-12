// g++ -std=c++14 -O2 -fsanitize=address,undefined -o employ employ.cpp && ./employ
#include <bits/stdc++.h>

// #define int int64_t

const int kMaxN = 505, kMod = 998244353;

int n, m, tot0;
int op[kMaxN], c[kMaxN], cnt[kMaxN], preo[kMaxN][2], prec[kMaxN], f[kMaxN][kMaxN][kMaxN];
int C[kMaxN][kMaxN], fac[kMaxN];
std::string str;

inline int add(int x, int y) { return (x + y >= kMod) ? (x + y - kMod) : (x + y); }
inline int sub(int x, int y) { return (x < y) ? (x - y + kMod) : (x - y); }
inline void inc(int &x, int y) { (x += y) >= kMod ? (x -= kMod) : x; }
inline void dec(int &x, int y) { (x -= y) < 0 ? (x += kMod) : x; }

void prework(int n = 500) {
  C[0][0] = fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1, fac[i] = 1ll * fac[i - 1] * i % kMod;
    for (int j = 1; j <= i; ++j)
      C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
  }
}

namespace Sub1 {
int f[1 << 18][25];

void solve() {
  f[0][0] = 1;
  for (int s = 1; s < (1 << n); ++s) {
    int c = __builtin_popcount(s);
    for (int i = 1; i <= n; ++i) {
      if (~s >> (i - 1) & 1) continue;
      int t = s ^ (1 << (i - 1));
      for (int now = 0; now <= c - 1; ++now) {
        if (op[c] && ::c[i] > now) inc(f[s][now], f[t][now]);
        else inc(f[s][now + 1], f[t][now]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n - m; ++i) inc(ans, f[(1 << n) - 1][i]);
  std::cout << ans << '\n';
}
} // namespace Sub1

void dickdreamer() {
  std::cin >> n >> m >> str;
  for (int i = 1; i <= n; ++i) {
    op[i] = str[i - 1] - '0', tot0 += !op[i];
    for (int j = 0; j < 2; ++j)
      preo[i][j] = preo[i - 1][j] + (op[i] == j);
  }
  for (int i = 1; i <= n; ++i) std::cin >> c[i], ++cnt[c[i]];
  if (n <= 18) return Sub1::solve();
  prec[0] = cnt[0];
  for (int i = 1; i <= n; ++i) prec[i] = cnt[i] + prec[i - 1];
  prework();
  f[0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (!op[i]) {
      for (int j = 0; j <= i - 1; ++j) {
        for (int k = 0; k <= n; ++k) {
          if (!f[i - 1][j][k]) continue;
          int val = f[i - 1][j][k];
          // int las = preo[i - 1][1] - (j - preo[i - 1][0]) - k;
          int jj = j - preo[i - 1][0], kk = k - jj;
          int las = preo[i - 1][1] - kk;
          for (int c = 0; c <= std::min(las, cnt[j + 1]); ++c)
            inc(f[i][j + 1][k + c], 1ll * val * C[las][c] % kMod * C[cnt[j + 1]][c] % kMod * fac[c] % kMod);
            // inc(f[i][j + 1][k + c], val);
        }
      }
    } else {
      for (int j = 0; j <= i - 1; ++j) {
        for (int k = 0; k <= n; ++k) {
          if (!f[i - 1][j][k]) continue;
          int val = f[i - 1][j][k];
          int jj = j - preo[i - 1][0], kk = k - jj;
          int las = preo[i - 1][1] - kk;
          // i 录取
          inc(f[i][j][k], val);
          // i 不录取
          for (int c = 0; c <= std::min(las, cnt[j + 1]); ++c) {
            // inc(f[i][j + 1][k + c + 1], 1);
            inc(f[i][j + 1][k + c + 1], 1ll * val * C[las][c] % kMod * C[cnt[j + 1]][c] % kMod * fac[c] % kMod * std::max<int>(prec[j] - k, 0) % kMod);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= n - m; ++j) {
    for (int k = 0; k <= n; ++k) {
      if (!f[n][j][k]) continue;
      int val = f[n][j][k];
      // int las = preo[n][1] - (j - preo[n][0]) - k;

      int jj = j - preo[n][0], kk = k - jj;
      int las = preo[n][1] - kk;
      inc(ans, 1ll * val * C[prec[n] - prec[j]][las] % kMod * fac[las] % kMod * fac[tot0] % kMod);
      // std::cerr << las << ' ' << val << ' ' << j << ' ' << k << ' ' << prec[n] - prec[j] << ' ' << C[prec[n] - prec[j]][las] << '\n';
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  // std::cin >> T;
  while (T--) dickdreamer();
  // std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}