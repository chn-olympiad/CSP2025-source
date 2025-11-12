#include <bits/stdc++.h>
using namespace std;

int n, k, a[500005], dp[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		int x = 0;
		int pos = lower_bound(dp + 1, dp + i, dp[i] - 1) - dp - 1;
		for (int j = i; j >= pos; j--) {
			x ^= a[j];
			if (x == k) {
				dp[i] = max(dp[i], dp[j - 1] + 1);
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
