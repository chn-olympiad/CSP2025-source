#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,x,y,z,c[10005],a[10][10005],tot=1;
ll f[10005];
struct road
{
	ll xu,xv,weigh;
}t[400005];
void add(ll u,ll v,ll w)
{
	t[++tot]={u,v,w};
}
void init()
{
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(ll i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	for(ll i=1;i<=n;i++)
		f[i]=i;
}
bool cmp(road x,road y)
{
	return x.weigh<y.weigh;
}
ll find(ll x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
init();
if(k==0)
{
	ll ans=0;
	sort(t+1,t+tot+1,cmp);
	for(ll i=1;i<=tot;i++)
	{
		ll ii,jj;
		ii=find(t[i].xu);
		jj=find(t[i].xv);
		if(ii!=jj)
		{
			f[ii]=jj;
			ans+=t[i].weigh;	
		}
	}
	printf("%lld",ans);
}
fclose(stdin);
fclose(stdout);
	return 0;
}

