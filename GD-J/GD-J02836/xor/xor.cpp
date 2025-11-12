#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], dp[500005]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		a[i] ^= a[i - 1];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((a[i-1]^a[j])==k)
				dp[j]=max(dp[i-1]+1,dp[j]);
	cout << dp[n];
	return 0;
}
