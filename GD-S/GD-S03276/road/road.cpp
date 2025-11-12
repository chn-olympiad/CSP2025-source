#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
const int N=2e4+7,M=1e6+7;
struct Edge{
	int u;
	int v;
	int w;
}edge[M],ned[200010];
int cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int f[N],c[21];
struct I{
	int w[N];
}a[15]; 
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int use[15],cnt=0,maxn=1e18;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	sort(edge+1,edge+m+1,cmp);
	int len=(1<<k);
	bool p=1,pp=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i]) p=0;
		bool p1=0;
		for(int j=1;j<=n;j++) 
		{
			scanf("%lld",&a[i].w[j]);
			if(!a[i].w[j]) p1=1;
		}
		pp&=p1;
	}
	if(p&pp)
	{
		int i=len-1;
		int ans=0;
		cnt=0;
		int an=0;
		memset(use,0,sizeof(use));
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1))) 
			{
				use[j]=1;
				ans+=c[j];
				an++;
				for(int li=1;li<=n;li++)
				{
					ned[++cnt]=(Edge){an+n,li,a[j].w[li]};
				}
			}
		}
		for(int j=1;j<=n+an;j++) f[j]=j;
		int p=1,br=0;
		sort(ned+1,ned+cnt+1,cmp);
		for(int j=1;j<=m;j++)
		{
			while(ned[p].w<=edge[j].w&&p<=cnt)
			{
				if(find(ned[p].u)!=find(ned[p].v))
				{
					f[find(ned[p].u)]=find(ned[p].v);
					ans+=ned[p].w;
					br++;
				}
				p++;
			}
			if(br==n+an-1) break;
			if(find(edge[j].u)!=find(edge[j].v)) 
			{
				f[find(edge[j].u)]=find(edge[j].v);
				ans+=edge[j].w;
				br++;
			}
			if(br==n+an-1) break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<len;i++)
	{
		int ans=0;
		cnt=0;
		int an=0;
		memset(use,0,sizeof(use));
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1))) 
			{
				use[j]=1;
				ans+=c[j];
				an++;
				for(int li=1;li<=n;li++)
				{
					ned[++cnt]=(Edge){an+n,li,a[j].w[li]};
				}
			}
		}
		for(int j=1;j<=n+an;j++) f[j]=j;
		int p=1,br=0;
		sort(ned+1,ned+cnt+1,cmp);
		for(int j=1;j<=m;j++)
		{
			while(ned[p].w<=edge[j].w&&p<=cnt)
			{
				if(find(ned[p].u)!=find(ned[p].v))
				{
					f[find(ned[p].u)]=find(ned[p].v);
					ans+=ned[p].w;
					br++;
				}
				p++;
			}
			if(br==n+an-1) break;
			if(find(edge[j].u)!=find(edge[j].v)) 
			{
				f[find(edge[j].u)]=find(edge[j].v);
				ans+=edge[j].w;
				br++;
			}
			if(br==n+an-1) break;
		}
		maxn=min(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
