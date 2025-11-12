#include<bits/stdc++.h>
using namespace std;
int mod=998244353,n,a[5001],m=0,dp[25000001],s=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n,dp[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		m=m+a[i];
		for(int j=m;j>=a[i];j--)
		{
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
			if(j>2*a[i])
				s=(s+dp[j-a[i]])%mod;
		}
	}
	cout<<s;
	return 0;
}
