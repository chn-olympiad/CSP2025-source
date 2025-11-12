#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL N = 1e3 + 10;
const LL M = 1e6 + 10;
LL n, m, K;
LL u, v, W;
LL ok[N][N];
LL G[N][N];
LL w[N];
LL c[15][N];
struct node {
	LL u, v, w;
	bool operator < (const node &o) const {
		return w < o.w;
	}
} b[M << 1];
LL cur;
LL res = 1e15;
LL fa[N];
LL find(LL x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(ok, 0x3f, sizeof(ok));
	cin >> n >> m >> K;
	for (LL i=1; i<=m; i++) {
		cin >> u >> v >> W;
		ok[u][v] = min(ok[u][v], W);
	}
	for (LL i=1; i<=K; i++) {
		cin >> w[i];
		for (LL j=1; j<=n; j++) {
			cin >> c[i][j];
		}
	}
	LL sum;
	LL cnt;
	for (LL S=0; S<(1<<K); ++S) {
		sum = 0;
		for (LL i=1; i<=n; ++i)
			for (LL j=1; j<=n; ++j)
				G[i][j] = ok[i][j]; 
		for (LL j=1; j<=K; ++j) {
			if (S & (1 << j-1)) {
				sum += w[j];
				for (LL k=1; k<=n; ++k) {
					for (LL l=k+1; l<=n; ++l) {
						G[k][l] = min(G[k][l], c[j][k] + c[j][l]);
					}
				}
			}
		}
		cur = 0;
		for (LL j=1; j<=n; ++j) {
			for (LL k=1; k<=n; ++k) {
				if (j == k)
					continue;
				if (G[j][k] <= 1000000000) {
					b[++cur] = {j, k, G[j][k]};
				}
			}
		}
		sort (b+1, b+cur+1);
		for (LL i=1; i<=n; i++)
			fa[i] = i;
		cnt = 0;
		for (LL i=1; i<=cur; i++) {
			u = find(b[i].u), v = find(b[i].v);
			if (u == v)
				continue;
			fa[u] = v;
			sum += b[i].w;
			++cnt;
			if (cnt == n-1)
				break;
		}
		res = min(res, sum);
	}
	cout << res << '\n';
	return 0;
}
