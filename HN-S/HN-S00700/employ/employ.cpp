#include<bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
using namespace std;
typedef long long LL;

const int N = 5e5 + 5, mod = 998244353;

int n, m, c[N], p[N], ans[N];
string s;

void work1() {
  rep (i, 1, n) p[i] = i;
  int ans = 0;
  do {
    int cnt = 0;
    rep (i, 1, n) {
      if (cnt >= c[p[i]] || s[i - 1] == '0') ++ cnt;
    }
    if (n - cnt >= m) ++ ans;
  } while (next_permutation(p + 1, p + 1 + n));
  cout << ans << '\n';
}

bool check() {
  bool flg = 1;
  rep (i, 1, n) flg &= (s[i - 1] == '1') ;
  return flg;
}

int cnt, pp[N];

void work2() {
  rep (i, 1, n) ++ pp[c[i]];
  int f = 1;
  rep (i, 0, n - 1) {
    cnt += pp[i];
    f = 1LL * f * max(0, cnt - 1) % mod;
    -- cnt;
  }
  int ans = 1;
  rep (i, 1, n) ans = 1LL * ans * i % mod;
  cout << (ans + mod - f) % mod << '\n';
}

void fakemain() {
  cin >> n >> m >> s;
  rep (i, 1, n) cin >> c[i];
  if (n <= 10) {
    work1();
  } else if (m == 1) {
    work2();
  }
}

void file(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
  cin.tie(0)->ios::sync_with_stdio(0), cout.tie(0);
  file("employ");
  int tc, T = 1;
  // cin >> tc >> T;
  while (T --) fakemain();
  cerr << 1. * clock() / CLOCKS_PER_SEC << "s\n";
}