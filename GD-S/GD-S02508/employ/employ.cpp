#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n,m,c[1000009],sw,dp[2][109][109][109],a[100009],C[1009][1009];
string s;
int main()
{
	C[0][0]=1;
	for(int i=1;i<=1000;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]%=mod;
		}
	}
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
	}
	for(int i=2;i<=n;++i)
	{
		for(int j=i-1;j>=1;--j)
		{
			if(c[j]>c[j+1])
			{
				sw=c[j];
				c[j]=c[j+1];
				c[j+1]=sw;
			}
		}
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(c[j]<=i)++a[i];
		}
	}
	dp[0][0][0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=n;++j)
		{
			for(int k=0;k<=n;++k)
			{
				for(int l=0;l<=n;++l)
				{
					if(s[i-1]=='0')
					{
						if(k>0)dp[1][j+1][k-1][l]+=dp[0][j][k][l]*k;
						if(l>0)dp[1][j+1][k][l-1]+=dp[0][j][k][l]*l;
					}
					else
					{
						if(k>0)dp[1][j+1][k-1][l]+=dp[0][j][k][l]*k;
						if(l>0)dp[1][j][k][l-1]+=dp[0][j][k][l]*l;
					}
				}
			}
		}
		for(int j=0;j<=n;++j)
		{
			for(int k=0;k<=n;++k)
			{
				for(int l=0;l<=n;++l)
				{
					dp[1][j][k][l]%=mod;
					dp[0][j][k][l]=dp[1][j][k][l];
				}
			}
		}
	}
	return 0;
}
