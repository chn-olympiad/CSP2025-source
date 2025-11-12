#include<bits/stdc++.h>
#include<bits/extc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
#define len(s) (int)s.size()
using namespace std;
typedef long long LL;
typedef unsigned long long UL;

const int N = 2e5 + 5, L = 5e6 + 5;
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

map<Hash2, int> id;

struct node {
  string s, t; Hash2 o;
} c[N], d[N];

bool work(string a, string b, node &res) {
  if (a.size() != b.size() || a == b) return 0;
  int l = 1e9, r = -1;
  rep (i, 0, len(a) - 1)
    if (a[i] != b[i]) {
      l = min(l, i), r = max(r, i);
    }
  rep (i, l, r) res.o.a = res.o.a + a[i], res.o.b = res.o.b + b[i];
  rep (i, 0, l - 1) res.s.push_back(a[i]);
  rep (i, r + 1, len(a) - 1) res.t.push_back(b[i]);
  reverse(res.t.begin(), res.t.end());
  return 1;
}

int ans[N], h_cnt;
vector<int> ss[N], qry[N];
vector<int> pos[L];
vector<pair<int, int>> qqq[L];

vector<int> g1[L], g2[L];

struct AC {
  int tr[L][26], fa[L], tot = 1;
  void clear() {
    rep (i, 1, tot) fa[i] = 0, memset(tr[i], 0, sizeof tr[i]);
    tot = 1;
  }
  int ins(string &s) {
    int u = 1;
    for (auto c : s) {
      int &v = tr[u][c - 'a'];
      if (v == 0) v = ++ tot; u = v;
    }
    return u;
  }
  int get(string &s) {
    int u = 1;
    for (auto c : s) {
      u = tr[u][c - 'a'];
    }
    return u;
  }
  void init(vector<int> g[L]) {
    // cerr << tot << '\n';
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
    rep (i, 1, tot) g[i].clear();
    rep (i, 2, tot) g[fa[i]].push_back(i);
  }
} S1, S2;

int dfn[L], dfn_cnt, out[L];

void dfs(int x) {
  dfn[x] = ++ dfn_cnt;
  for (auto y : g2[x]) dfs(y);
  out[x] = dfn_cnt;
}

struct bits {
  int c[L * 2], n;
  void init(int _n) {
    n = _n;
    // cerr << _n << '\n';
    rep (i, 1, n) c[i] = 0;
  }
  void add(int x, int v) {
    for (; x <= n; x += x & (-x)) c[x] += v;
  }
  void add(int l, int r, int v) {
    add(l, v), add(r + 1, -v);
  }
  int sum(int x) {
    int ans = 0;
    for (; x; x -= x & (-x)) ans += c[x];
    return ans;
  }
} bbb;

void dfs2(int x) {
  for (auto o : pos[x]) {
    bbb.add(dfn[o], out[o], 1);
    // cerr << "dfs2:" << x << ' ' << o << '\n';
  }
  for (auto [y, i] : qqq[x]) {
    ans[i] += bbb.sum(dfn[y]);
    // cerr << ans[i] << '\n';
  }
  for (auto y : g1[x]) dfs2(y);
  for (auto o : pos[x]) {
    bbb.add(dfn[o], out[o], -1);
  }
}

void work(vector<int> &qq, vector<int> &ss) {
  // cerr << "heige\n";
  int t = max(S1.tot, S2.tot);
  rep (i, 0, t) pos[i].clear(), qqq[i].clear();
  S1.clear(), S2.clear();
  for (auto i : ss) {
    auto &[s, t, _] = c[i];
    int u = S1.ins(s), v = S2.ins(t);
    if (u != 0 && v != 0) pos[u].push_back(v);
    // cerr << u << ' ' << v << '\n';
  }
  S1.init(g1), S2.init(g2);
  dfn_cnt = 0, dfs(1);
  bbb.init(S2.tot);
  for (auto i : qq) {
    int x = S1.get(d[i].s), y = S2.get(d[i].t);
    if (x != 0 && y != 0) qqq[x].emplace_back(y, i);
    // cerr << x << ' ' << y << ' ' << i << '\n';
  }
  dfs2(1);
  // cerr << "???\n";
}

void fakemain() {
  cin >> n >> q, nn = 1;
  rep (i, 1, n) {
    string a, b; cin >> a >> b;
    if (work(a, b, c[nn])) { 
      if (id.find(c[nn].o) == id.end()) {
        id[c[nn].o] = ++ h_cnt;
      }
      ss[id[c[nn].o]].push_back(nn);
      ++ nn;
    }
  }
  n = nn - 1;
  rep (i, 1, q) {
    string s, t; cin >> s >> t;
    if (work(s, t, d[i]) && id.find(d[i].o) != id.end()) {
      qry[id[d[i].o]].push_back(i);
    }
  }
  rep (i, 1, h_cnt) {
    work(qry[i], ss[i]);
  }
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