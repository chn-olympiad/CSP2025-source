#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
long long fac[5005],ifac[5005];
long long power(long long x,int y)
{
	if(y==0)
		return 1;
	long long k=power(x,y/2);
	return ((k*k)%mod)*(y&1?x:1)%mod;
}
long long inv(int x)
{
	return power(x,mod-2);
}
long long c(int x,int y)
{
	return (fac[x]*ifac[y]%mod)*ifac[x-y]%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=5000;i++)
		fac[i]=fac[i-1]*i%mod;
	ifac[5000]=inv(fac[5000]);
	for(int i=4999;i>=0;i--)
		ifac[i]=ifac[i+1]*(i+1)%mod;
	scanf("%d",&n);
	bool s=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)
			s=0;
	}	
	if(n<3)
	{
		printf("0");
		return 0;
	}
	if(n==3)
	{
		int sum=0,maxn=-1e9;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
			sum+=a[i]; 
		}
		if(sum>maxn*2)
			printf("1");
		else
			printf("0");
		return 0;
	}
	if(s)
	{
		long long sum=0;
		for(int i=3;i<=n;i++)
			sum=(sum+c(n,i))%mod;
		printf("%lld",sum);
	}
	else
		printf("0");
	return 0;
}
