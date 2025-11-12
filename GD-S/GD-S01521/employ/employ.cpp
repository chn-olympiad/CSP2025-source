#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
using ll=long long;
constexpr int N=500,MOD=998244353;
ll ksm(ll x,ll y=MOD-2)
{
	ll res=1;
	while(y)
	{
		if(y&1) res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return res;
}
int n,m;
char s[N+5];
int c[N+5];
int p[N+5];
int a[N+5];
int v[N+5];
ll f[N+5][N+5];
ll g[N+5][N+5];
ll fac[N+5];
ll ifac[N+5];
ll C(int n,int m)
{
	if(n<0||m<0||n<m) return 0;
	return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
ll ans;
int main()
{
	fac[0]=1;
	fr(i,1,N) fac[i]=fac[i-1]*i%MOD;
	fr(i,0,N) ifac[i]=ksm(fac[i]);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	fr(i,1,n) scanf("%d",&c[i]),++v[c[i]];
	a[0]=v[0];
	fr(i,1,n) a[i]=a[i-1]+v[i];
	if(n<=10)
	{
		iota(p+1,p+1+n,1);
		while(1)
		{
			int x=0;
			fr(i,1,n) if(s[i]=='0'||c[p[i]]<=x) ++x;
			if(x<=n-m) ++ans;
			if(!next_permutation(p+1,p+1+n)) break;
		}
		printf("%lld\n",ans);
	}
	else
	{
		f[0][0]=1;
		fr(i,0,n-1)
		{
			fr(j,0,i)
			{
				fr(x,0,i)
				{
					fr(y,0,min(x,v[j+1])) (g[j+1][x-y]+=C(x,y)*C(v[j+1],y)%MOD*fac[y]%MOD*(a[j]-(i-x))%MOD*f[j][x])%=MOD;
					(g[j][x+1]+=f[j][x])%=MOD;
				}
			}
			memcpy(f,g,sizeof(f));
			memset(g,0,sizeof(g));
		}
		fr(j,0,n-m)
		{
			ll sum=f[j][n-a[j]];
			int num=n-a[j];
			fr(k,j+1,n)
			{
				(sum*=C(num,v[k])*fac[v[k]]%MOD)%=MOD;
				num-=v[k];
			}
			(ans+=sum)%=MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}