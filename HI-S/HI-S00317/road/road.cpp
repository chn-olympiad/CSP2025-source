#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long n, m, k, cs[10005][10005], c, a[1005], ans=1e18;
bool f[10005];

void dfs(long long step, long long sum, int last) {
	if (sum >= ans) return;
	if (step >= n) {
		ans = min(ans, sum);
		return;
	}
	
	for (int i=1; i<=n; i++) {
		if (f[i]) continue;
		f[i] = 1;
		dfs(step+1, sum+(last!=0?cs[last][i]:0), i);
		f[i] = 0;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	// freopen("road.out", "w", stdout);
	
	memset(cs, 0x3f, sizeof(cs));
	
	cin >> n >> m >> k;
	for (int i=1; i<=m; i++) {
		long long u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		cs[u][v] = w;
		cs[v][u] = w;
	}
	for (int j=1; j<=k; j++) {
		scanf("%lld", &c);
		for (int i=1; i<=n; i++) {
			scanf("%lld", &a[i]);
			for (int j=i; j<=n; j++) {
				cs[i][j] = min(cs[i][j], c+a[i]+a[j]);
				cs[j][i] = cs[i][j];
			}
		}
	}
	
//	for (int i=1; i<=n; i++) {
//		for (int j=1; j<=n; j++) {
//			cout << cs[i][j] << ' ';
//		}
//		cout << endl;
//	}
	dfs(0, 0, 0);
	
	cout << ans;	
	
	return 0;
}

