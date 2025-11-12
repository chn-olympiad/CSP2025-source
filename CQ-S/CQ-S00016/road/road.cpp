#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define lb(x) (x&-x)

namespace rsy {
using namespace std;
using i64 = long long;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
void chmax (int &x, int c) { x = max(x, c); }
void chmin (int &x, int c) { x = min(x, c); }

const int maxn = 1e6 + 50, mod = 998244353;
namespace dsu {
	int p[maxn];
	void init(int N_) { L (i, 1, N_) p[i] = i; }
	int gf (int x) { return p[x] == x ? x : p[x] = gf(p[x]); }
	bool same (int x, int y) { return gf(x) == gf(y); }
	void merge (int x, int y) { int px = gf(x), py = gf(y); if (px != py) p[px] = py; }
}
int N, M, K, id = 0;
struct qwq { int u, v, w; } q[maxn], e[maxn];
int val[maxn], c[11][maxn], pos[11][maxn], now[11];
int p_i, g[11];

void solve() {
	cin >> N >> M >> K;
	L (i, 1, M) cin >> q[i].u >> q[i].v >> q[i].w;
	sort (q + 1, q + 1 + M, [](qwq i, qwq j){ return i.w < j.w; });
	dsu::init(N);
	L (i, 1, M) if (!dsu::same(q[i].u, q[i].v)) dsu::merge(q[i].u, q[i].v), e[++id] = q[i];
//	assert (id == N - 1);
	L (i, 1, K) {
		cin >> val[i], p_i = i;
		L (j, 1, N) cin >> c[i][j], pos[i][j] = j;
		sort (pos[i] + 1, pos[i] + N + 1, [](int x, int y){ return c[p_i][x] < c[p_i][y]; });
	}
	ll res = 1e18;
	L (S, 0, (1 << K) - 1) {
		int gid = 0; ll cnt = 0;
		L (i, 1, K) if (S >> (i - 1) & 1) g[++gid] = i, now[i] = 0, cnt += val[i];
		dsu::init(N + K);
		int tot = 0; bool F = 0;
		L (i, 1, N - 1) {
			L (j, 1, gid) {
				int x = g[j];
				while (now[x] + 1 <= N && c[x][pos[x][now[x] + 1]] <= e[i].w) {
					now[x]++;
					if (!dsu::same(x + N, pos[x][now[x]]))
						dsu::merge(x + N, pos[x][now[x]]), cnt += c[x][pos[x][now[x]]], tot++;
					if (cnt > res || tot == N + gid - 1) { F = 1; break; }
				}
				if (F == 1) break;
			}
			if (F == 1) break;
			if (!dsu::same(e[i].u, e[i].v)) dsu::merge(e[i].u, e[i].v), cnt += e[i].w, tot++;
			if (cnt > res || tot == N + gid - 1) break;
		}
//		if (cnt < res) { L (i, 1, N) assert (dsu::gf(i) == dsu::gf(1)); }
		res = min(res, cnt);
	}
	cout << res << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	while (T--) solve();
	return 0;
}
} signed main() {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	return rsy::main();
}
// 118 MB
