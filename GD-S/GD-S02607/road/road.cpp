#include<bits/stdc++.h>
#define ll long long



using namespace std;

const ll N=2e6+10;

ll n,m,k;
struct e{
	ll x,y,z;
}a[N];
ll c[N];
ll w[N];
ll to[1001][1001];

bool cmp(e x,e y)
{
	return x.z<y.z;
}

ll fa[N];

ll fd(ll x)
{
	return fa[x]==x?x:fa[x]=fd(fa[x]);
}

ll ans=0;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&m,&k);
	if(n<=1000)
	{
		for(ll i=1;i<=n;++i)
		{
			for(ll j=1;j<i;++j)
			{
				to[j][i]=-1;
			}
		}
	}
	
	for(ll i=1;i<=n;++i) fa[i]=i;
	for(ll i=1;i<=m;++i)
	{
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		ll xx=a[i].x;
		ll yy=a[i].y;
		if(xx>yy) swap(xx,yy);
		if(n<=1000) to[xx][yy]=a[i].z;
	}
	
	if(k==0)
	{
		int o=0;
		sort(a+1,a+m+1,cmp);
		ans=0;
		for(ll i=1;i<=m;++i)
		{
			ll xx=fd(a[i].x);
			ll yy=fd(a[i].y);
			if(xx!=yy)
			{
				fa[xx]=yy;
				ans+=a[i].z;
				++o;
				if(o==n-1) break;
			}
		}
		printf("%lld",ans);
	}
	else
	{
		for(ll i=1;i<=k;++i)
		{
			scanf("%lld",&c[i]);
			for(ll j=1;j<=n;++j)
			{
				scanf("%lld",&w[j]);
				for(ll l=1;l<j;++l)
				{
					if(to[l][j]!=-1) to[l][j]=min(to[l][j],w[l]+w[j]+c[i]);
					else to[l][j]=w[l]+w[j]+c[i];
				}
			}
		}
		for(ll i=1;i<=n;++i)
		{
			for(ll j=1;j<i;++j)
			{
				//printf("%lld %lld %lld\n",j,i,to[j][i]);
				if(to[j][i]!=-1)
				{
					++m;
					a[m]={j,i,to[j][i]};
				}
			}
		}
		
		sort(a+1,a+m+1,cmp);
		ans=0;
		ll o=0;
		for(ll i=1;i<=m;++i)
		{
			ll xx=fd(a[i].x);
			ll yy=fd(a[i].y);
			if(xx!=yy)
			{
				fa[xx]=yy;
				ans+=a[i].z;
				++o;
				//printf("%lld %lld %lld\n",a[i].x,a[i].y,a[i].z);
				if(o==n-1) break;
			}
		}
		printf("%lld",ans);
		
	}
	
	return 0;
}
