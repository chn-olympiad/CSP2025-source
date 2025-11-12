#include <bits/stdc++.h>
using namespace std;

using i64 = unsigned long long;
#define sr cin
#define sw cout
#define sendl '\n'
#define seia cout.flush();return 0

struct egd {
	int u, v, w;
} ed[1000010];

bool cmp(egd x, egd y) {
	return x.w < y.w;
}

vector<egd> G[110];
vector<int> org;
int temp[110], cur[110];

int fa[20010], c[110];

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

int main() {
	ios::sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	// int t = clock();
	int n, m, k;
	sr >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		sr >> ed[i].u >> ed[i].v >> ed[i].w;
	}
	for (int i = 1; i <= k; i++) {
		sr >> c[i];
		for (int j = 1; j <= n; j++) {
			int w;
			sr >> w;
			G[i].push_back({n + i, j, w});
		}
		sort(G[i].begin(), G[i].end(), cmp);
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	sort(ed + 1, ed + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int x = find(ed[i].u), y = find(ed[i].v);
		// sw << x << " " << y << endl;
		if (x != y) {
			org.push_back(i);
			fa[x] = y;
		}
	}
	for (int i = 1; i <= k; i++) {
		while (!G[i].empty() && G[i].back().w > ed[org.back()].w) {
			G[i].pop_back();
		}
	}
	i64 ans = LONG_LONG_MAX;
	for (int sta = 0; sta < (1 << k); sta++) {
		i64 res = 0;
		int g = __builtin_popcount(sta);
		int tnt = 0;
		// sw << sta << " " << g << sendl;
		for (int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
		for (int i = 1; i <= k; i++) {
			if (sta & (1 << (i - 1))) {
				res += c[i];
				temp[++tnt] = i;
				cur[tnt] = 0;
			}
		}
		int cnt = n + g;
		int z = 0;
		while (cnt > 1) {
			if (z == org.size()) {
				break;
			}
			int f = -1;
			egd i = ed[org[z]];
			for (int j = 1; j <= tnt; j++) {
				if (cur[j] < G[temp[j]].size()) {
					if (i.w > G[temp[j]][cur[j]].w) {
						i = G[temp[j]][cur[j]];
						f = j;
					}
				}
			}
			int u = i.u;
			int v = i.v;
			int w = i.w;
			int x = find(u), y = find(v);
			if (x != y) {
				// sw << u << " " << v << " " << w << sendl;
				fa[x] = y;
				res += w;
				cnt--;
			}
			if (f == -1) {
				z++;
			} else {
				cur[f]++;
			}
		}
		if (cnt != 1) {
			res = LONG_LONG_MAX;
		}
		// sw << res << sendl;
		ans = min(ans, res);
	}
	sw << ans << sendl;
	// sw << 1.0 * (clock() - t) / CLOCKS_PER_SEC << sendl;
	seia;
}