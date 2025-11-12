#include <bits/stdc++.h>

using namespace std;

typedef long long lnt;

const int N = 1e4 + 7, M = 1e6 + 7;

int n, m, k;

struct Edge {
	int x, y, z;
} eg[M], a[10][N], e[M];

inline bool operator< (const Edge &a, const Edge &b) {
	return a.z < b.z;
}

int fa[N];

inline int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int c[10];

void INIT() { }

void WORK() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++ i) {
		int x, y, z;
		cin >> x >> y >> z;
		eg[i] = { x, y, z };
	}
	for (int j = 0; j < k; ++ j) {
		cin >> c[j];
		for (int i = 1; i <= n; ++ i) {
			cin >> a[j][i].z;
			a[j][i].x = n + 1 + j;
			a[j][i].y = i;
		}
		sort(a[j] + 1, a[j] + n + 1);
	}
	sort(eg + 1, eg + m + 1);
	iota(fa + 1, fa + n + 1, 1);
	for (int i = 1, t = 0; i <= m; ++ i) {
		int x = find(eg[i].x);
		int y = find(eg[i].y);
		if (x == y) {
			continue;
		}
		fa[x] = y;
		eg[ ++ t] = eg[i];
	}
	lnt ans = 1e18;
	for (int S = 0, Se = (1 << k); S < Se; ++ S) {
		lnt res = 0;
		int si = n - 1;
		copy(eg + 1, eg + n, e + 1);
		int t = n - 1;
		for (int j = 0; j < k; ++ j) {
			if (S >> j & 1) {
				res += c[j];
				++ si;
				copy(a[j] + 1, a[j] + n + 1, e + t + 1);
				inplace_merge(e + 1, e + t + 1, e + t + n + 1);
				t += n;
			}
		}
		iota(fa + 1, fa + n + k + 1, 1);
		for (int i = 1; si && res < ans; ++ i) {
			int x = find(e[i].x);
			int y = find(e[i].y);
			if (x == y) {
				continue;
			}
			-- si;
			fa[x] = y;
			res += e[i].z;
		}
		ans = min(ans, res); 
	}
	cout << ans << '\n';
}

#define filename "road"

int main() {
	#ifdef filename
	freopen(filename ".in", "r", stdin);
	freopen(filename ".out", "w", stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int Turn = 1;
//	cin >> Turn;
	INIT();
	while (Turn -- ) {
		WORK();
	}
	return 0;
}