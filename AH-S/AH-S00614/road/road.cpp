#include <bits/stdc++.h>
using namespace std; 
const long long N = 1e4 + 5, M = 1e6 + 5, K = 15; 
struct Edge {
	long long to, from, next, dis; 
} edge[2 * (M + N * K)]; 
long long n, m, k, numedge, ans, head[N], c[K], a[K][N], fa[N + K];
void addedge(long long from, long long to, long long dis) {
	edge[++numedge].next = head[from]; 
	edge[numedge].from = from; 
	edge[numedge].to = to; 
	edge[numedge].dis = dis; 
	head[from] = numedge; 
} 
long long find(long long x) {
	if (fa[x] == x)
		return x; 
	else 
		return fa[x] = find(fa[x]); 
}
void onion(long long x, long long y) {
	long long fx = find(x), fy = find(y); 
	if (fx == fy)
		return; 
	fa[fx] = fy; 
	return; 
}
int main() {
	//cout << "Able!" << endl; 
	ios :: sync_with_stdio(false); 
	cin.tie(nullptr), cout.tie(nullptr); 
	freopen("road.in", "r", stdin); 
	freopen("road.out", "w", stdout); 
	cin >> n >> m >> k; 
	for (long long i = 1; i <= m; i++) {
		//cout << "Able!" << endl; 
		long long u, v, w; 
		cin >> u >> v >> w; 
		addedge(u, v, w); 
		addedge(v, u, w); 
	}
	//cout << "Able!" << endl; 
	for (long long i = 1; i <= k; i++) {
		cin >> c[i]; 
		for (long long j = 1; j <= n; j++) {
			cin >> a[i][j]; 
			addedge(n + i, j, a[i][j]); 
			addedge(j, n + i, a[i][j]); 
		}
	}
	//cout << "Able!" << endl; 
	sort(edge + 1, edge + numedge + 1, [](Edge x, Edge y) {
		return x.dis < y.dis; 
	}); 
	for (long long i = 1; i <= n + k; i++)
		fa[i] = i; 
	long long cnt = 0; 
	for (long long i = 1; i <= numedge && cnt < n + k - 1; i++) {
		long long u = edge[i].from, v = edge[i].to; 
		long long fu = find(u), fv = find(v); 
		if (fu == fv)
			continue; 
		cnt++; 
		onion(fu, fv); 
		ans += edge[i].dis; 
	}
	cout << ans << endl; 
	return 0; 
}
