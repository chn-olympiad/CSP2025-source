#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k;
int c[15], edg[15][100005], fa[10005];
int head[2000005], ver[2000005], to[2000005], edge[2000005], tot = 0;

void add(int x, int y, int z) {
	ver[++ tot] = y;
	edge[tot] = z;
	to[tot] = head[x];
	head[x] = tot;
}

int ff(int x) {
	if(fa[x] == x) return x;
	return fa[x] = ff(fa[x]);
}

struct Edge {
	int u, v, w;
}E[2000005];

bool cmp(Edge E1, Edge E2) {
	return E1.w < E2.w;
}

int mm = 0;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i ++) {
		fa[i] = i;
	}
	for(int i = 1, x, y, z;i <= m;i ++) {
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}
	int ans = 0ll, edgecnt = 0;
	for(int x = 1;x <= n;x ++) {
		for(int i = head[x];i;i = to[i]) {
			E[++ mm] = {x, ver[i], edge[i]};
		}
	}
	sort(E + 1, E + mm + 1, cmp);
	for(int i = 1;i <= mm;i ++) {
		int x = E[i].u, y = E[i].v, z = E[i].w;
		if(ff(x) == ff(y)) continue;
		edgecnt ++;
		ans += z;
		fa[ff(x)] = ff(y);
		if(edgecnt == n - 1) break;
	}
	cout << ans << "\n"; 
	return 0;
}
//链式前向星二倍空间。 
