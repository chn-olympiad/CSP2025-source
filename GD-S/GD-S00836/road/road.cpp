#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+10,maxm=1e6+10;
int n,m,k,p,l,tot,ans=1e18;
int a[11][maxn],c[11],fa[maxn],idx[11];
struct edge
{
	int u,v,w;
}ee[maxm],e1[maxm],e2[maxm];
int get(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>ee[i].u>>ee[i].v>>ee[i].w;
	sort(ee+1,ee+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=get(ee[i].u),fy=get(ee[i].v);
		if(fx==fy) continue;
		fa[fx]=fy,e1[++p]=ee[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j],ee[++tot]=edge{i,j,a[i][j]};
		sort(a[i]+1,a[i]+n+1);
	}
	sort(ee+1,ee+tot+1,cmp);
	for(int s=0;s<(1<<k);s++)
	{
		int l=0,sum=0,num=n;
		for(int i=1;i<=k;i++)
			if((s>>(i-1))&1) sum+=c[i],idx[i]=++num;
		for(int i=1;i<=num;i++) fa[i]=i;
		for(int i=1;i<=tot;i++)
		{
			int x=ee[i].u;
			if((s>>(x-1))&1) e2[++l]={idx[x],ee[i].v,ee[i].w};
		}
		int i=1,j=1;
		while(i<=p||j<=l)
		{
			if(i==p+1)
			{
				int fx=get(e2[j].u),fy=get(e2[j].v),w=e2[j].w;
				j++;
				if(fx==fy) continue;
				fa[fx]=fy,sum+=w;
				continue;
			}
			if(j==l+1)
			{
				int fx=get(e1[i].u),fy=get(e1[i].v),w=e1[i].w;
				i++;
				if(fx==fy) continue;
				fa[fx]=fy,sum+=w;
				continue;
			}
			if(e1[i].w<e2[j].w)
			{
				int fx=get(e1[i].u),fy=get(e1[i].v),w=e1[i].w;
				i++;
				if(fx==fy) continue;
				fa[fx]=fy,sum+=w;
			}
			else 
			{
				int fx=get(e2[j].u),fy=get(e2[j].v),w=e2[j].w;
				j++;
				if(fx==fy) continue;
				fa[fx]=fy,sum+=w;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
}
