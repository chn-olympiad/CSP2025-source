#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define pb emplace_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

constexpr int P = 998244353;
struct Z {
  int x;
  Z() : x(0) {}
  Z(LL t) : x(t % P) {}
  // + (t < 0 ? P : 0)) {}
};
inline Z operator + (Z a, const Z& b) {
  ((a.x += b.x) >= P) ? (a.x -= P) : 0;
  return a;
}
//inline Z operator - (Z a, const Z& b) {
//  ((a.x -= b.x) < P) ? (a.x += P) : 0;
//  return a;
//}
inline Z operator * (Z a, const Z& b) {
  return Z(1ll * a.x * b.x);
}
inline Z& operator += (Z &a, const Z& b) {
  ((a.x += b.x) >= P) ? (a.x -= P) : 0;
  return a;
}
//inline Z& operator -= (Z &a, const Z& b) {
//  ((a.x -= b.x) < P) ? (a.x += P) : 0;
//  return a;
//}
inline Z& operator *= (Z &a, const Z& b) {
  return a = a * b, a;
}
ostream& operator << (ostream &a, Z b) {
  return a << b.x;
}
Z qpow(Z a, int b = P - 2) {
  Z t = 1;
  for (; b; b >>= 1, a *= a) {
    if (b & 1) {
      t *= a;
    }
  }
  return t;
}

bool sm;

constexpr int N = 505;
int n, m;
string s;
int ct[N], sum[N];

Z dp[2][N][N], g[N][N], fac[N];

bool em;

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  clog << fixed << fabs(&sm - &em) / 1024 / 1024 << endl;
  cin >> n >> m >> s;
  s = "#" + s;
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = i * fac[i - 1];
  }
  
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> c; 
    ++ct[c];
  }
  sum[0] = ct[0];//c_i ¿ÉÄÜÎª 0 
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + ct[i];
  }

#define F dp[fl]
#define G dp[!fl]
  bool fl = true;
  F[0][0] = 1;
  for (int i = 0; i < n; ++i) {//i -> i+1
    fl ^= 1;
    for (int refuse = 0; refuse <= i; ++refuse) {
      for (int blanks = 0; blanks <= i && blanks <= n - sum[refuse]; ++blanks) {
        int no_use = sum[refuse] - (i - blanks);//c_i<=refuse 
        auto &val = G[refuse][blanks];
        if (!val.x) {
          continue;
        }
        if (s[i + 1] == '0') {
          //c_i <= refuse / c_i > refuse
          g[refuse + 1][blanks + 1] += val;
          if (no_use > 0) {
            g[refuse + 1][blanks] += val * no_use;
          }
        }else {
          //c_i <= refuse
          if (no_use > 0) {
            g[refuse + 1][blanks] += val * no_use;
          }
          //c_i > refuse
          F[refuse][blanks + 1] += val;
        }
        val = 0;
      }
    }
    for (int refuse = 1; refuse <= i + 1; ++refuse) {
      for (int rounds = 1; rounds <= ct[refuse]; ++rounds) {
        for (int blanks = 0; blanks <= i + 1 && blanks <= n - sum[refuse - 1] - (rounds - 1); ++blanks) {
          if (blanks) {
            g[refuse][blanks - 1] += g[refuse][blanks] * blanks;
          }
        }
      }
      for (int blanks = 0; blanks <= i + 1; ++blanks) {
        F[refuse][blanks] += g[refuse][blanks];
        g[refuse][blanks] = 0;
      }
    }
  }
  Z ans = 0;
  for (int i = 0; i <= n - m; ++i) {
    for (int blanks = 0; blanks <= n; ++blanks) {
      if (blanks == sum[n] - sum[i]) {
        ans += fac[blanks] * F[i][blanks];
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
