#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++) 
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define int long long
#define RD read()
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
  while('0' <= ch && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
  return x * f;
}

int const N = 1e4 + 5, M = 1e6 + 5, inf = 1e16;

int n, m, kn;
struct edge { int u, v, w; } e[M], b[N], now[N * 20];
int cnt, tot;
bool cmp(edge a, edge b) { return a.w < b.w; }

int fa[N];
int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

int a[12][N], c[N];

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);

  n = RD, m = RD, kn = RD;
  rep(i, 1, n) fa[i] = i;
  rep(i, 1, m) {
    int u = RD, v = RD, w = RD;
    e[i] = {u, v, w};
  }
  sort(e + 1, e + 1 + m, cmp);
  rep(i, 1, m) {
    int u = e[i].u, v = e[i].v;
    int x = find(u), y = find(v);
    if(x == y) continue;
    fa[x] = y;
    b[++ cnt] = e[i];
  }
  assert(cnt == n - 1);

  rep(i, 1, kn) {
    c[i] = RD;
    rep(j, 1, n) a[i][j] = RD;
  }

  int ans = inf;
  rep(s, 0, (1 << kn) - 1) {
    int res = 0;
    tot = cnt;
    rep(i, 1, tot) now[i] = b[i];
    rep(i, 1, kn) if(s >> (i - 1) & 1ll) {
      res += c[i];
      rep(j, 1, n) {
        now[++ tot] = {n + i, j, a[i][j]};
      }
    }
    sort(now + 1, now + 1 + tot, cmp);
    // rep(i, 1, tot) printf("(%lld, %lld, %lld)\n", now[i].u, now[i].v, now[i].w);
    rep(i, 1, n + kn) fa[i] = i;
    rep(i, 1, tot) {
      int u = now[i].u, v = now[i].v;
      int x = find(u), y = find(v);
      if(x == y) continue;
      res += now[i].w;
      fa[x] = y;
    }
    ans = min(ans, res);
    // printf("s = %lld, res = %lld\n", s, res);
  }
  printf("%lld\n", ans);

  return 0;
}