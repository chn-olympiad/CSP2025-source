#include<bits/stdc++.h>
using namespace std;
long long n,k,maxx,a[500005],f[500005],dp[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1)
		{
			dp[i]=(dp[i-1]^a[i]);
		}
		else
		{
			dp[1]=a[1];
		}
		if(dp[i]==k)
		{
			f[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			if((dp[i]^dp[j])==k)
			{
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,f[i]); 
	}
	cout<<maxx;
	return 0;
}