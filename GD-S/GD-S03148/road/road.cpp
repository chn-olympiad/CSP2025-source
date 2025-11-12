#include<bits/stdc++.h>
using namespace std;
int n, m, k;
struct node{
	int u, v;
	int w;
}r[1000010];
bool vis[10010][10010], viss[10010];
int c[15][10010];
int pricec[15];
int ans;
bool cmp(node x, node y) {
	return x.w < y.w;
}
void solve() {
	int cnt = 0, cntt = 0;
	for(int i = 1; i <= m; i++) {
		if(!vis[r[i].u][r[i].v]) {
			cnt++;
			vis[r[i].u][r[i].v] = 1;
			if(!viss[r[i].u]) cntt++;
			if(!viss[r[i].v]) cntt++;
			viss[r[i].u] = 1;
			viss[r[i].v] = 1;
			ans += r[i].w;
		}
		if(cnt == n - 1 && cntt == n) break;
	}
	cout << ans;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int u, v, w;
	for(int i = 1; i <= m; i++) {
		cin >> r[i].u >> r[i].v >> r[i].w;
		if(r[i].u > r[i].v) swap(r[i].u, r[i].v);
	}
	for(int i = 1; i <= k; i++) {
		cin >> pricec[i];
		for(int j = 1; j <= n; j++) cin >> c[i][j];
	}
	for(int i = 1; i <= k; i++) {
		for(int l = 1; l < n; l++) {
			for(int rr = l + 1; rr <= n; rr++) {
				m++;
				r[m].u = l;
				r[m].v = rr;
				r[m].w = pricec[i] + c[i][l] + c[i][rr];
			}
		}
	}
	sort(r + 1, r + m + 1, cmp);
	solve();
	return 0;
}
