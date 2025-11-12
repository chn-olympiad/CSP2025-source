#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define U(i, a, b) for (int i = (a); i <= (b); i++)
#define drep(i, a, b) for (int i = (a); i >= b; i--)
#define pii pair<ll, ll>
#define fi first
#define se second
#define ld lower_bound
#define ud upper_bound
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define fv inline void
#define fn inline static
using i32 = int; using i64 = ll; using i128 = __int128;
using u32 = unsigned int; using u64 = unsigned ll;
using namespace std;
bool bg;
const i32 N = 2e5, M = 1.5e6 + 5;
const i64 inf = 1e16;
struct node {
  i32 u, v, w;
  friend bool operator < (node a, node b) {
    return a.w < b.w;
  }
} t[M], t1[M];
i32 n, m, k, w, num, cnt, fa[N], dep[N], c[N], a[12][N];
bool vis[N];
fn i32 get(i32 u) { return fa[u] == u ? u : fa[u] = get(fa[u]); }
fn i32 read() {
  i32 x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}
fv sol() {
  cin >> n >> m >> k;
  iota(fa, fa + n + 1, 0); 
  rep (i, 1, m) cin >> t[i].u >> t[i].v >> t[i].w;
//  cerr << "---\n";
  sort(t + 1, t + m + 1);
  rep (i, 1, m) {
    i32 u = get(t[i].u), v = get(t[i].v);
    if (u == v) continue;
    fa[u] = v, t1[++num] = t[i];
  }
  m = num;
  rep (i, 1, m) t[i] = t1[i];
  rep (i, 1, k) {
    cin >> c[i];
    rep (j, 1, n) cin >> a[i][j], t[++m] = {n + i, j, a[i][j]};
  }
  sort(t + 1, t + m + 1);
//  exit(0);
  rep (i, 1, n) vis[i] = 1;
//  cerr << "---\n";
  i64 ans = inf, cnt = 0;
  U (S, 0, (1 << k)) {
    i64 sum = 0;
    iota(fa, fa + n + k + 1, 0);
    fill(dep, dep + n + k + 1, 1);
    i32 num = n;
    rep (i, 1, k) vis[n + i] = 0;
    rep (i, 1, k) if ((S >> (i - 1)) & 1) sum += c[i], vis[n + i] = 1, num++;
    i32 res = 0;
    rep (i, 1, m) {
      if (!vis[t[i].u]) continue;
//      i32 u = 0, v = 0;
      i32 u = get(t[i].u), v = get(t[i].v);
      if (u == v) continue;
      sum += t[i].w;
      if (dep[u] > dep[v]) swap(u, v);
      fa[u] = v, dep[v] += (dep[u] == dep[v]);
      res++;
      if (res == num - 1) break;
    }
    ans = min(ans, sum);
  }
//  cerr << cnt << "\n";
  cout << ans << "\n";
}
bool ed;
int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  IOS;
  i32 T = 1;
//  cin >> T;
  while (T--) sol();
}
