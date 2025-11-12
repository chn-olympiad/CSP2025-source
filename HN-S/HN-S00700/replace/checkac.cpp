#include<bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
using namespace std;
typedef long long LL;

const int N = 2e5 + 5, L = 5e6 + 5;

struct AC {
  int tr[L][26], fa[N], tot = 1;
  int ins(string &s) {
    int u = 1;
    for (auto c : s) {
      int &v = tr[u][c - 'a'];
      if (v == 0) v = ++ tot; u = v;
    }
    return u;
  }
  void init() {
    queue<int> q;
    fa[1] = 0, q.push(1);
    rep (i, 0, 25) tr[0][i] = 1;
    while (q.size()) {
      int x = q.front(); q.pop();
      rep (i, 0, 25) {
        int &v = tr[x][i];
        if (v) {
          fa[v] = tr[fa[x]][i], q.push(v);
        } else {
          v = tr[fa[x]][i];
        }
      }
    }
    rep (i, 1, tot) cerr << fa[i] << " \n"[i == tot];
  }
} S1, S2;

int n, q, p1[N], p2[N];

void fakemain() {
  cin >> n;
  rep (i, 1, n) {
    string s; cin >> s, S1.ins(s);
  }
  S1.init();
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