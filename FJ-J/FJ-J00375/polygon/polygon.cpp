#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[10000],ans=0,dfn[100],sum1,sum2,maxx,dp[25000001];
const ll mod=998244353;
void solve1()
{
	sum2=0;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		sum2+=a[i];
		for(int j=sum2-a[i];j>=0;j--)
		{
			if(j>=a[i-1])
			{
				dp[j]=dp[j]+dp[j-a[i-1]];
				dp[j]%=mod;
			}
		}
		if(i<3)
		{
			continue;
		}
		if(sum2-2*a[i]<=0)
		{
			continue;
		}
		//cout<<i<<" "<<sum2-2*a[i]<<" ";
		for(int j=0;j<sum2-2*a[i];j++)
		{
			ans+=dp[j];
			ans%=mod;
		}
		//cout<<ans<<endl;
	}
	cout<<ans/2;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum1+=a[i];
	}
	sort(a+1,a+1+n);
	solve1();
	return 0;
}
/*
5
2 2 3 8 10
*/
