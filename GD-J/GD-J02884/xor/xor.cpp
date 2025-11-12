#include<bits/stdc++.h>
using namespace std;

int n,k,a[500001],sum[500001],dp[500001],use[500001],flag,flag2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)flag=1;
		if(a[i]!=1 && a[i]!=0)flag2=1;
	}
	if(!flag)
	{
		if(k>1)
		{
			cout<<0;
			return 0;
		}
		if(k==1)
		{
			cout<<n;
			return 0;
		}
		if(k==0)
		{
			cout<<n/2;
			return 0;
		}
	}
	else if(!flag2)
	{
		if(k>1)
		{
			cout<<0;
			return 0;
		}
		if(k==1)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)cnt++;
			}
			cout<<cnt;
			return 0;
		}
		if(k==0)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)cnt++;
				if(i>1 && a[i]==1 && a[i-1]==1 && !use[i-1])
				{
					cnt++;
					use[i]=use[i-1]=1;
				}
			}
			cout<<cnt;
			return 0;
		}
	}
	else
	{
		int r=0;
		for(int i=1;i<=n;i++)sum[i]=a[i]^sum[i-1]; 
		for(int i=1;i<=n;i++)
		{
			int tmp=sum[i]^k;
			dp[i]=dp[i-1];
			for(int j=i-1;j>=r;j--)//找到可以抵消的 
			{
				if(sum[j]==tmp && dp[i]<dp[j]+1)
				{
					dp[i]=dp[j]+1;
					r=i;
				}
			}
		}
		cout<<dp[n]<<endl;
	}
}

