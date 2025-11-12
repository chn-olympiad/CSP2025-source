#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 500, maxm = 2e6 + 5;
int n, m, k, ans;
struct edge{
	int u, v, next;
	int w;
	int tag;
}e[maxm];
int h[maxm], ecn, fa[maxn];
struct node{
	int w;
	int x, y, v;
	bool operator <(const node &x)const {
		return w > x.w;
	}
};
priority_queue<node> q;
void add(int u, int v, int w, int tag) {
	e[++ecn].v = v;
	e[ecn].u = u;
	e[ecn].w = w;
	e[ecn].next = h[u];
	e[ecn].tag = tag;
	h[u] = ecn;
	q.push((node){e[ecn].w, e[ecn].u, e[ecn].tag, e[ecn].v});
}
int c[20], a[20][maxn];

int find(int x) {
	if(fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void hb(int x, int y){
	int qx = find(x), qy = find(y);
	fa[qy] = qx;
}
void pl() {
	while(!q.empty()) {
		//cout << "(";
		node p = q.top(); q.pop();
		int x = find(p.v), y = find(p.x);
		if(x == y) continue;
		if(p.y) {
			if(a[p.y][0]) continue;
			a[p.y][0] = 1;
			for(int j = 1; j < n; j++) {
				for(int l = j; l <= n; l++) add(j, l, a[p.y][j] + a[p.y][l], 0), add(l, j, a[p.y][j] + a[p.y][l], 0);
			}
		}
		ans += p.w;
		//cout << p.w << ' ';
		hb(p.x, p.v);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w, 0);
		add(v, u, w, 0);
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	bool k = 1;
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		if(c[i]) k = 0; 
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if(a[i][j]) k = 0;
		}
		for(int j = 1; j < n; j++) {
			for(int l = j; l <= n; l++) add(j, l, a[i][j] + c[i] + a[i][l], i), add(l, j, a[i][j] + c[i] + a[i][l], i);
		}
	}
	if(k) {
		cout << 0;
		return 0;
	}
	pl();
	cout << ans;
	return 0;
}
