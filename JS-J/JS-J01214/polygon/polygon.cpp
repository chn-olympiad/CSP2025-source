#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=5e3+1;
ll n,a[N],cnt;
bool f[N];
ll ans,t,mx;

void dfs(ll dep,ll zong,ll da,ll t)
{
	if(dep>3)
	{
		if(zong>da*2) ++ans;
		ans%=998244353;
	}
	if(dep>n) return ;
	for(ll i=t+1;i<=n;++i)
	{
		if(!f[i])
		{
			f[i]=1;
			dfs(dep+1,zong+a[i],max(da,a[i]),i);
			f[i]=0;
		}
	}
}

ll jc_lf(ll x)
{
	if(x==0) return 1;
	ll qwq=1;
	for(ll i=2;i<=x;++i) qwq*=i;
	return qwq;
}

int main()
{//byd ji de bu quan freopen,bing qu xiao zhu shi aaa
	freopen("polygon.in","r",stdin);
	freopen("poligon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i)
		scanf("%lld",a+i),cnt+=(a[i]==1);
	if(cnt==n)
	{
		for(ll i=3;i<=n;++i)
		{
			ll mi_lf=1,mm_lf=1;
			mi_lf=jc_lf(n);
			mm_lf=jc_lf(i)*jc_lf(n-i);
			ans+=(mi_lf/mm_lf)%998244353;
		}
		printf("%lld\n",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n-2;++i) f[i]=1,dfs(2,a[i],a[i],i),f[i]=0;
	printf("%lld\n",ans);
	return 0;
}
/*
* 09:54 a=1 pian fen wan cheng
* 10:09 wan cheng bao li qiu jie
* +64pts(?)gen ju ce shi dian shi zhe me duo
* yao me jiu shi 50+
* yin wei a=1 ye ke neng yi chu,C
*/
