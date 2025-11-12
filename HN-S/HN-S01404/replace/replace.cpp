#include <bits/stdc++.h>
#define file_in(x) (freopen(#x".in", "r", stdin))
#define file_out(x) (freopen(#x".out", "w", stdout))
#define ll long long
#define vi vector
#define pb push_back
#define lb(x) (x & (-x))
#define pc(x) (__builtin_popcount(x))

using namespace std;

char _c; bool _f; template <class T> void IN(T & x) {
  _f = x = 0; while (_c = getchar(), !isdigit(_c)) {if (_c == '-') _f = 1;}
  while (isdigit(_c)) {x = x * 10 + _c - '0', _c = getchar();} if (_f) x = -x;
}

template <class T> void _write(T x) {
  if (x < 0) return putchar('-'), _write(-x);
  if (x > 9) _write(x / 10);
  putchar('0' + (x % 10));
}
template <class T> void write_s(T x) {_write(x), putchar(' ');}
template <class T> void write(T x) {_write(x), putchar('\n');}
template <class first, class... rest> void write(first fir, rest... res) {
  write_s(fir), write(res...);
}

#define debug(...) (_debug(#__VA_ARGS__, __VA_ARGS__))
template <class T> void _debug(const char * format, T x) {
  cerr << format << " = " << x << endl;
}
template <class first, class... rest>
void _debug(const char * format, first fir, rest... res) {
  while (*format != ',') cerr << *format++;
  cerr << " = " << fir << ',', _debug(format + 1, res...);
}

bool START;

const int N = 4e5 + 5, M = 2.5e6 + 5;
const int inf = 1e9;

int n, q, id[N][2], cnt;
char s0[M << 1], s1[M << 1];
ll ans[N];

struct acam {
  int tr[M][26], fa[M], idx = 1;
  int hd[M], nxt[M], to[M], tot;
  int dfn[M], sz[M], num;
  int sn[M], tp[M], dy[M];
  int L[M];
  
  int ins(char * s) {
    int p = 1, len = strlen(s + 1);
    for (int i = 1; i <= len; ++i) {
      int c = s[i] - 'a';
      if (!tr[p][c]) tr[p][c] = ++idx, L[idx] = L[p] + 1;
      p = tr[p][c];
    }
    return p;
  }
  void add_e(int x, int y) {
    tot++, nxt[tot] = hd[x], hd[x] = tot, to[tot] = y;
  }
  void dfs(int x) {
    sz[x] = 1;
    for (int i = hd[x]; i; i = nxt[i]) {
      dfs(to[i]), sz[x] += sz[to[i]];
      if (sz[to[i]] > sz[sn[x]]) sn[x] = to[i];
    }
  }
  void dfs2(int x, int TP) {
    dfn[x] = ++num, dy[num] = x, tp[x] = TP;
    if (sn[x]) dfs2(sn[x], TP);
    for (int i = hd[x]; i; i = nxt[i])
      if (to[i] != sn[x]) dfs2(to[i], to[i]);
  }
  void bld() {
    queue <int> q;
    for (int i = 0; i < 26; ++i) {
      if (tr[1][i]) fa[tr[1][i]] = 1, q.push(tr[1][i]);
      else tr[1][i] = 1;
    }
    while (!q.empty()) {
      int x = q.front(); q.pop();
      for (int i = 0; i < 26; ++i) {
	if (!tr[x][i]) tr[x][i] = tr[fa[x]][i];
	else fa[tr[x][i]] = tr[fa[x]][i], q.push(tr[x][i]);
      }
    }
    for (int i = 2; i <= idx; ++i) add_e(fa[i], i);
    dfs(1), dfs2(1, 1);
  }
  int jp(int x, int lim) { // L <= lim
    if (L[x] <= lim) return x;
    while (x) {
      if (L[tp[x]] > lim) x = fa[tp[x]];
      else break;
    }
    int l = dfn[tp[x]], r = dfn[x], p = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (L[dy[mid]] <= lim) p = dy[mid], l = mid + 1;
      else r = mid - 1;
    }
    return p;
  }
} t0, t1;

struct qry {
  int x, y, op, id;
  bool operator < (const qry & o) const {return x < o.x;}
} c[M << 1];

int T;
 
struct opt {
  int x, l, r, v;
  bool operator < (const opt & o) const {return x < o.x;}
} tmp[N << 1];

namespace bit {
  int c[M];
  void add(int x, int k) {for (; x <= t1.num; x += lb(x)) c[x] += k;}
  int ask(int x) {int s = 0; for (; x; x -= lb(x)) s += c[x]; return s;}
}

bool END;

signed main() {
  file_in(replace), file_out(replace);
  IN(n), IN(q);
  for (int i = 1; i <= n; ++i) {
    scanf(" %s", s0 + 1), id[i][0] = t0.ins(s0);
    scanf(" %s", s1 + 1), id[i][1] = t1.ins(s1);
  }

  t0.bld(), t1.bld();

  for (int i = 1; i <= n; ++i) {
    int i0 = id[i][0], i1 = id[i][1];
    int l = t0.dfn[i0], r = t0.dfn[i0] + t0.sz[i0] - 1;
    int L = t1.dfn[i1], R = t1.dfn[i1] + t1.sz[i1] - 1;
    tmp[++T] = {l, L, R, 1}, tmp[++T] = {r + 1, L, R, -1};
  }

  int S = 0;

  for (int id = 1; id <= q; ++id) {
    scanf(" %s", s0 + 1), scanf(" %s", s1 + 1);
    if ((int)strlen(s0 + 1) != (int)strlen(s1 + 1)) {
      continue;
    }

    S += strlen(s0 + 1);
    
    int p0 = 1, p1 = 1, sz = strlen(s1 + 1);

    int lp = inf, rp = 0;
    for (int i = 1; i <= sz; ++i)
      if (s0[i] != s1[i]) {
	lp = min(lp, i);
	rp = max(rp, i);
      }
    
    for (int i = 1; i <= sz; ++i) {
      p0 = t0.tr[p0][s0[i] - 'a'], p1 = t1.tr[p1][s1[i] - 'a'];
      if (i >= rp) {
	int lim = i - lp + 1;
	if (t0.L[p0] < lim || t1.L[p1] < lim)
	  continue;
	
	int pos = t0.jp(p0, lim - 1);
	c[++cnt] = {t0.dfn[p0], t1.dfn[p1], 1, id};
	if (pos) c[++cnt] = {t0.dfn[pos], t1.dfn[p1], -1, id};
      }
    }
  }

  
  sort(c + 1, c + 1 + cnt);
  sort(tmp + 1, tmp + 1 + T);

  for (int i = 1, j = 1; i <= cnt; ++i) {
    while (j <= T && tmp[j].x <= c[i].x) {
      bit :: add(tmp[j].l, tmp[j].v), bit :: add(tmp[j].r + 1, -tmp[j].v);
      j++;
    }
    ans[c[i].id] += c[i].op * bit :: ask(c[i].y);
  }
  for (int i = 1; i <= q; ++i) write(ans[i]);
  return 0;
}
/*
1 1
aa bb
aaaa bbbb

 */
