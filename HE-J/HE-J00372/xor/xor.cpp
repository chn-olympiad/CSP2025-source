#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, k, a[N], s[N], dp[N];
map<int, int> mp;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] ^ a[i];
	mp[s[n]] = n;
	for (int i = n; i >= 1; i--) {
		int tmp = (k ^ s[i - 1]);
		dp[i] = dp[i + 1];
		if (mp.count(tmp))
			dp[i] = max(dp[i], dp[mp[tmp] + 1] + 1);
		mp[s[i - 1]] = i - 1;
	}
	cout << dp[1] << '\n';
	return 0;
}
