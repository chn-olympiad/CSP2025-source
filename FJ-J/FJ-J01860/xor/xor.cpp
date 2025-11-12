#include <bits/stdc++.h>
using namespace std;
int dp[500005],n,sum[500005];
long long a[500005],k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	    cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		int j = i;
		long long cnt = a[i];
		while (cnt != k && j > 1)
		    j--,cnt = cnt ^ a[j];
		if (cnt != k) sum[i] = -1;
		else sum[i] = i - j + 1;
	}
	for (int i = 1;i <= n;i++)
	{
		if (sum[i] == -1) dp[i] = dp[i - 1];
		else dp[i] = max(dp[i - 1],dp[i - sum[i]] + 1); 
	}
	cout << dp[n];
} 
