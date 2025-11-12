#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
const int MOD = 998244353;
int n, a[N], maxnum;
long long C[N][N];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	C[0][0] = 1;
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	} 
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); 
		maxnum = max(maxnum, a[i]);
	}
	if (n <= 20) {
		int ans = 0;
		for (int i = 0; i < (1 << n); i++) {
			int subsum = 0, submax = 0, sublen = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					subsum += a[j]; 
					submax = max(submax, a[j]);
					sublen++;
				}
			}
			if (sublen >= 3 && subsum > submax * 2) {
				ans++;
			}
		}
		printf("%d", ans);
	} else if (maxnum == 1) {
		long long res = 0;
		for (int i = 3; i <= n; i++) {
			res = (res + C[n + 1][i + 1]) % MOD;
		}
		printf("%lld", res % MOD);
	} else {
		printf("0");
	}
	return 0;
}
