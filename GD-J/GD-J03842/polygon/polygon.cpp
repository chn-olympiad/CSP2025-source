#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const long long mod=998244353;
int n;
long long a[110000];
long long f[510][510];
long long qpow(long long a,long long b)
{
	long long s=1;
	while(b)
	{
		if(b&1) s=s*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return s;
}
long long dfs(int n,int s,int max_l)
{
	if(s<=500&&f[n][s]!=-1) return f[n][s];
	if(s>max_l)
	{
		return 0;
//		return qpow(2,n);
	}
	if(s==max_l)
	{
		return 1;
//		return ((qpow(2,n)-1)%mod+mod)%mod;
	}
	if(n<=0) return 1;
	if(s<=500)
	{
		return f[n][s]=(dfs(n-1,s+a[n],max_l)+dfs(n-1,s,max_l))%mod;
	}
	return (dfs(n-1,s+a[n],max_l)+dfs(n-1,s,max_l))%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	bool t=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1) t=false;
	}
	if(t)
	{
		printf("%lld\n",((qpow(2,n)-n-n*(n-1)/2)%mod+mod)%mod);
		return 0;
	}
	sort(a+1,a+1+n);
	long long sum=0;
	for(int i=3;i<=n;i++)
	{
//		printf("%d\n",i);
		memset(f,-1,sizeof(f));
		sum=(sum+qpow(2,i-1)-dfs(i-1,0,a[i]))%mod;
	}
	printf("%lld",sum);
}

