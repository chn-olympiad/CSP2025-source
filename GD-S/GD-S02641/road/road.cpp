#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef struct b {
	int u, v, w;
} b;
struct cmp {
	bool operator() (b x, b y) {
		return x.w > y.w;
	}
};
priority_queue <b, vector <b>, cmp > l;
int n, m, k, u[1000010], v[1000010], w[1000010], a[10010], cnt, ans, c[20];
bool is[10010], can[10010][10010];
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		can[u[i]][v[i]] = can[v[i]][u[i]] = true;
		if (k == 0) {
			l.push({u[i], v[i], w[i]});
		}
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[j]);
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= m; j++) {
			w[j] = min(w[j], (c[i] + a[u[j]] + a[v[j]]));
		}
		for (int j = 1; j <= n; j++) {
			for (int z = 1; z <= n; z++) {
				if (j == z || can[j][z]) continue;
				l.push({j, z, (c[i] + a[j] + a[z])});
				can[j][z] = true;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		l.push({u[i], v[i], w[i]});
	}
	int uu, vv, ww;
	while (cnt < n) {
		uu = l.top().u, vv = l.top().v, ww = l.top().w;
	//	if (uu == 1 && vv == 3) cout << ':' << ww <<endl;
		if (!is[vv] || !is[uu]) {
			ans += ww;
		//	cout << uu << ' ' << vv << ' ' << ww << endl;
		}
		if (!is[vv]) cnt++;
		if (!is[uu]) cnt++;
		is[uu] = is[vv] = true;
		l.pop();
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
