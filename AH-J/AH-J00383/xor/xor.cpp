#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005],dp[500005],vmax;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	cin>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	if(n>10000)
	{
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			cnt=cnt^a[i];
			if(cnt==k)
			{
				cnt=0;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((s[j]^s[i-1])==k)
			{
				if(dp[j]==0)
				{
					dp[j]=1;
				}
				for(int l=1;l<i;l++)
				{
					dp[j]=max(dp[j],dp[l]+1);
				}
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		vmax=max(vmax,dp[i]);
	}
	cout<<vmax;
	return 0;
}
