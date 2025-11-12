#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool flag1=true,flag2=true;
	cin>>n>>k;
	int a[500001]={0},xorsum[500001]={0},dp[500001]={0},maximum=0,tg=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		xorsum[i]=xorsum[i-1]^a[i];
		if(a[i]!=1)flag1=false;
		if(a[i]>1)flag2=false;
	}
	if(k==0 && flag1)
	{
		cout<<n/2;
		return 0;
	}
	if(k<=1 && flag2)
	{
		if(k==0)
		{
			int ans=0;
			bool tag=false;
			for(int i=1;i<=n;i++)
			{
				if(a[i]+a[i-1]==2)
				{
					if(tag==false)
					{
						ans++;
						tag=true;
						continue;
					}
				}
				tag=false;
				if(a[i]==0)ans++;
			}
			cout<<ans;
			return 0;
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=a[i];
			}
			cout<<ans;
			return 0;
		}
	}
	dp[0]=0;
	dp[n]=0;
	for(int i=1;i<=n;i++)
	{
		bool f=false;
		int j;
		for(j=i;j>tg;j++)
		{
			if(xorsum[i]^xorsum[j-1]==k)
			{
				f=true;
				break;
			}
		}
		dp[i]=maximum;
		if(f)
		{
			dp[i]=max(dp[i],dp[j]+1);
			tg=i+1;
		}
		maximum=max(maximum,dp[i]);
	}
	cout<<dp[n];
	return 0;
}
