#include<bits/stdc++.h>
using namespace std;
long long n,k,a,x[1010][1010],dp[1010][1010],l,r;
long long f(long long xx,long long yy)
{
	long long ans=0,an,logx=0,logy=0,squ=1,pow[30],p=1;
	memset(pow,sizeof(pow),0);
	while(xx>=squ||yy>=squ)
	{
		logx+=(xx>=squ);
		logy+=(yy>=squ);
		squ*=2;
	}
	an=xx&yy;
	for(int i=1;i<=max(logx,logy);i++)
	{
		if(an%2==0)
		{
			pow[i]=1;		
		}
		an/=2;
	}
	for(int i=1;i<=max(logx,logy);i++)
	{
		if(pow[i]==1)
		{
			ans+=p;
		}
		p*=2;
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i][i];
		if(x[i][i]==k)
		{
			dp[i][i]++;
		}
		for(int j=i-1;j>=1;j--)
		{
			x[j][i]=f(x[j][i-1],x[i][i]);
			if(x[j][i]==k)
			{
				dp[j][i]=1;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			l=j;
			r=l+i-1;
			for(int k=0;k<i-1;k++)
			{
				dp[l][r]=max(dp[l][r],dp[l][l+k]+dp[l+k+1][r]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}
