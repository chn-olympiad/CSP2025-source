#include<bits/stdc++.h>
using namespace std;
int n;
int a[5100]={0};
int b[100]={0};
long long dp[5100]={0};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(maxa==1)
	{
		dp[0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>=1;j--)
			{
				dp[j]+=dp[j-1];
				dp[j]%=998244353;
			}
		}
		long long ans=0;
		for(int i=3;i<=n;i++)
		{
			ans=(ans+dp[i])%998244353;
		}
		cout<<ans;
	}
	else if(n<=20)
	{
		int ans=0;
		for(int i=1;i<(1<<n);i++)
		{
			int j=i,m=0,k=0;
			while(j)
			{
				k++;
				if(j%2==1)
				{
					b[++m]=a[k];
				}
				j/=2;
			}
			if(m>=3)
			{
				int maxa=0,ans1=0;
				for(int i=1;i<=m;i++)
				{
					maxa=max(maxa,b[i]);
					ans1+=b[i];
				}
				if(maxa*2<ans1)ans++;
			}
		}
		cout<<ans;
	}
}
