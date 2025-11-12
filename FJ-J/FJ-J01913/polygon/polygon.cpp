#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[21];
unsigned long long int f[10086]={};
int dp[21][1050000];
void jiecheng(int z)
{
	f[z]=f[z-1]*z,f[z]%=9982443453;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	f[1]=1;
	f[2]=2;
	int n,l=0;
	unsigned long long int ans=0,k=3;
	cin>>n;
	for(int u=1;u<=n;u++)
	cin>>a[u],l=max(a[u],l);
	sort(a+1,a+n+1);
	if(l==1)
	{
		while(n-k>0)
		{
			ans+=n-k,k++;
		}
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		dp[3][0]++;
		dp[3][dp[3][0]]=a[1]+a[2];
		for(int u=4;u<=n;u++)
		{
			dp[u][0]=dp[u-1][0]*2;
			for(int p=1;p<=dp[u-1][0];p++)
			dp[u][p]=dp[u-1][p];
			for(int p=dp[u-1][0]+1;p<=dp[u-1][0]*2;p++)
			{
				dp[u][p]=dp[u-1][p]+a[u-1];
			}
		}
		for(int u=3;u<=n;u++)
		{
			for(int p=1;p<=dp[u][0];p++)
			if(dp[u][p]>=a[u])
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
