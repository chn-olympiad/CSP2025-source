#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 10;
int n, m, k, fa[N], d[N], dis[N], vis[N], frm[N], flag[N], ans, c[N], a[20][(int)(1e5) + 10];
struct Node {
	int u, v, w;
	bool operator < (const Node & x) const {
		if(u > n && v > n && !(x.u > n && x.v > n)) {
			return 1;
		}
		if(!(u > n && v > n) && x.u > n && x.v > n) {
			return 0;
		}
		return w < x.w;
	}
}E[N], E2[N]; 

int find(int x) {
	return x == fa[x] ?x : fa[x] = find(fa[x]);
}

int kruskal(int n, int m) {
	int ans = 0, now = n;
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for(int j = 1; j <= m; j++) {
		E2[j] = E[j];
	}
	sort(E2 + 1, E2 + m + 1);
	for(int i = 1; i <= m && now > 1; i++) {
		if(find(E2[i].u) != find(E2[i].v)) {
			ans += E2[i].w;
			fa[find(E2[i].u)] = find(E2[i].v);
			now--;
		} 
	}
	return ans;
}

int solve() {
	int ans = 1e18;
	for(int i = 0; i < 1 << k; i++) {
		int now = n, cnt = m;
		for(int j = 1; j <= k; j++) {
			if((i >> j - 1) & 1) {
				cnt++;
				E[cnt] = {now + 2, now + 1, c[j]};
				for(int l = 1; l <= n; l++) {
					cnt++;
					E[cnt] = {now + 1, l, a[j][l]};
					cnt++;
					E[cnt] = {l, now + 2, a[j][l]};
				}
				now += 2;
			}
		}
		ans = min(ans, kruskal(now, cnt));
	}
	return ans;
}

signed main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		E[i] = {u, v, w};
	}
	bool flag = 1;
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		if(c[i])  {
			flag = 0;
		}
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if(a[i][j])  {
				flag = 0;
			}
		}
	}
	if(!flag) {
		cout << solve() << "\n";
	}
	else {
		cout << "0\n";
	}

	return 0;
}

