#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e3 + 2;
const int MOD = 998244353;
int n, a[N], dp[N], ans, maxt, sumt;

int Popcount(int msk) {
	int nmsk = msk, cnt = 0;
	while (nmsk) {
		nmsk &= (nmsk - 1);
		cnt++;
	}
	return cnt;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		maxt = max(maxt, a[i]), sumt += a[i];
	}
	if (n <= 10) {
		sort(a, a + n);
		for (int msk = 1; msk < (1 << n); msk++) {
			int cnt = Popcount(msk);
			if (cnt < 3) {
				continue;
			}
			int sum = 0, maxx = 0;
			for (int i = 0; i < n; i++) {
				if (msk & (1 << i)) {
					sum += a[i], maxx = max(maxx, a[i]);
				}
			}
			if (sum > maxx * 2) {
				ans = (ans + 1);
			}
		}
		printf("%d", ans);
	} else {
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = sumt; j >= a[i]; j--) {
				dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
			}
		}
		puts("Can mix:");
		for (int i = 1; i <= sumt; i++) {
			printf("%d ", dp[i]);
		}
		puts("");
		for (int i = 0; i < n; i++) {
			for (int j = 2 * a[i] + 1; j <= sumt - a[i]; j++) {
				ans = (ans + dp[j]) % MOD;
			}
		}
		printf("%d", ans);
	}
	return 0;
}

