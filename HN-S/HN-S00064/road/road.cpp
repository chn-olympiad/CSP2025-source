#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, fa[1000005], siz[1000005], ans, x, y, z, w, cnt, c[1000005];
struct road{
	int x, y, z;
} rd[1000005];
struct node{
	int x, y, z, wch;
} a[1000005];
bool vis[1000005];

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
bool croad(road a, road b){
	return a.z < b.z;
}
bool cnode(node a, node b){
	return a.z < b.z;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for( int i = 1; i <= m; i++ ) cin >> rd[i].x >> rd[i].y >> rd[i].z;
	sort(rd + 1, rd + m + 1, croad);
	for( int i = 1; i <= n; i++ ){
		fa[i] = i;
		siz[i] = 1;
	}
	for( int i = 1; i <= m; i++ ){
		x = rd[i].x, y = rd[i].y, z = rd[i].z;
		int u = find(x), v = find(y);
		if(u == v) continue;
		if(siz[u] < siz[v]) swap(u, v);
		fa[v] = u;
		siz[u] += siz[v];
		ans += z;
		a[++cnt] = {x, y, z, 0};
	}
	vis[0] = 1;
	for( int i = 1; i <= k; i++ ){
		cin >> c[i];
		for( int j = 1; j <= n; j++ ){
			cin >> x;
			a[++cnt] = {i + n, j, x, i};
		}
	}
	sort(a + 1, a + cnt + 1, cnode);
	for( int i = 1; i < (1 << k); i++ ){
		int spend = 0;
		for( int j = 0; j < k; j++ ){
			if((i >> j) & 1){
				vis[j + 1] = 1;
				spend += c[j + 1];
			}
			else vis[j + 1] = 0;
		}
		for( int j = 1; j <= n + k; j++ ){
			fa[j] = j;
			siz[j] = 1;
		}
		for( int j = 1; j <= cnt; j++ ){
			if(!vis[a[j].wch]) continue;
			x = a[j].x, y = a[j].y, z = a[j].z;
			int u = find(x), v = find(y);
			if(u == v) continue;
			if(siz[u] < siz[v]) swap(u, v);
			fa[v] = u;
			siz[u] += siz[v];
			spend += z;
		}
		ans = min(spend, ans);
	}
	cout << ans << '\n';
	return 0;
}
