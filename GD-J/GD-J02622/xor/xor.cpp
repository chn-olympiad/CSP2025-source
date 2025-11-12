#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long n,k,a[1003],cnt[1003][1003],num[1003][1003],dp[1003],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int len = 1;len <= n;len++)
	{
		for(int l = 1,r = l + len - 1;r <= n;l++,r++)
		{
			cnt[l][r] = cnt[l][r - 1] ^ a[r];
			num[l][r] = (cnt[l][r] == k);
		}
	}
	dp[1] = (a[1] == k);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j < i;j++)
		{
			dp[i] = max(dp[i],dp[j] + num[j + 1][i]);
		}
	}
	cout << dp[n];
	return 0;
}
