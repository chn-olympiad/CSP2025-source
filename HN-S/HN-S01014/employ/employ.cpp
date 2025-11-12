#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define sz(x) (int)(x).size()
using ll = long long;

const int N = 510, mod = 998244353;
int n, m, cnt[N], pre[N];
bool s[N];

int c[N][N], p[N][N];

void math(int n) {
  rep(i, 0, n) {
    c[i][0] = 1;
    rep(j, 1, i) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  rep(i, 0, n) {
    p[i][0] = 1;
    rep(j, 1, i) p[i][j] = (ll)p[i][j - 1] * (i - j + 1) % mod;
  }
}

inline void add(int &a, ll b) { a = (a + b) % mod; }

int f[2][N][N];

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  {
    string s0;
    cin >> s0, s0 = " " + s0;
    rep(i, 1, n) s[i] = s0[i] - '0';
  }
  rep(i, 1, n) {
    int x;
    cin >> x;
    ++cnt[x];
  }
  pre[0] = cnt[0];
  rep(i, 1, n) pre[i] = pre[i - 1] + cnt[i];
  math(n);
  int o = 0;
  f[o][0][0] = 1;
  rep(i, 0, n - 1) {
    o ^= 1, memset(f[o], 0, sizeof f[o]);
    rep(j, 0, i)
      rep(k, 0, min(i, n - pre[i - j])) {
        int val = f[o ^ 1][j][k];
        if(!val) continue;
        rep(l, 0, min(k + 1, cnt[i - j + 1])) {
          if(l <= k)
            add(f[o][j][k - l], (ll)val * p[cnt[i - j + 1]][l] % mod * (pre[i - j] - (i - k)) % mod * c[k][l]);
          if(!s[i + 1])
            add(f[o][j][k + 1 - l], (ll)val * p[cnt[i - j + 1]][l] % mod * c[k + 1][l]);
        }
        if(s[i + 1]) add(f[o][j + 1][k + 1], val);
      }
    // rep(j, 0, i + 1)
    //   rep(k, 0, i + 1)
    //     if(f[o][j][k]) cerr << "f[" << i + 1 << "][" << j << "][" << k << "] = " << f[o][j][k] << "\n";
  }
  int ans = 0;
  rep(j, m, n)
    rep(k, 0, n) add(ans, (ll)f[o][j][k] * p[n - pre[n - j]][k]);
  cout << ans << "\n";
}