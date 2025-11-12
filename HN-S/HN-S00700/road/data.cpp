#include<bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
using namespace std;
typedef long long LL;
mt19937 rnd(random_device{}());

const int N = 5e5 + 5;

int n = 1e4, m = 1e6, k = 10, V = 1e9;

void fakemain() {
  cout << n << ' ' << m << ' ' << k << '\n';
  rep (i, 1, m) {
    cout << rnd() % n + 1 << ' ' << rnd() % n + 1 << ' ' << rnd() % V + 1 << '\n';
  }
  rep (i, 1, k) {
    rep (j, 1, n + 1) cout << rnd() % V + 1 << " \n"[j == n + 1];
  }
}

void file(string s) {
  // freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".in").c_str(), "w", stdout);
}

signed main() {
  cin.tie(0)->ios::sync_with_stdio(0), cout.tie(0);
  file("road");
  int tc, T = 1;
  // cin >> tc >> T;
  while (T --) fakemain();
  cerr << 1. * clock() / CLOCKS_PER_SEC << "s\n";
}