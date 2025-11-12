#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,ans=1e18,cnt=0,sum[(1<<10)+1],c[15],a[15][10005],fa[10005];
int zfa[(1<<10)+1][10015];
struct node
{
	ll x,y,w;
	int zt;
}s[1000005],ns[110005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
int zfind(int zt,int x)
{
	if(zfa[zt][x]==x)
	{
		return x;
	}
	return zfa[zt][x]=zfind(zt,zfa[zt][x]);
}
void kruskal()
{
	for(ll i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(ll i=1;i<=m;i++)
	{
		ll x=s[i].x,y=s[i].y,w=s[i].w,fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			cnt++;
			ns[cnt].x=x;
			ns[cnt].y=y;
			ns[cnt].w=w;
			ns[cnt].zt=0;
		}
	}
	return;
}
void ts_kruskal()
{
	for(int zt=0;zt<(1<<k);zt++)
	{
		for(int i=1;i<=n+k;i++)
		{
			zfa[zt][i]=i;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		ll x=ns[i].x,y=ns[i].y,w=ns[i].w,zt=ns[i].zt;
		for(int nzt=0;nzt<(1<<k);nzt++)
		{
			if((nzt&zt)==zt)
			{
				int fx=zfind(nzt,x),fy=zfind(nzt,y);
				if(fx!=fy)
				{
					zfa[nzt][fx]=fy;
					sum[nzt]+=w;
				}
			}
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>s[i].x>>s[i].y>>s[i].w;
	}
	for(int x=1;x<=k;x++)
	{
		cin>>c[x];
		for(int y=1;y<=n;y++)
		{
			ll w;
			cin>>w;
			cnt++;
			ns[cnt].x=x+n;
			ns[cnt].y=y;
			ns[cnt].w=w;
			ns[cnt].zt=(1<<(x-1));
		}
	}
	sort(s+1,s+m+1,cmp);
	kruskal();
	sort(ns+1,ns+cnt+1,cmp);
	for(int zt=0;zt<(1<<k);zt++)
	{
		for(int i=0;i<k;i++)
		{
			if((zt&(1<<i))!=0)
			{
				sum[zt]+=c[i+1];
			}
		}
	}
	ts_kruskal();
	for(int zt=0;zt<(1<<k);zt++)
	{
		ans=min(ans,sum[zt]);
	}
	cout<<ans;
	return 0;
}
