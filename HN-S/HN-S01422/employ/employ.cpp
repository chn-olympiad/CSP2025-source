#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[1100005][21],c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18)
	{
		dp[0][0]=1;
		for(int i=1;i<(1<<n);i++)
		{
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1))) cnt++;
			}
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1)))
				{
					for(int k=0;k<cnt;k++)
					{
						if(cnt-k>c[j])
						{
							dp[i][k]=(dp[i][k]+dp[i-(1<<(j-1))][k])%mod;
						}
						else if(s[cnt-1]=='0')
						{
							dp[i][k]=(dp[i][k]+dp[i-(1<<(j-1))][k])%mod;
						}
						else
						{
							dp[i][k+1]=(dp[i][k+1]+dp[i-(1<<(j-1))][k])%mod;
						}
					}
				}
			}
		}
		long long ans=0;
		for(int i=m;i<=n;i++) ans=(ans+dp[(1<<n)-1][i])%mod;
		cout<<ans;
		return 0; 
	}
	else if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
			{
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		long long ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	else
	{
		sort(c+1,c+n+1);
		long long ans=1,p=0,tp=1;
		for(int i=1;i<=n;i++)
		{
			while(tp<=n&&c[tp]<i) p++,tp++;
			if(s[i-1]=='1')
			{
				ans=ans*p%mod;
				p--;
			}
		}
		for(int i=1;i<=p;i++) ans=ans*i%mod;
		long long fac=1;
		for(int i=1;i<=n;i++) fac=fac*i%mod;
		cout<<(fac-ans+mod)%mod;
	}
	return 0;
}
