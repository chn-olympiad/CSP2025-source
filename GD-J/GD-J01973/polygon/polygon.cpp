#include<bits/stdc++.h>
using namespace std;
const int N=5007;
long long f[N];
const long long mod=998244353;
long long a[N];
int n;
long long mx;
long long MAX(long long x,long y)
{
	if(x>y)
	return x;
	else
	return y;
}
long long qpow(long long x,long long y)
{
	long long res=1;
	while(y)
	{
		if(y&1)
		res=res*x%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mx=MAX(mx,a[i]);
	}
	sort(a+1,a+n+1);
	long long ans=0;
	f[a[1]]=1;
	for(int i=2;i<=n;i++)
	{
		long long res=qpow(2,(i-1));
		for(int j=0;j<=a[i];j++)
		{
			if(f[j])
			res=(res-f[j]+mod)%mod;
		}
		ans=(ans+res)%mod;
		for(int j=mx;j>=0;j--)
		{
			if(j>=a[i])
			f[j]=(f[j]+f[j-a[i]])%mod;
		}
	}
	printf("%lld",ans);
	return 0; 
}

