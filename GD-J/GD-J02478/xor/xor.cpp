#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int a[N];
int dp[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i != 1) dp[i] = dp[i - 1] ^ a[i];
		else dp[i] = a[i];
	}
	int l = 0, r = 1;
	int tot = 0;
	while (r <= n) {
		for (int i = r - 1; i >= l; i--) {
			if (i == 0 && dp[r] == k) {
				tot++;
				l = r;
				break;
			}
			int x = dp[r] ^ dp[i];
			if (x == k) {
				tot++;
				l = r;
				break;
			}
		}
		r++;
	}
	printf("%d", tot);
	return 0;
} 
