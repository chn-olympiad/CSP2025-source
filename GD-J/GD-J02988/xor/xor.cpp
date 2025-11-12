#include <bits/stdc++.h>
using namespace std;
int n, a[500005], k, sum[500005], dp[500005], ans, x;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	
	int i, j;
	cin>>n>>k;
	for(i=1; i<=n; i++)
	{
		cin>>a[i];
		if(i>=2)
			sum[i]=sum[i-1]|a[i];
		else
			sum[i]=a[i];
	}
	if(n==1)
	{
		if(a[1]==k)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	else if(n==2)
	{
		if(a[1]==a[2])
		{
			if(a[1]!=0)
				cout<<1;
			else
				cout<<2;
		}
		else
		{
			if(a[1]==0||a[2]==0)
				cout<<1;
			else
				cout<<0;
		}
		return 0;
	}
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==k)
			ans++;
	}
	for(i=1; i<=n; i++)
	{
		bool num = sum[i]&&k;
		for(j=x+1; j<i; j++)
		{
			num =max(num, sum[x]|sum[j]&&k);
			if(num)
			{
				x=j;
				break;
			}
		}	
		dp[i]=max(dp[i-1], dp[i-x]+num);
	}
	cout<<max(ans, dp[n]);
	return 0;
}
