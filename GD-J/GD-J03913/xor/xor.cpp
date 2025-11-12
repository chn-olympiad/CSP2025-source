#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000010],dp[1000010],ma;
long long b[1000010],c[1000010],j,y;
long long yihuo(long long a,long long b)
{
	long long x=0,y=1;
	while(a>0||b>0) 
	{
		if(a%2!=b%2) x+=y;
		a/=2;b/=2;y=y*2; 
	}
	return x;
}
long long fyh(long long a,long long b)
{
	long long x=0,y=1;
	while(a>0||b>0) 
	{
		if(a%2==0) x+=(b%2)*y;
		else x+=(1-b%2)*y;
		a/=2;b/=2;y=y*2; 
	}
	return x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=yihuo(b[i-1],a[i]);
	memset(c,-1,sizeof(c));c[0]=0;
	for(int i=1;i<=n;i++)
	{
		y=fyh(k,b[i]);j=c[y];dp[i]=dp[i-1];
		if(a[i]==k) dp[i]=dp[i-1]+1;
		if(j>=0) dp[i]=max(dp[j]+1,dp[i]);
		c[b[i]]=i;
		ma=max(ma,dp[i]);
	}
	cout<<dp[n];
	return 0;
}
