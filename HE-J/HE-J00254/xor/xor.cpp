#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

int n, k;
int a[MAXN];
int x[MAXN];
int dp[MAXN];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		x[i] = x[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			if (dp[j - 1] + 1 <= dp[i]) break;
			bool r = (x[i] ^ x[j - 1]) == k;
			dp[i] = max(dp[i], dp[j - 1] + r);
		}
	}
	cout << dp[n] << endl;
	return 0;
}

