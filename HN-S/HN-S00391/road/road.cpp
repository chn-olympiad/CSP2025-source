#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m, k;
int fa[10029];

int find(int u) {
	if(fa[u] != u) fa[u] = find(fa[u]);
	return fa[u];
}

inline bool hb(int x, int y) {
	int xr = find(x), yr = find(y);
	if(xr == yr) return 0;
	fa[xr] = yr;
	return 1;
}

int x[1000029];
int y[1000029];
int z[1000029];
int c[29];
int d[29][10029];

int ans = 0x7f7f7f7f;

priority_queue<array<int, 3> > edge;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i] >> z[i];
	}
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}
	for(int i = 0; i < (1 << k); i++) {
		for(int j = 1; j <= n + k; j++) {
			fa[j] = j;
		}
		int cnt = 0;
		for(int j = 1; j <= k; j++) {
			if(i & (1 << j - 1)) {
				cnt += c[j];
				for(int k = 1; k <= n; k++) {
					edge.push({-d[j][k], n + j, k});
				}
			}
		}
		if(cnt > ans) continue;
		for(int i = 1; i <= m; i++) {
			edge.push({-z[i], x[i], y[i]});
		}
		while(edge.size()) {
			int w = -edge.top()[0], u = edge.top()[1], v = edge.top()[2];
			edge.pop();
			if(hb(u, v)) {
//				cout << u << "->" << v << " " << w << "\n";
				cnt += w;
				if(cnt > ans) break;
			}
		}
//		cout << cnt << " " << i << "\n";
		ans = min(ans, cnt);
	}
	cout << ans<< "\n";
	
	return 0; 
}
