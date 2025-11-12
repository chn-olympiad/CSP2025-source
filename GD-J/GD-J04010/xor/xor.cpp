#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL MAXN = 5e5+5, MAXK = 1048576+20;
LL n, k, xr[MAXN], dp[MAXN];
deque<LL> s[MAXK];

int main() {
	// rp++;
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	s[0].push_back(0);
	for (LL i = 1; i<=n; i++) {
		cin >> xr[i];
		xr[i] ^= xr[i-1];
		dp[i] = dp[i-1];
		if (!s[k^xr[i]].empty()) {
			dp[i] = max(dp[i], 1+dp[s[k^xr[i]].front()]);
		}
		while (!s[xr[i]].empty() && dp[s[xr[i]].back()] < dp[i]) s[xr[i]].pop_back();
		s[xr[i]].push_back(i);
	}
	cout << dp[n];
	return 0;
} 
