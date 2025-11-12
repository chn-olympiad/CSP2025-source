#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],maxn;
int dp[5005][5005];
void init()
{
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
		}
	}
}
int c(int x,int y)
{
	return dp[x+1][y+1];
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=2)//?
	{
		cout<<0;
		return 0;
	}
	else if(n==3)//12
	{
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3]))
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	else if(maxn==1)//24
	{
		int ans=0;
		init();
		for(int i=3;i<=n;i++)
		{
			ans+=c(n,i);
		}
		cout<<ans;
		return 0;
	}
	else if(n<=20)//28
	{
		int t[35],ans=0;
		for(int p=0;p<1<<n;p++)
		{
			int pp=p;
			int sum=0,maxnum=0;
			for(int i=1;i<=n;i++)
			{
				t[i]=pp&1;
				pp>>=1;
				if(t[i]==1)
				{
					sum+=a[i];
					maxnum=max(maxnum,a[i]);
				}
			}
			if(sum>2*maxnum)
			ans++;
		}
		cout<<ans%mod;
		return 0;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
/*
5
2 2 3 8 10
*/
