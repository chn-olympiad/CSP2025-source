#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long t,n,a[5010],mx,f[5010][5010];
struct w{
	long long x,y;
}g[5010];
long long mi(long long x,long long y)
{
	long long s=1;
	while(y)
	{
		if(y%2)
			s=s*x%mod;
		x=x*x%mod;
		y=y/2;
	}
	return s;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
		if(g[t].x!=a[i])
		{
			g[++t].x=a[i];
			g[t].y=1;
		}
		else
			g[t].y++;
	f[0][0]=1;
	for(long long i=1;i<=t;i++)
	{
		for(long long j=0;j<=mx;j++)
		f[i][j]=(f[i][j]+f[i-1][j])%mod;
		for(long long k=1;k<=g[i].y;k++)
		for(long long j=mx;j>=g[i].x;j--)
			f[i][j]=(f[i][j-g[i].x]+f[i][j])%mod;
	}
//	cout<<f[1][0]<<endl;
	for(long long i=0;i<=t;i++)
		for(long long j=1;j<=mx;j++)
			f[i][j]=(f[i][j]+f[i][j-1])%mod;
	long long s=0,ss=0;
	for(long long i=1;i<=t;i++)
	{
		s=(s+(((mi(2,g[i].y)-1-g[i].y)%mod+mod)%mod*(((mi(2,ss)-f[i-1][0])%mod+mod)%mod))%mod)%mod;
	//	cout<<s<<" ";
		s=(s+(g[i].y*(((mi(2,ss)-f[i-1][g[i].x])%mod+mod)%mod)%mod))%mod;
	//	cout<<s<<" "<<i-1<<" "<<g[i].x+1<<" "<<mi(2,ss)<<" "<<f[i-1][g[i].x]<<endl; 
		s=(s+((mi(2,g[i].y)-1-g[i].y-((g[i].y)*(g[i].y-1)%mod*mi(2,mod-2)%mod))%mod+mod)%mod)%mod;
		ss=ss+g[i].y;
	}
	printf("%lld\n",s);
	return 0;
}
