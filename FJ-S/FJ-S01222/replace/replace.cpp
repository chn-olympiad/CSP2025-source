#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define pb emplace_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

constexpr int N = 4e5 + 5, L = 5e6 + N * 5; // (5e6/2)

bool sm;

constexpr int P[2] {998244853, 998244353};
void doadd(int &x, int &y, int a, int b) {
  x = (x + a) % P[0];
  y = (y + b) % P[1];
}
//void dored(int &x, int &y, int a, int b) {
//  x = (x + P[0] - a) % P[0];
//  y = (y + P[1] - b) % P[1];
//}
void domul(int &x, int &y, int a, int b) {
  x = (1ll * x * a) % P[0];
  y = (1ll * y * b) % P[1];
}

int n, q, ans[N];
string PRE[N], SUF[N];
map<pair<int, int>, vector<int>> inq;
int pos[N];

struct bit {
  vector<int> tr;
  int n;
  void add(int x, int y) {
    for (; x <= n; x += x & -x) {
      tr[x] += y;
    }
  }
  int ask(int x) {
    int y = 0;
    for (; x; x -= x & -x) {
      y += tr[x];
    }
    return y;
  }
  void add(int l, int r, int v) {
    if (l > r) {
      return ;
    }
    add(l, v);
    add(r + 1, -v);
  }
  bit(int siz) : n(siz), tr(siz + 1) {
  }
  bit() {
  }
} B;

int dfn[L], ed[L], cntd;

struct TRIE {
  int son[L][26], tot;
  vector<int> vec[L];
  void ins(string &s, int p) {
    int fa = 0;
    for (auto c : s) {
      int &ch = son[fa][c - 'a'];
      if (!ch && (p > n)) {//如果往下没有对应的修改，那么提前 break，/2 
        break;
      }
      fa = ch ? ch : ch = ++tot;
    }
    vec[fa].pb(p);
  }
  void dfsdfn(int u) {
    dfn[u] = cntd + 1;
    if (sz(vec[u])) {
      ++cntd;
    }
    for (auto v : vec[u]) {
      pos[v] = u;
    }
    for (int i = 0; i < 26; ++i) {
      if (son[u][i]) {
        dfsdfn(son[u][i]);
      }
    }
    ed[u] = cntd;
  }
  void clear() {
//    while (tot >= 0) {
//      memset(son[tot], 0, sizeof son[tot]);
//      vec[tot].clear();
//      --tot;
//    }
//    tot = 0;
      memset(son[0], 0, sizeof son[0]);
      vec[0].clear();
  }
} T;

bool em;

void dfs(int u) {
  for (auto v : T.vec[u]) {
    if (v <= n) {
      B.add(dfn[pos[v]], ed[pos[v]], 1);
    }
  }
  for (auto v : T.vec[u]) {
    if (v > n) {
      ans[v - n] = B.ask(dfn[pos[v]]);
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (T.son[u][i]) {
      dfs(T.son[u][i]);
    }
  }
  for (auto v : T.vec[u]) {
    if (v <= n) {
      B.add(dfn[pos[v]], ed[pos[v]], -1);
    }
  }
}

void dolove() {
  for (auto &[dif, s] : inq) {
    if (sz(s) <= 1) {
      continue;
    }
#ifdef BRUTE
    for (auto u : s) {
      if (u <= n) {
        for (auto v : s) {
          if (v > n) {
            if (sz(PRE[v]) >= sz(PRE[u]) && sz(SUF[v]) >= sz(SUF[u])) {
              ans[v - n] += PRE[v].substr(0, sz(PRE[u])) == PRE[u] && SUF[v].substr(0, sz(SUF[u])) == SUF[u];
            }
          }
        }
      }
    }
    continue;
#endif
    T.clear();
    for (auto v : s) {
      if (v <= n) {
        T.ins(SUF[v], v);
      }
    }
    for (auto v : s) {
      if (v > n) {
        T.ins(SUF[v], v);
      }
    }
    cntd = 0;
    T.dfsdfn(0);
    B = bit(cntd);
    
    T.clear();
    for (auto v : s) {
      if (v <= n) {
        T.ins(PRE[v], v);
      }
    }
    for (auto v : s) {
      if (v > n) {
        T.ins(PRE[v], v);
      }
    }
    
    dfs(0);
  }
}

void prepare(int pos, bool o) {
  string s[2];
  cin >> s[0] >> s[1];
  if (sz(s[0]) != sz(s[1])) {
    return ;
  }
  int p = 0, q = sz(s[0]) - 1;
  while (p < sz(s[0]) && s[0][p] == s[1][p]) {
    ++p;
  }
  while (q >= 0 && s[0][q] == s[1][q]) {
    --q;
  }
  if (p <= q) {    
    int a0 = 0, b0 = 0;
    for (int i = p; i <= q; ++i) {
      domul(a0, b0, 1331, 13331);
      doadd(a0, b0, s[0][i], s[0][i]);
    }
    for (int i = p; i <= q; ++i) {
      domul(a0, b0, 1331, 13331);
      doadd(a0, b0, s[1][i], s[1][i]);
    }
    
    inq[{a0, b0}].pb(pos);
    PRE[pos] = s[0].substr(0, p);
    reverse(all(PRE[pos]));
    SUF[pos] = s[0].substr(q + 1);
  }else {
    assert(o);//0
  }
}

signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  clog << fixed << fabs(&sm - &em) / 1024 / 1024 << endl;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    prepare(i, true);
  }
  for (int i = 1; i <= q; ++i) {
    prepare(i + n, false);
  }
  dolove();
  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
