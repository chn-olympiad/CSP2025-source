#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 5e6 + 5;
unordered_map<string, int> id;
string s[2][N], t[2][N];
int n, m, itot, res[N];
int lp[N], rp[N], lq[N], rq[N];
int sdl[N], sdr[N], qed[N];
struct BIT {
  int c[M];
  void upd(int x, int v) {
    for (++x; x < M; x += (x & -x)) {
      c[x] += v;
    }
  }
  int qry(int x) {
    int res = 0;
    for (++x; x; x -= (x & -x)) {
      res += c[x];
    }
    return res;
  }
} bit;
struct Trie {
  unordered_map<int, int> ch[26];
  int ed[N], tot = 1;
  int dfn[M], sz[M], dtot = 0;
  vector<int> edis[M], qry[M];
  void cls() {
    for (int i = 0; i < 26; ++i) {
      ch[i].clear();
    }
    for (int i = 0; i <= tot; ++i) {
      dfn[i] = sz[i] = 0;
      for (int x : edis[i]) {
        ed[x] = 0;
      }
      edis[i].clear();
      qry[i].clear();
    }
    dtot = 0;
    tot = 1;
  }
  void ins(string S, int x) {
    int u = 1;
    for (char c : S) {
      int &v = ch[c - 'a'][u];
      if (!v) v = ++tot;
      u = v;
    }
    edis[u].push_back(x);
    ed[x] = u;
  }
  int fnd(string S) {
    int u = 1;
    for (char c : S) {
      int v = ch[c - 'a'][u];
      if (!v) return u;
      u = v;
    }
    return u;
  }
  void dfs(int u) {
    dfn[u] = ++dtot;
    sz[u] = 1;
    for (int i = 0; i < 26; ++i) {
      int v = ch[i][u];
      if (!v) continue;
      dfs(v);
      sz[u] += sz[v];
    }
  }
  void merge(int u) {
    for (int x : edis[u]) {
      bit.upd(sdl[x], 1);
      bit.upd(sdr[x] + 1, -1);
    }
    for (int x : qry[u]) {
      res[x] = bit.qry(qed[x]);
    }
    for (int i = 0; i < 26; ++i) {
      int v = ch[i][u];
      if (v) merge(v);
    }
    for (int x : edis[u]) {
      bit.upd(sdl[x], -1);
      bit.upd(sdr[x] + 1, 1);
    }
  }
} tr;
struct Sub {
  vector<int> sid, qid;
  void solve() {
    for (int x : sid) {
      tr.ins(s[1][x], x);
    }
    tr.dfs(1);
    for (int x : sid) {
      int u = tr.ed[x];
      sdl[x] = tr.dfn[u];
      sdr[x] = sdl[x] + tr.sz[u] - 1;
    }
    for (int x : qid) {
      qed[x] = tr.dfn[tr.fnd(t[1][x])];
    }
    tr.cls();
    for (int x : sid) {
      tr.ins(s[0][x], x);
    }
    for (int x : qid) {
      tr.qry[tr.fnd(t[0][x])].push_back(x);
    }
    tr.merge(1);
  }
} sub[N];
signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios :: sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[0][i] >> s[1][i];
    if (s[0][i] == s[1][i]) continue;
    int l = s[0][i].size();
    for (int j = l - 1; j >= 0; --j) {
      if (s[0][i][j] != s[1][i][j]) lp[i] = j;
    }
    for (int j = 0; j < l; ++j) {
      if (s[0][i][j] != s[1][i][j]) rp[i] = j;
    }
    string T;
    for (int k = 0; k < 2; ++k) {
      for (int j = lp[i]; j <= rp[i]; ++j) {
        T = T + s[k][i][j];
      }
    }
    if (!id[T]) id[T] = ++itot;
    sub[id[T]].sid.push_back(i);
    string str0, str1;
    for (int j = lp[i] - 1; j >= 0; --j) str0 = str0 + s[0][i][j];
    for (int j = rp[i] + 1; j < l; ++j) str1 = str1 + s[0][i][j];
    s[0][i] = str0, s[1][i] = str1;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> t[0][i] >> t[1][i];
    int l = t[0][i].size();
    if (l != t[1][i].size()) continue;
    for (int j = l - 1; j >= 0; --j) {
      if (t[0][i][j] != t[1][i][j]) lq[i] = j;
    }
    for (int j = 0; j < l; ++j) {
      if (t[0][i][j] != t[1][i][j]) rq[i] = j;
    }
    string T;
    for (int k = 0; k < 2; ++k) {
      for (int j = lq[i]; j <= rq[i]; ++j) {
        T = T + t[k][i][j];
      }
    }
    if (!id[T]) continue;
    sub[id[T]].qid.push_back(i);
    string str0, str1;
    for (int j = lq[i] - 1; j >= 0; --j) str0 = str0 + t[0][i][j];
    for (int j = rq[i] + 1; j < l; ++j) str1 = str1 + t[1][i][j];
    t[0][i] = str0, t[1][i] = str1;
  }
  for (int i = 1; i <= itot; ++i) {
    if (sub[i].qid.size()) {
      sub[i].solve();
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << res[i] << '\n';
  }
  return 0;
}