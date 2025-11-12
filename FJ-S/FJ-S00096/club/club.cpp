#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N][10], dp[N], ans = 0, vis[N], n;

void dfs(int k, int sum, int m) {
	if(k > n) {
		ans = max(ans, sum); 
		return; 
	}
	for (int i = 1;i <= 3;i++) {
		if(vis[i] >= m) continue;
		vis[i]++;
		dfs(k + 1, sum + a[k][i], m);
		vis[i]--;
	}
	return;
}

int main () {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0;
		int m;
		m = n / 2;
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= 3;j++) {
				cin >> a[i][j];
			}
		}
		dfs(1, 0, m);
		cout << ans << endl;
	}
	
	return 0;
}

