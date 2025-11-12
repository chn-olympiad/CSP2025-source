#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
int dp[50][50][50][50], number[300][5], vis[50][50][50][50];
int n;

int dfs(int now, int i, int j, int k) {
	if(now > n) {
		return 0;
	}
	if(vis[now][i][j][k])
		return dp[now][i][j][k];
		
	vis[now][i][j][k] = 1;
	dp[now][i][j][k] = 0;
	
	
	if(i < ceil(n / 2.0)) {
		dp[now][i][j][k] = max(dp[now][i][j][k], dfs(now + 1, i + 1, j, k) + number[now][1]);
	}
	if(j < ceil(n / 2.0)) {
		dp[now][i][j][k] = max(dp[now][i][j][k], dfs(now + 1, i, j + 1, k) + number[now][2]);
	}
	if(k < ceil(n / 2.0)) {
		dp[now][i][j][k] = max(dp[now][i][j][k], dfs(now + 1, i, j, k + 1) + number[now][3]);
	}
	
	return dp[now][i][j][k];
}

signed main() {
    freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	
	int t;
	cin >> t;
	
	while(t--) {
		memset(dp, 0, sizeof dp);
		memset(vis, 0, sizeof vis);
		memset(number, 0, sizeof number);
		
		cin >> n;
		
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= 3; j ++) {
				cin >> number[i][j];
			}
		}
		
		cout << dfs(1, 0, 0, 0) << endl;
	}
	
	return 0;
}

