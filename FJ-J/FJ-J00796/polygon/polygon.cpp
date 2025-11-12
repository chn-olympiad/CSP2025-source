#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long b[5005];
bool c[5005];
long long s;
void pd(int n)
{
	long long maxx=INT_MIN,mun=0;
	for(int i=1;i<n;i++)
	{
		mun+=a[b[i]];
		maxx=max(maxx,a[b[i]]);
	}
	if(mun>(2*maxx))
	{
		s=(s+1)%998244353;
	}
}
void fun(int k,int m)
{
	if(k==m+1)
	{
		pd(k);
		return;
	}
	for(int i=b[k-1]+1;i<=n;i++)
	{
		if(c[i]==0)
		{
			b[k]=i;
			c[i]=1;
			fun(k+1,m);
		}
		c[i]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1)
			f=0;
	}
	if(f==1)
	{
		for(int i=3;i<=n;i++)
		{
			long long h=1;
			for(int j=0;j<i;j++)
			{
				h=(h*(n-j))%998244353;
			}
			for(int j=2;j<=i;j++)
			{
				h/=j;
			}
			s=(s+h)%998244353;
		}
		printf("%lld",s);
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		fun(1,i);
	}
	printf("%lld",s);
	return 0;
}
