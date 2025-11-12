#include <iostream>
#include <cstdio>
#define MOD (998244353)

using namespace std;

long long n,a[5010],cnt,maxnn;

long long mpow(long long a,long long b)
{
	if(b==0)return 1;
	long long t=mpow(a,b>>1)%MOD;
	if(b&1)return t*t%MOD*a%MOD;
	else return t*t%MOD;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		maxnn=max(maxnn,a[i]);
	}
	if(maxnn==1)
	{
		cout<<max(0ll,(mpow(2,n)-(n*(n-1)/2)%MOD-n-1)%MOD);
		return 0;
	} 
	for(long long i=0;i<(1<<n);i++)
	{
		long long c=i,id=1,sum=0,maxn=0;
		while(c!=0)
		{
			if(c&1)
			{
				sum+=a[id];
				maxn=max(maxn,a[id]);
			}
			c>>=1;
			id++;
		}
		if(sum>2*maxn)cnt++;
	}
	cout<<cnt;
}
/*#include <iostream>

using namespace std;

long long n,a[5010],f[5010][10010],s[10010],d[10010],m;

long long main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		m=max(m,a[i]);
	}
	for(long long i=0;i<=n;i++)f[i][0]=1;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=2*m;j++)
		{
			if(j>=a[i])f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
			else f[i][j]=f[i-1][j];
		}
	}
	s[0]=f[n][0];
	for(long long i=1;i<=2*m;i++)s[i]=s[i-1]+f[n][i];
	d[0]++;
	for(long long i=1;i<=n;i++)d[a[i]]++;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i+1;j<=n;j++)d[a[i]+a[j]]++;
	}
	long long now=0;
	for(long long i=0;i<=2*m;i++)
	{
		now+=d[i];
		d[i]=now;
	}
	for(long long i=0;i<=n;i++)
	{
		for(long long j=0;j<=2*m;j++)cerr<<f[i][j]<<" ";
		cerr<<endl;
	}
	for(long long i=0;i<=2*m;i++)cerr<<s[i]<<" "; cerr<<endl;
	for(long long i=0;i<=2*m;i++)cerr<<d[i]<<" "; cerr<<endl;
	for(long long i=0;i<=2*m;i++)cerr<<s[i]-d[i]<<" "; cerr<<endl;
} */
