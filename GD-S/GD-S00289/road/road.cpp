#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6+10;
struct node {
	int u, v, w;
	bool operator < (const node &u) const {
		return  w < u.w;
	}
} e[maxn];
int f[maxn];
bool vis[maxn];

int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, tot = 0;
	cin >> n >> m >> k;
	for(int i=0; i<=n+k+10; i++) {
		f[i] = i;
	}
	for(int i=1; i<=m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[++tot] = {u, v, w};
	}
	for(int i=1; i<=k; i++) {
		int tw, w;
		cin >> tw;
		e[++tot] = {0, n+i, tw};
		for(int j=1; j<=n; j++) {
			cin >> w;
			e[++tot] = {n+i, j, w}; 
		}
	}
	sort(e+1, e+tot+1);
	long long ans = 0;
	for(int i=1; i<=tot; i++) {
		if(e[i].u > n && !vis[e[i].u]) continue;
		if(e[i].v > n && !vis[e[i].v]) continue;
		vis[e[i].u] = vis[e[i].v] = true;
		int fx = find(e[i].u);
		int fy = find(e[i].v);
		if(fx == fy) continue;
		f[fx] = fy;
		ans += e[i].w;
		int t = find(1);
		int flag = 1;
		for(int j=2; j<=n; j++) {
			if(t != find(j)) {
				flag = 0; 
				break;
			}
		}
		if(flag) {
			break;
		}
	}
	cout << ans;
	return 0;
}

