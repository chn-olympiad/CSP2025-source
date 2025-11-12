#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5001;
int n, cnt, a[N], val[N];
bool vis[N];
inline void dfs(int x, int m) {
	if (x == m + 1) {
		for (int i = 1; i <= m; i++) {
			if (val[i] < val[i - 1]) return ;
		}
		int sum = 0;
		for (int i = 1; i < m; i++) sum += val[i];
		if (val[m] < sum) cnt++; 
		return ;
	}
	for (int i = 1; i <= n; i++) {
		int k = a[i];
		if (vis[k]) continue;
		vis[k] = true;
		val[x] = k; 
		dfs(x + 1, m);
		vis[k] = false;
		val[x] = 0;
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 3; i <= n; i++) {
		dfs(1, i);
	}
	cout << cnt;
	return 0;
}
