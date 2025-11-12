#include <bits/stdc++.h>
using namespace std;

int a[500005];
int s[500005];
int dp[500005];
unordered_map < int, int > mp;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		if (s[i] == m) dp[i] = max(dp[i], dp[mp[0]] + 1);
		if (mp[s[i] ^ m]) dp[i] = max(dp[i], dp[mp[s[i] ^ m]] + 1);
		mp[s[i]] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';
    return 0;
}
