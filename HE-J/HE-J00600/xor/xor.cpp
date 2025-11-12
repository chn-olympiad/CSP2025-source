#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010];
int b[500010], dp[500010];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1) flag = false;
	}
	for (int i = 1; i <= n; i++)
	{
		int ans = a[i], pos = i;
		while (pos <= n && ans != k)
		{
			pos++;
			ans ^= a[pos];
		}
		if (pos > n) b[i] = -1;
		else b[i] = pos;
	}
	if (a[1] == k) dp[1] = 1;
	else dp[1] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < i; j++)
		{
			if (b[j + 1] == -1) continue; 
			if (b[j + 1] <= i) dp[i] = max(dp[i], dp[j] + 1);
		}
	cout << dp[n] << endl;
	return 0;
}
