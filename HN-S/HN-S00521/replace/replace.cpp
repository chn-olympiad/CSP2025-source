#include <bits/stdc++.h>
#define rep(i, l, r) for (int i (l); i <= (r); ++ i)
#define rrp(i, l, r) for (int i (r); i >= (l); -- i)
#define eb emplace_back
#define pii pair <long long, long long>
#define ls (p << 1)
#define rs (ls | 1)
using namespace std;
constexpr int N = 5e6 + 5, M = 2e5 + 5, P = 1e9 + 9, Q = 998233853, B = 131; //注意模数
typedef long long ll;
inline int rd () {
  int x (0), f (1);
  char ch = getchar ();
  while (! isdigit (ch)) {
    if (ch == '-') f = -1;
    ch = getchar ();
  }
  while (isdigit (ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar ();
  } return x * f;
} //冷静
int qpow (int x, int y, int p) {
  int ret (1);
  for (; y; y >>= 1, x = x * x % p) if (y & 1) ret = ret * x % p;
  return ret;
}
map <pii, int> mp;
int n, q, tot, idx;
char s[N], t[N];
pii H[M];
int c[N][26];
int r1[M], r2[M];
int Rt[N];
int id1[M], id2[M];
vector <int> vec[M];
int Tot, iid[N];
int lc[M << 5], rc[M << 5], tag[M << 5];
void upd (int pre, int &p, int l, int r, int L, int R, int k) {
  p = ++ tot;
  lc[p] = lc[pre], rc[p] = rc[pre], tag[p] = tag[pre];
  // if (l >= 3 && r <= 4) cout<<L<<" : "<<R<<" "<<l<<" "<<r<<" "<<tag[p]<<endl; 
  if (L <= l && r <= R) return tag[p] += k, void ();
  int mid (l + r >> 1);
  if (L <= mid) upd (lc[pre], lc[p], l, mid, L, R, k);
  if (R > mid) upd (rc[pre], rc[p], mid + 1, r, L, R, k);
}
int qry (int p, int l, int r, int x) {
  // if (l >= 3 && r <= 4) cout<<l<<" "<<r<<" "<<tag[p]<<endl;
  if (l == r) return tag[p];
  int mid (l + r >> 1);
  if (x <= mid) return tag[p] + qry (lc[p], l, mid, x);
  return tag[p] + qry (rc[p], mid + 1, r, x);
}
int dfn[N], dfu[N];
void dfs1 (int u) {
  for (auto p : vec[iid[u]]) {
    upd (Rt[u], Rt[u], 1, N - 1, dfn[id2[p]], dfu[id2[p]], 1);
  }
  rep (i, 0, 25) {
    if (c[u][i]) {
      Rt[c[u][i]] = Rt[u];
      dfs1 (c[u][i]);
    }
  }
}
void dfs2 (int u) {
  dfn[u] = ++ idx;
  rep (i, 0, 25) if (c[u][i]) dfs2 (c[u][i]);
  dfu[u] = idx;
}
int32_t main () {
  freopen ("replace.in", "r", stdin);
  freopen ("replace.out", "w", stdout);
  n = rd (), q = rd ();
  rep (i, 1, n) {
    scanf ("%s", s + 1);
    scanf ("%s", t + 1);
    int len = strlen (s + 1); 
    int l (1), r (len);
    while (l <= len && s[l] == t[l]) ++ l;
    if (l == len + 1) continue;
    while (s[r] == t[r]) -- r;
    ll h1 (0), h2 (0);
    rep (i, l, r) h1 = (h1 * B + s[i] - 'a') % P, h2 = (h2 * B + t[i] - 'a') % P;
    H[i] = pii (h1, h2);
    if (mp.find (pii (h1, h2)) == mp.end ()) mp[pii (h1, h2)] = i;
    int id (mp[H[i]]);
    if (! r1[id]) r1[id] = ++ tot;
    if (! r2[id]) r2[id] = ++ tot;
    int p (r1[id]);
    rrp (i, 1, l - 1) {
      int o = s[i] - 'a';
      if (! c[p][o]) c[p][o] = ++ tot;
      p = c[p][o];
    }
    if (! iid[p]) iid[p] = ++ Tot;
    vec[iid[p]].eb (i);
    id1[i] = p;
    p = r2[id];
    rep (i, r + 1, len) {
      int o = s[i] - 'a';
      if (! c[p][o]) c[p][o] = ++ tot;
      p = c[p][o];
    }
    id2[i] = p;
    // cout<<id1[i]<<" "<<id2[i]<<endl;
  }
  tot = 0;
  for (auto p : mp) {
    int now = p.second;
    Rt[r1[now]] = ++ tot;
    dfs2 (r2[now]);
    dfs1 (r1[now]);
  }
  for (; q; -- q) {
    scanf ("%s", s + 1);
    scanf ("%s", t + 1);
    int len = strlen (s + 1);
    int l (1), r (len);
    while (s[l] == t[l]) ++ l;
    while (s[r] == t[r]) -- r;
    ll h1 (0), h2 (0);
    rep (i, l, r) h1 = (h1 * B + s[i] - 'a') % P, h2 = (h2 * B + t[i] - 'a') % P;
    if (mp.find (pii (h1, h2)) == mp.end ()) {
      puts ("0"); continue;
    }
    int id = mp[pii (h1, h2)];
    int p1 (r1[id]), p2 (r2[id]);
    rrp (i, 1, l - 1) {
      int o (s[i] - 'a');
      if (! c[p1][o]) break;
      p1 = c[p1][o];
    }
    rep (i, r + 1, len) {
      int o (s[i] - 'a');
      if (! c[p2][o]) break;
      p2 = c[p2][o];
    }
    printf ("%d\n", qry (Rt[p1], 1, N - 1, dfn[p2]));
  }
  cerr << 1.0 * clock () / CLOCKS_PER_SEC;
}