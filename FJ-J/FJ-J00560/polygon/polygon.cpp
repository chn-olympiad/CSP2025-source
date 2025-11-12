#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define mod 998244353
#define MAX_N 5000
int n, a[MAX_N + 5], dp[MAX_N + 5][MAX_N + 5], pw[MAX_N + 5], ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	pw[0] = 1;
	for (int i = 1; i <= MAX_N; i++) 
		pw[i] = pw[i - 1] * 2 % mod;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
//		printf("nnn%d %d\n", i, a[i]);
		for (int j = 0; j <= a[n]; j++) {
			if (j == 0) {
				dp[i][j] = pw[i - 1] - 1;
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i - 1][max(j - a[i - 1], 0)];
			if (a[i - 1] > j) dp[i][j]++;
			dp[i][j] %= mod;
//			printf("!!!%d %d %d\n", i, j, dp[i][j]);
		}
		ans = (ans + dp[i][a[i]]) % mod;
	}
	printf("%d", ans);
	return 0;
}

