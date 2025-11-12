#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 50, M = 2e6 + 10, K = 15;

int n, m, k, tot;
int fa[N], c[K], sz[N];
bool build[K];

struct Node{
	int u, v;
	long long w;
	bool operator < (const Node& rhs) const {
		return w < rhs.w;
	}
}e[M];

int find(int x) {
	if (fa[x] == x) return x;
	return (fa[x] = find(fa[x]));
}

void fast_read() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	fast_read();
	
	cin >> n >> m >> k;
	tot = m;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			int d;
			cin >> d;
			e[++tot] = (Node){n + i, j, 1LL * d + c[i]}; // countryside is first
		}
	}
	sort(e + 1, e + tot + 1);
	
	iota(fa + 1, fa + n + k + 1, 1);
	for (int i = 1; i <= n; i++) {
		sz[i] = 1;
	}
	
	long long ans = 0;
	for (int i = 1; i <= tot; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (u > n){
			 if (build[u - n]) w -= c[u - n];
			 build[u - n] = true;
		}
		
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		
		fa[fv] = fu, sz[fu] += sz[fv];
		ans += w;
		// cout << u << ' ' << v << ' ' << w << "\n";
		if (sz[fu] >= n) break;
	}
	
	cout << ans;
	return 0;
}
