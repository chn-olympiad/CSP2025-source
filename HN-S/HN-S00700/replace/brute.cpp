#include<bits/stdc++.h>
#include<bits/extc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
#define len(s) (int)s.size()
using namespace std;
typedef long long LL;
typedef unsigned long long UL;

const int N = 2e5 + 5, L = 2.5e6 + 5;
const int m1 = 1e9 + 13, m2 = 1e9 + 91, b1 = 131, b2 = 191;

struct Hash {
  int h1, h2;
  Hash(int _a=0, int _b=0) : h1(_a), h2(_b) {}
  Hash operator+(int a) const {
    return {(1LL * h1 * b1 + a) % m1, (1LL * h2 * b2 + a) % m2};
  }
  bool operator==(const Hash &t) const {
    return h1 == t.h1 && h2 == t.h2;
  }
  bool operator<(const Hash &t) const {
    return h1 < t.h1 || (h1 == t.h1 && h2 < t.h2);
  }
  UL get() {
    return ((UL)h1 << 32) + h2;
  }
};

UL val(const Hash &t) { return ((UL)t.h1 << 32) + t.h2; }

struct Hash2 {
  Hash a, b;
  Hash2(Hash _a=Hash(), Hash _b = Hash()) : a(_a), b(_b) {}
  bool operator==(const Hash2 &t) const {
    return a == t.a && b == t.b;
  }
  bool operator<(const Hash2 &t) const {
    return a < t.a || (a == t.a && b < t.b);
  }
};

struct myhash {
  UL operator()(const Hash2 &t) const {
    return val(t.a) * b1 + val(t.b) * b2;
  };
};

int n, q, nn;

void fakemain() {
  cin >> n >> q, nn = 1;
  rep (i, 1, n) {
    string a, b; cin >> a >> b;
  }
  n = nn - 1;
  rep (i, 1, q) {
    string s, t; cin >> s >> t;
  }
  rep (i, 1, h_cnt) work(qry[i], ss[i]);
  rep (i, 1, q) cout << ans[i] << '\n';
}                 

void file(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
  cin.tie(0)->ios::sync_with_stdio(0), cout.tie(0);
  file("replace");
  int tc, T = 1;
  // cin >> tc >> T;
  while (T --) fakemain();
  cerr << 1. * clock() / CLOCKS_PER_SEC << "s\n";
}