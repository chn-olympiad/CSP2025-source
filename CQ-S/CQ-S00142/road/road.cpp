#include <bits/stdc++.h>

using namespace std;

using ll = long long; using ull = unsigned long long;
#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)

using u32 = unsigned;
namespace Main {

const u32 IOSIZE = (1 << 16);
char ibuf[IOSIZE], *iS = ibuf, *iT = ibuf;
// #define gc getchar
inline char gc() { return ((iS == iT) && (iT = (iS = ibuf) + fread(ibuf, 1, IOSIZE, stdin)), iS == iT ? EOF : *iS++);}

template<class T>
inline void read(T&x) {
  x = 0; char c = gc(); while(!(47 < c && c < 58)) c = gc();
  while(47 < c && c < 58) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
}

// #define pct __builtin_popcount
  const u32 N = 1e4 + 5 + 10, M = 1e6 + 5;
  int n, m, K;
  struct edge {
    u32 u, v, w;
  } e[M], Ans[N];
  inline bool cmp(const edge &x, const edge&y) { return x.w < y.w; }
  u32 fa[N], sz[N]; inline u32 find(u32 x) { while(x != fa[x]) x = fa[x] = fa[fa[x]]; return x; }
  int cur;
  inline void solve(int E) {
    cur = 0;
    stable_sort(e + 1, e + 1 + E, cmp);
    REP(i, 1, n + K) fa[i] = i, sz[i] = (i <= n);
    REP(i, 1, E) {
      u32 u = find(e[i].u), v = find(e[i].v);
      if(u == v) continue;
      if(sz[v] > sz[u]) swap(u, v);
      fa[v] = u; sz[u] += sz[v]; Ans[++cur] = e[i];
      if(int(sz[u]) == n) {
        return;
      }
    }
  }
  edge a[1 << 10][N]; int len[1 << 10];
  ll res[1 << 10];
  ll sum[1 << 10];
  u32 g[N];
	int main() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

    // cin >> n >> m >> K;
    read(n), read(m), read(K);
    REP(i, 1, m) {
      read(e[i].u), read(e[i].v), read(e[i].w);
      // cin >> e[i].u >> e[i].v >> e[i].w;
    }
    solve(m);
    REP(i, 1, cur) a[0][i] = Ans[i], res[0] += Ans[i].w;
    len[0] = cur;
    REP(z, 0, K - 1) {
      u32 val;
      read(val);
      // cin >> val;
      REP(i, 1, n) {
        // cin >> g[i];
        read(g[i]);
      }
      // 1<<z
      u32 X = 1 << z;
      REP(s, (1 << z), (1 << (z + 1)) - 1)  {
        REP(i, 1, len[s ^ X]) e[i] = a[s ^ X][i];
        int E = len[s ^ X]; u32 mx = a[s ^ X][len[s ^ X]].w;
        REP(i, 1, n) if(g[i] < mx) e[++E] = (edge){u32(z + n + 1), u32(i), g[i]};
        solve(E);
        REP(i, 1, cur) a[s][i] = Ans[i], res[s] += Ans[i].w;
        len[s] = cur;
        
        sum[s] = sum[s ^ X] + val;
        // assert(len[s] <= n + pct(s) - 1);
      }
    }
    ll ans = 9e18;
    REP(i, 0, (1 << K) - 1) ans = min(ans, sum[i] + res[i]);
    cout << ans << '\n';
		return 0;
	}
}

int main() {
  double S = clock();
#ifndef Ace
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif
	Main::main();
  double T = clock();
  cerr << (T - S) / CLOCKS_PER_SEC << '\n';
  // while(1);
	return 0;
} 
// Think TWICE, code ONCE
/*
Meb:138mb
加边 MST -> LCT / 暴力
m log m + 2^k n log n
*/