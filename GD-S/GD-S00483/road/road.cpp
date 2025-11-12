#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+9,K=12;
ll n,m,k;
struct bian
{
	ll u,v,w;
};
vector<bian>b,b0;
bool cmp(bian x,bian y)
{
	return x.w<y.w;
}
ll c[K],a[K][N],tot;
ll fa[N];
ll fz(ll x)
{
	while(x!=fa[x])x=fa[x]=fa[fa[x]]; 
	return x;
}
ll kruskal(ll nn)
{
	for(int i=1;i<=nn;i++)
	fa[i]=i;
/*	for(int i=1;i<=tot;i++)
	{
		printf("%lld %lld %lld\n",b[i].u,b[i].v,b[i].w);
	}*/
	sort(b.begin(),b.end(),cmp);
	ll cnt=0,ans=0;
	for(auto t:b)
	{
		ll fu=fz(t.u),fv=fz(t.v);
		if(fu==fv)continue;
		ans+=t.w;
		cnt++;
		fa[fu]=fv;
		if(cnt==nn-1)break;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		b0.push_back((bian){u,v,w});
	}
	tot=m;
	if(k==0)
	{
		b=b0;
		printf("%lld\n",kruskal(n));
		return 0;
	}
	bool subA=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i])subA=0;
		for(int j=1;j<=n;j++)
		scanf("%lld",&a[i][j]);
	}
	b=b0;
	ll ans=kruskal(n);
	for(int s=1;s<(1<<k);s++)
	{
		ll sum=0,g=0;
		tot=m;
		b=b0;
		for(int i=0;i<k;i++)
		{
			if((s>>i)&1)
			{
				g++;
				sum+=c[i+1];
				for(int j=1;j<=n;j++)
				b.push_back((bian){n+g,j,a[i+1][j]});
			}
		}
		ll ret=kruskal(n+g)+sum;
		ans=min(ans,ret);
	}
	printf("%lld",ans);
	return 0;
}
