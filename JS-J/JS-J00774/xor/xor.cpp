#include <bits/stdc++.h>
using namespace std;
int xr(int x, int y) {
	int p = 1;
	int res = 0;
	while (x != 0 || y != 0) {
		if (((x % 2 && y % 2) == 0) && ((x % 2 || y % 2) == 1))
			res += p;
		x >>= 1;
		y >>= 1;
		p *= 2;
	}
	return res;
}
//4 2
//2 1 0 3
int fi(int start, int sum, int n, int k, int a[], int dp[]) {
	if (start > n)
		return sum;
	int mx = -1;
	for (; start <= n; ++start) {
		int test = a[start];
		for (int i = start; i <= n; ++i) {
			if (test == k) {
				if (dp[i + 1] == 0) {
					int tt = fi(i + 1, sum + 1, n, k, a, dp);
					dp[i + 1] = tt - sum;
				}
				mx = max(mx, sum + dp[i + 1]);
				break;
			}
			test = xr(test, a[i + 1]);
		}
	}
	return mx;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	int a[500010];
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int dp[500010];
	memset(dp, 0, sizeof(dp));
	cout << fi(1, 0, n, k, a, dp);
	return 0;
}
