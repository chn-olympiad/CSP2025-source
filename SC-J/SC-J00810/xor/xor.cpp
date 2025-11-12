#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], sum[N], dp[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
	}
	int l = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = l; j < i; j++) {
			if ((sum[i] ^ sum[j]) == k) {
				dp[i] = max(dp[i], dp[j] + 1);
			} else {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		if (dp[i] > dp[i-1]) l = i-1;
	}
	cout << dp[n];
	return 0;
}