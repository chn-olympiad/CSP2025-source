#include <bits/stdc++.h>
using namespace std;
const int N = 5005, M = 2.5e7 + 2, mod = 998244353;
int n, a[N], dp[M];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = 0, ans = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = sum; j > a[i]; --j)
			ans = (ans + dp[j]) % mod;
		sum += a[i];
		for (int j = sum; j >= a[i]; --j)
			dp[j] = (dp[j] + dp[j - a[i]]) % mod;
	}
	cout << ans << '\n';
	return 0;
}
/*
g++ polygon.cpp -o polygon -std=c++14 -O2 -static
*/