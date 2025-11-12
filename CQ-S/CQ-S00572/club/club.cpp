#include<bits/stdc++.h>
using namespace std;
int dp[100005], a[100005][5], ans;
int n;
void dfs(int i, int sum, int x, int y, int z) {
	if (i > n) {
		ans = max(ans, sum);
		return ;
	}
	if (x < n / 2) {
		dfs(i + 1, sum + a[i][1], x + 1, y, z);
	}
	if (y < n / 2) {
		dfs(i + 1, sum + a[i][2], x, y + 1, z);
	}
	if (z < n / 2) {
		dfs(i + 1, sum + a[i][3], x, y, z + 1);
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
