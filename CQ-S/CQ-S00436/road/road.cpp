#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e4+10, M = 2e6+10, K = 20;

int n, m, k;
int c[K], a[K][N];
int f[N], minn;
bool vis[M];

struct node {
	int u, v, w;
} ed[M], tt[M];

void init(int n) {
	for (int i = 1;i<= n;i++)
		f[i] = i;
}

int doFind(int x) {
	if (f[x] == x) return x;
	return f[x] = doFind(f[x]);
}

void doUnion(int x, int y) {
	x = doFind(x), y = doFind(y);
	if (x == y) return ;
	f[y] = x;
}

bool cmp(node x, node y) {
	return x.w < y.w;
}

void dfs(int step, int sum) {
	if (sum > minn) return ;
	if (step > k) {
		init(n+k);
		int tmp = m, ans = 0;
		for (int i = 1;i<= m;i++) {
			ed[i] = {tt[i].u, tt[i].v, tt[i].w};
		}
		for (int i = 1;i<= k;i++) {
			if (vis[i] == 0) continue;
			for (int j = 1;j<= n;j++) {
				ed[++tmp] = {n+i, j, a[i][j]};
			}
		}
		sort(ed+1, ed+tmp+1, cmp);
		for (int i = 1;i<= tmp;i++) {
			int u = ed[i].u, v = ed[i].v;
//			cout << u << " " << v << " " << ed[i].w << endl;
			if (doFind(u) == doFind(v)) continue;
			doUnion(u, v); ans += ed[i].w;
			if (ans+sum >= minn) return ;
		}
//		cout << ans + sum << endl;
//		for (int i = 1;i<= k;i++) {
//			cout << vis[i] << " "; 
//		} cout << endl;
//		cout << endl;
		
		minn = ans+sum;
		return ;
	}
	vis[step] = 0;
	dfs(step+1, sum);
	vis[step] = 1;
	dfs(step+1, sum + c[step]);
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i<= m;i++) {
		cin >> tt[i].u >> tt[i].v >> tt[i].w;
	}
	sort(tt+1, tt+m+1, cmp);
	init(n);
	for (int i = 1;i<= m;i++) {
		int u = tt[i].u, v = tt[i].v;
		if (doFind(u) == doFind(v)) continue;
		vis[i] = 1; doUnion(u, v);
		minn += tt[i].w;
	} 
	int tmp = 0;
	for (int i = 1;i<= m;i++) {
		if (!vis[i]) continue;
		tt[++tmp] = {tt[i].u, tt[i].v, tt[i].w};
	} m = tmp;
	for (int i = 1;i<= k;i++) {
		cin >> c[i];
		for (int j = 1;j<= n;j++) {
			cin >> a[i][j];
		}
	}
	dfs(1, 0);
	cout << minn << endl;
	return 0;
}
