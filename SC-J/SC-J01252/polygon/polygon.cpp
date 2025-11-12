#include<bits/stdc++.h>
#define int long long
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
using namespace std;
const int mod=998244353;
int n,a[5010],dp[5010],sum;
bool flag;
void dfs(int x,int y,int z)//x：上一个下标，y：最大值，z：个数
{
	for(int i=x+1;i<=n;i++)
	{
		sum+=a[i]; z++;
		if(a[i]>y)
		{
			if(sum>a[i]*2&&z>=3) dp[z]=(dp[z]+1+mod)%mod;
			dfs(i,a[i],z);
		}
		else
		{
			if(sum>y*2&&z>=3) dp[z]=(dp[z]+1+mod)%mod;
			dfs(i,y,z);
		}
		sum-=a[i]; z--;
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	I AK CSP
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=1) flag=true;
	}
	if(!flag)
	{
		for(int i=1;i<=n-2;i++) sum+=a[i],dfs(i,a[i],1),sum-=a[i];
		int ans=0;
		for(int i=3;i<=n;i++) ans=(ans+dp[i]+mod)%mod;
		cout<<ans;
	}
	else
	{
		int ans=1;
		for(int i=n;i>=n/2;i--)
		{
			sum=1;
			for(int j=n;j>=i;j--) sum=(sum*j+mod)%mod;
			ans=(ans+sum+mod)%mod;
		}
		cout<<(ans*2+mod)%mod;
	}
	return 0;
}