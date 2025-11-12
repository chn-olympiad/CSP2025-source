#include<bits/stdc++.h>
using namespace std;
long long n,k,dp[1000005],x[1000005],ma,xx,a[1000005];
string s,ss;
long long xxor(long long q,long long w)
{
	long long s=0,u=0;
	while(q!=0||w!=0)
	{
		long long p=abs((w%2)-(q%2));
		u=u+p*pow(2,s);
		s++;
		w/=2,q/=2;
	}
	return u;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		xx=xxor(xx,a[i]);
		x[i]=xx;
		if(a[i]==k)dp[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(dp[i]==1)
		{
			dp[i]=dp[i-1]+1;
			continue;
		}
		for(int j=1;j<i;j++)
		{
			dp[i]=max(dp[i],dp[j]);
			if(abs(x[i]-x[j-1])!=k)continue;
			else dp[i]=max(dp[i],dp[j-1]+1);
		}
	}
	cout<<dp[n];
	return 0;
}
