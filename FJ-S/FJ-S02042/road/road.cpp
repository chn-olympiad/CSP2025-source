#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e4 + 5;
const int M = 2e6 + 5;

int n, m, k, cnt;
int f[N], a[15][N], c[15], vis[15];
ll ans;
double st;

struct node {
	int u, v, w;
}b[M], d[M];

int fd(int x) {
	if (f[x] == x) return x;
	return f[x] = fd(f[x]);
}

ll Union(int u, int v, int w) {
	int x = fd(u), y = fd(v);
	if (x == y) return 0;
	f[x] = y;
	return w; 
}

bool cmp(node a, node b) {
	return a.w < b.w;
}

ll calc() {
	for (int i = 1; i <= m; ++i)
		d[i] = b[i];
	ll res = 0, cnt = 0;
	for (int i = 1; i <= k; ++i)
		if (vis[i]) 
			res += c[i]; 
	
	sort(d + 1, d + 1 + m + cnt, cmp);
	for (int i = 1; i <= n + k; ++i) f[i] = i;
	for (int i = 1; i <= m + cnt; ++i)
		res += Union(d[i].u, d[i].v, d[i].w);
	return res;
}

void dfs(int x) {
	if (x == k + 1) {
		ans = min(ans, calc());
		if (clock() - st > 900) {
			cout << ans;
			exit(0);
		}
		return;
	}
	if (c[x])
		dfs(x + 1);
	vis[x] = 1;
	for (int j = 1; j <= n; ++j) {
		cnt++;
		d[m + cnt] = (node){j, n + x, a[x][j]};
	}
	dfs(x + 1);
	cnt -= n;
	vis[x] = 0;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	st = clock();
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		b[i] = (node){u, v, w};
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	}
	ans = 1e18;
	dfs(1);
	cout << ans;
	
	return 0;
}


