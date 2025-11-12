#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;
int n, m, k, head[N], nxt[M<<1], to[M<<1], val[M<<1], ca[15][N], fa[N], c[N], tot, tot1;
void add(int x, int y, int z) {
	to[++tot1] = y;
	val[tot1] = z;
	nxt[tot1] = head[x];
	head[x] = tot1;
}
struct Node {
	int u, v, w;
	bool operator < (const Node& z)const {
		return w < z.w;
	}
} e[M<<1];
int Find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int x, y, z, i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		e[++tot] = (Node){x, y, z};
	}
	if (k == 0) {
		int cnt = 0;
		long long ans = 0;
		sort(e+1, e+tot+1);
		for (int i = 1; i <= tot; i++) {
			int fx = Find(e[i].u), fy = Find(e[i].v);
			if (fx != fy) {
				fa[fx] = fy;
				++cnt;
				ans += e[i].w;
				if (cnt == n-1) break;
			}
		}
		cout << ans;
	} else {
		for (int i = 1; i <= k; i++) {
			fa[n+i] = n+i;
		}
		for (int i = 1; i <= k; i++) {
			scanf("%d", &c[i]);
			for (int id, j = 1; j <= n; j++) {
				scanf("%d", &id);
				ca[i][j] = id;
				e[++tot] = (Node){n+i, j, id};
			}
		}
		int cnt = 0;
		long long ans = 0;
		sort(e+1, e+tot+1);
		for (int i = 1; i <= tot; i++) {
			int fx = Find(e[i].u), fy = Find(e[i].v);
			if (fx != fy) {
				fa[fx] = fy;
				++cnt;
				ans += e[i].w;
				add(fx, fy, e[i].w);
				add(fy, fx, e[i].w);
				if (cnt == n+k-1) break;
			}
		}
		for (int i = 1; i <= k; i++) {
			int now = n + i;
			int cnt = 0;
			long long tmp = 0;
			for (int j = head[now]; j; j = nxt[j]) {
				++cnt;
				tmp += val[j];
			}
			if (cnt == 1) ans -= tmp;
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
