#include <bits/stdc++.h>

namespace daiari {
  using ll = long long;
  const ll mod = 998'244'353;
  const int maxn = 505;
  int n, m, c[maxn], s[maxn];
  std::string S;

  namespace bruteforce {
    bool check() {
      return n <= 18;
    }
    const int maxm = 1 << 18;
    ll dp[maxm][19];
    void _(ll &a, ll b) {
      a += b;
      if (a >= mod) a -= mod;
    }
    void solve() {
      dp[0][0] = 1;
      int mx = 1 << n;
      for (int t = 0; t < mx - 1; ++t) {
        int d = __builtin_popcount(t) + 1;
        for (int i = 1; i <= n; ++i) {
          if (t >> (i - 1) & 1) continue; // if tested #i
          int t1 = t | (1 << (i - 1));
          for (int z = 0; z <= n; ++z) {
            bool success = s[d] && d - 1 - z < c[i]; // easy and didnt give up
            _(dp[t1][z + success], dp[t][z]);
            // std::clog << t1 << ' ' << z + success << " += " << t << ' ' << z << std::endl;
          }
        }
      }
      ll res = 0;
      for (int i = m; i <= n; ++i) res += dp[mx - 1][i];
      std::cout << res % mod << '\n';
    }
  }
  namespace m1 {
    bool check() { return m == 1; }
    ll fac[maxn];
    void solve() {
      fac[0] = 1;
      for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
      std::vector<int> p;
      for (int i = 1; i <= n; ++i) {
        if (s[i]) p.push_back(i);
      }
      ll cas = 1, res = 0;
      for (std::size_t i = 0; i < p.size(); ++i) {
        int k = p[i], l = 0;
        for (int j = 1; j <= n; ++j) if (c[j] >= k) ++l;
        res += cas * l % mod * fac[n - i - 1] % mod;
        cas = cas * (n - i - l) % mod;
      }
      std::cout << res % mod << '\n';
    }
  }
  namespace mn {
    bool check() { return m == n; }
    void solve() {
      bool flag = true; ll res = 1;
      for (int i = 1; i <= n; ++i) {
        res = res * i % mod;
        flag = flag && s[i] && c[i];
      }
      if (flag) std::cout << res << '\n';
      else std::cout << 0 << '\n';
    }
  }
  // namespace s18 {
  //   bool check() {
  //     int z = 0;
  //     for (int i = 1; i <= n; ++i) z += s[i];
  //     return z <= 18;
  //   }
  //   const int maxm = 1 << 18;
  //   std::vector<int> p;
  //   int k[18];
  //   ll res[maxm];
  //   ll fac[maxn];
  //   ll calc(int t) {
  //     for (int i = 1, j = 0, k0 = 0; i <= n; ++i) {
  //       if (s[i]) {
  //         if (t >> j & 1) k[j] = k0;
  //         else k[j] = 0, ++k0;
  //         ++j;
  //       } else ++k0;
  //     }
  //     std::sort(c + 1, c + 1 + n);
  //     ll r = 1;
  //     for (int i = p.size() - 1, j = n, d = 0; i >= 0; --i) {
  //       // int pos = p[i];
  //       if (!(t >> i & 1)) continue;
  //       while (j && c[j] > k[i]) --j;
  //       // std::clog << n << ' ' << j << ' ' << d << std::endl;
  //       r = r * (n - j - d) % mod;
  //       ++d;
  //     }
  //     return r * fac[n - __builtin_popcount(t)] % mod;
  //   }
  //   void solve() {
  //     fac[0] = 1;
  //     for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
  //     for (int i = 1; i <= n; ++i) if (s[i]) p.push_back(i);
  //     if (p.empty()) {
  //       std::cout << 0 << '\n';
  //       return;
  //     }
  //     int z = p.size(), mx = 1 << z;
  //     for (int t = 0; t < mx; ++t) {
  //       res[t] = calc(t);
  //       std::clog << res[t] << ' ';
  //     }
  //     std::clog << std::endl;
  //     ll Res = 0;
  //     for (int t = mx - 1; t >= 0; --t) {
  //       for (int u = (t + 1) | t; u < mx; u = (u + 1) | t) res[t] -= res[u];
  //       res[t] = (res[t] % mod + mod) % mod;
  //       if (__builtin_popcount(t) >= m) Res += res[t];
  //     }
  //     for (int t = 0; t < mx; ++t) {
  //       // res[t] = calc(t);
  //       std::clog << res[t] << ' ';
  //     }
  //     std::clog << std::endl;
  //     std::clog << "Run 3" << std::endl;
  //     std::cout << Res % mod << '\n';
  //   }
  // }
  // good. it's wrong.

#define S(x) if (x::check()) x::solve(); else
#define fallback bruteforce
  int main() {
    std::cin >> n >> m >> S;
    for (int i = 1; i <= n; ++i) std::cin >> c[i], s[i] = S[i - 1] == '1';

    S(bruteforce)
    S(m1)
    S(mn)
    // S(s18)
    fallback::solve();

    return 0;
  }
#undef S
}

int main() {
  using namespace std;
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  daiari::main();
  cout.flush();
  return 0;
}
