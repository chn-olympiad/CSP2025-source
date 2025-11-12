#include<bits/stdc++.h>
using namespace std;

string s;
long long mod=998244353;
long long n,m,a[505],dp[505];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=(dp[i-1]*i)%mod;
	}
	cout<<dp[n];
	return 0;
}
