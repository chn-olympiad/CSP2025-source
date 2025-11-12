#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans = 0;

int main () {
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	scanf ("%d %d",&n,&k);
	int maxn = n + 10;
	int a[maxn];
	long long dp[maxn][maxn];
	memset (dp,-1,sizeof(dp));
	for (int i = 1;i <= n; ++i) {
		scanf ("%d",&a[i]);
	}
	for (int i = 1;i <= n; ++i) {
		for (int j = i;j <= n; ++j) {
			if (i != j) {
				dp[i][j] = dp[i][j - 1] ^ a[j];
			} else {
				dp[i][i] = a[i];
			}
		}
	}
	for (int i = 1;i <= n; ++i) {
		for (int j = i;j <= n; ++j) {
			if (dp[i][j] == k) {
				i = j + 1;
				ans += 1;
			}
		}
	}
	printf ("%d",ans);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
