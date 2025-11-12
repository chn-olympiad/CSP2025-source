#include <cstdio>
#include <algorithm>

int a[500005];
int s[500005];
int dp[1005][1005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	bool speca = true, specb = true;
	int cnt1 = 0;
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) {
			cnt1 ++;
		} else {
			speca=false;
		}
		if (a[i] > 1) {
			specb = false;
		}
		s[i] = s[i-1] ^ a[i];
	}
	if (speca) {
		if (k == 0) {
			printf("%d", cnt1 / 2);
		} else if (k == 1) {
			printf("%d", cnt1);
		} else {
			putchar('0');
		}
		return 0;
	}
	if (specb) {
		if (k == 0) {
			int cnt = 0;
			bool odd = false;
			for (int i = 1 ; i <= n ; i ++) {
				if (a[i] == 0) {
					cnt ++;
					odd = false;
				} else if (odd) {
					cnt ++;
					odd = false;
				} else {
					odd = true;
				}
			}
			printf("%d", cnt);
		} else if (k == 1) {
			printf("%d", cnt1);
		} else {
			putchar('0');
		}
		return 0;
	}
	if (n <= 1000) {
		for (int length = 1 ; length <= n ; length ++) {
			for (int l = 1 ; l + length - 1 <= n ; l ++) {
				int r = l + length - 1;
				if ((s[l-1]^s[r]) == k) {
					dp[l][r] = 1;
				} else {
					dp[l][r] = 0;
				}
				for (int split = l ; split < r ; split ++) {
					dp[l][r] = std::max(dp[l][r], dp[l][split]+dp[split+1][r]);
				}
			} 
		}
		printf("%d", dp[1][n]);
		return 0;
	}
	putchar('0');
	return 0;
}
