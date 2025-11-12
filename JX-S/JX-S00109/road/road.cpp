#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void read() {}
template<typename T, typename... U> void read(T &x, U&... arg) {
  x = 0; int f = 1; char ch = getchar();
  while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f; read(arg...);
}

void write() {}
template<typename T> void write(T x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}

template<typename T, typename U> void write(T x, U y) {
  write(x); putchar(y);
}

template<typename T> void chkmin(T &x, T y) { x = min(x, y); }
template<typename T> void chkmax(T &x, T y) { x = max(x, y); }

const int inf = 1e9 + 5;
const int M = 1e6 + 5;
const int N = 1e4 + 5;
const int K = 15;

#define int long long
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define adj(g, u, v) for (int _eid = g.head[u], v; v = g.ver[_eid], _eid; _eid = g.Next[_eid])

struct Edge { int u, v, w, id; } e[M + 10 * N], edge[20 * N];
int n, m, k, c[K], f[N + K], cnt, a[K], tot;
map<int, int> mp;
i64 ans;

bool cmp(Edge a, Edge b) { return a.w < b.w; }
void init() { rep(i, 1, n + k) f[i] = i; }
int get(int u) { return u == f[u] ? u : f[u] = get(f[u]); }

void dfs(int a, Edge *b) {
  if (mp[a]) return;
  i64 res = 0; init();
  rep(i, 0, k - 1) if (a >> i & 1) res += c[i + 1];
  rep(i, 1, cnt) {
    if (b[i].w == inf) continue;
    int u = b[i].u, v = b[i].v;
    int fu = get(u), fv = get(v);
    if (fu == fv) continue;
    f[fu] = fv, res += b[i].w;
  }
  mp[a] = 1;
  chkmin(ans, res);
  vector<int> tmp;
  rep(i, 0, k - 1) if (a >> i & 1) {
    a -= (1 << i);
    rep(j, 1, cnt) if (b[j].id == i + 1) tmp.push_back(b[j].w), b[j].w = inf;
    dfs(a, b);
    a += (1 << i); int it = 0;
    rep(j, 1, cnt) if (b[j].id == i + 1) b[j].w = tmp[it++];
  }
}

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  read(n, m, k);
  rep(i, 1, m) read(e[i].u, e[i].v, e[i].w);

  rep(i, 1, k) {
    read(c[i]);

    rep(j, 1, n) {
      read(edge[++cnt].w),
      edge[cnt].u = i + n,
      edge[cnt].v = j,
      edge[cnt].id = i;
    }
  }


  init();
  sort(e + 1, e + m + 1, cmp);

  rep(i, 1, m) {
    int u = e[i].u, v = e[i].v;
    int fu = get(u), fv = get(v);
    if (fu == fv) continue;
    f[fu] = fv, edge[++cnt] = e[i], ans += e[i].w;
  }

  if (k == 0) return write(ans), 0;

  sort(edge + 1, edge + cnt + 1, cmp);
  dfs((1 << k) - 1, edge);
  write(ans);
  return 0;
}
