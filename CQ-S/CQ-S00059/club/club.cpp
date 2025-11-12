#include <bits/stdc++.h>
using namespace std;
int T;
int n;
struct node{
	int x, y, z;
}a[100005];
long long dp[205][105][105][105];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		}
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= n / 2; j++) {
				for(int k = 0; k <= n / 2; k++) {
					for(int l = 0; l <= n / 2; l++) {
						dp[i][j][k][l] = 0;
						if(i == 0) continue;
						dp[i][j][k][l] = max(dp[i - 1][j][k][l], dp[i][j][k][l]);
						if(j > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j - 1][k][l] + a[i].x);
						if(k > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k - 1][l] + a[i].y);
						if(l > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l - 1] + a[i].z);
					}
				}
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n / 2; i++) {
			for(int j = 1; j <= n / 2; j++) {
				for(int k = 1; k <= n / 2; k++) {
					ans = max(ans, dp[n][i][j][k]);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
