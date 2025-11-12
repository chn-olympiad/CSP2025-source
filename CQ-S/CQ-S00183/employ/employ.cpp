#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define U(i, a, b) for (int i = (a); i <= (b); i++)
#define drep(i, a, b) for (int i = (a); i >= b; i--)
#define pii pair<ll, ll>
#define fi first
#define se second
#define ld lower_bound
#define ud upper_bound
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define fv inline void
#define fn inline static
#define mem(s, k) memset(s, k, sizeof(s))
using i32 = ll; using i64 = ll; using i128 = __int128;
using u32 = unsigned int; using u64 = unsigned ll;
using namespace std;
const i32 N = 5e2 + 5, mod = 998244353;
i32 n, m, c[N], cnt[N], cnt1[N], f[2][N][N], fac[N], ifac[N], b[N][N];
string s;
fn i32 qkpow(i32 a, i32 b) {
  i32 ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans;
}
fn i32 C(i32 n, i32 m) { 
  return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
fv inc(i32 &x, i32 y) { x = (x + y >= mod ? x + y - mod : x + y); }
fv sol() {
  cin >> n >> m >> s, s = " " + s;
  i32 mn = n + 1; fac[0] = ifac[0] = 1;
  rep (i, 1, n) cin >> c[i], cnt[c[i]]++, mn = min(mn, c[i]);
  rep (i, 1, n) fac[i] = fac[i - 1] * i % mod, ifac[i] = qkpow(fac[i], mod - 2);
  cnt1[0] = cnt[0];
  rep (i, 1, n) cnt1[i] = cnt1[i - 1] + cnt[i];
  i32 tnum = 0;
  f[0][0][0] = 1;
  rep (i, 0, n) rep (j, 0, i) b[i][j] = C(i, j);
  i32 o = 1;
  U (i, 0, n) {
    mem(f[o], 0);
    if (s[i + 1] == '1') {
      rep (j, 0, n - m) {
        rep (k, 0, i) {
          if (cnt1[j] - (i - k) <= 0 || !f[o ^ 1][j][k]) continue;
          i32 res = f[o ^ 1][j][k] * (cnt1[j] - (i - k)) % mod;
          rep (x, 0, min(cnt[j + 1], (ll)i)) {
              tnum++;
              inc(f[o][j + 1][k - x], res * b[cnt[j + 1]][x] % mod * b[k][x] % mod * fac[x] % mod);
//              cerr << i + 1 << " " << j + 1 << " " << k - x << " trans from " << i << " " << j << " " << k << " : " << (cnt1[j] - (i - k)) % mod * C(cnt[j + 1], x) % mod * C(k, x) % mod * fac[x] % mod << "\n";
          }
          inc(f[o][j][k + 1], f[o ^ 1][j][k]);
//          cerr << i + 1 << " " << j << " " << k + 1 << " trans2 from " << i << " " << j << " " << k << "\n";
        }
      }
      
    } else {
      rep (j, 0, n - m) {
        rep (k, 0, i) {
          if (cnt1[j] - (i - k) <= 0 || !f[o ^ 1][j][k]) continue;
          i32 res = f[o ^ 1][j][k] * (cnt1[j] - (i - k)) % mod;
          rep (x, 0, min(cnt[j + 1], (ll)k)) {
            tnum++;
            inc(f[o][j + 1][k - x], res * b[cnt[j + 1]][x] % mod * b[k][x] % mod * fac[x] % mod);
          }
        }
      }
      rep (j, 0, n - m) {
        rep (k, 0, i) {
          if (!f[o ^ 1][j][k]) continue;
          rep (x, 0, min(cnt[j + 1], k + 1ll)) {
            tnum++;
            inc(f[o][j + 1][k + 1 - x], f[o ^ 1][j][k] * b[cnt[j + 1]][x] % mod * b[k + 1][x] % mod * fac[x] % mod);
          }
        }
      }
    }
    o ^= 1;
  }
  i32 ans = 0;
  rep (j, 0, n) {
    rep (k, 0, n) {
      if (n - j >= m && n - cnt1[j] == k) {
        inc(ans, f[o][j][k] * fac[k] % mod);
      }
    }
//    cerr << "\n";
  }
  cout << ans << "\n";
}
int main() {
//  freopen("employ.in", "r", stdin);
//  freopen("employ.out", "w", stdout);
  IOS;
  i32 T = 1;
//  cin >> T;
  while (T--) sol();
}
