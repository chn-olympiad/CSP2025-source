#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,m,dp[262144][18],c[510],ll,w[18],ps,ans=0;
char s[510];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	if(n<=18)
	{
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++)
		{
		ll=i;ps=0;
		while(ll)ps+=ll&1,ll>>=1;
		for(int k=0;k<n-1;k++)
		{
			if(dp[i][k]==0)continue;
			for(int j=0;j<n;j++)
				if(((i>>j)&1)==0)
				{
					if(s[ps]=='0' || ps-k>=c[j])
						dp[i|(1<<j)][k]=(dp[i|(1<<j)][k]+dp[i][k])%mod;
					else
						dp[i|(1<<j)][k+1]=(dp[i|(1<<j)][k+1]+dp[i][k])%mod;
				}
		}
		}
		for(int i=m;i<n;i++)
			ans=(ans+dp[(1<<n)-1][i])%mod;
		cout<<ans;
	}
}
