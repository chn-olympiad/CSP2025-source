#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char st;
const ll mod=998244353;
ll ans,fac[5005],inv[5005];
int n,a[5005],g[5005][5005],f[5005][10005];
ll add(ll x,ll y){return x+y>=mod?x+y-mod:x+y;}
ll Pow(ll x,ll y)
{
	ll a=1;
	while(y)
	{
		if(y&1ll)
			a=a*x%mod;
		x=x*x%mod;y>>=1ll;
	}
	return a;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<=5000;i++)
		fac[i]=fac[i-1]*i%mod;
	inv[5000]=Pow(fac[5000],mod-2);
	for(int i=4999;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(ll x,ll y)
{
	if(x<0||x<y)
		return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
char en;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	cerr<<(&st-&en)/1024.0/1024.0<<"\n"; 
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++)
		ans=add(ans,C(n,i));
//	cout<<ans<<"\n";
	g[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=5000;j++)
			g[i][j]=add(g[i][j],g[i-1][j]);
		for(int j=0;j+a[i]<=5000;j++)
			g[i][j+a[i]]=add(g[i][j+a[i]],g[i-1][j]);
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=10000;j++)
			f[i][j]=add(f[i][j],f[i-1][j]);
		for(int j=0;j<=a[i];j++)
			f[i][j+a[i]]=add(f[i][j+a[i]],g[i-1][j]);
	}
//	cout<<f[4][15]<<" No\n";
//	for(int i=0;i<=25;i++)
//		cout<<f[n][i]<<" ";
//	cout<<"\n";
	for(int i=0;i<=10000;i++)
		ans=add(ans,mod-f[n][i]);
	printf("%lld",ans);
	return 0;
}
