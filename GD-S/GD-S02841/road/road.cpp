#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
struct node
{
	ll s,t,v;
}l[100005],r[1000005];
bool cmp(node x,node y)
{
	return x.v<y.v;
}
ll n,m,k;
ll c[15];
ll moy=1e18;
ll k1,k2;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){scanf("%lld%lld%lld",&r[i].s,&r[i].t,&r[i].v);if(r[i].s>r[i].t)swap(r[i].s,r[i].t);}
	sort(r+1,r+1+m,cmp);
	for(ll i=0;i<k;i++)
	{
		scanf("%lld",&c[i+1]);
		for(ll j=1;j<=n;j++)
		{
			scanf("%lld",&l[i*n+j].v);
			l[i*n+j].s=i+n+1;
			l[i*n+j].t=j;
		}
	}
	sort(l+1,l+1+k*n,cmp);
	l[k*n+1]={0,0,(ll)(1e18)};
	r[m+1]={0,0,(ll)(1e18)};
	for(ll j=0;j<(1<<k);j++)
	{
		ll cnt=n-1,ans=0;
		ll ft[10015];
		for(ll i=1;i<=n+k;i++)ft[i]=i;
		for(ll i=1;i<=k;i++)
		{
			if((j&(1<<(i-1)))>0)
			{
				cnt++;
				ans+=c[i];
			}
		}
		ll x=1,y=1;
		while(cnt)
		{
			if(l[x].v<r[y].v)
			{
				if((((1<<(l[x].s-n-1))&j)==0)||ft[l[x].s]==ft[l[x].t])x++;
				else
				{
					ft[l[x].t]=ft[l[x].s];
					ans+=l[x].v,x++,cnt--;
					//cout<<"x = "<<x<<'\n';
				}
			}
			else
			{
				if(ft[r[y].s]==ft[r[y].t])y++;
				else ft[r[y].t]=ft[r[y].s],ans+=r[y].v,y++,cnt--/*,cout<<"y = "<<y<<'\n'*/;
			}
		}
		//cout<<ans<<'\n';
		moy=min(moy,ans);
	}
	printf("%lld",moy);
	
	return 0;
}
