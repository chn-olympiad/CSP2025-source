#include<bits/stdc++.h>
using namespace std;

int n,m,k,bs=0,cnt=0;
int a[10010];
int c[10010];
bool kai[20];
int fa[10010];
struct lym{
	int u,v,w;
	int t;
}e[3000010];

int findfa(int x)
{
	if(fa[x]==x) return fa[x];
	fa[x]=findfa(fa[x]);
	return fa[x];
}

bool cmp(const lym &x,const lym &y)
{
	return x.w<y.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		e[++bs]={u,v,w,-1};
	}
	bool pfa=true;
	if(k==0) pfa=false;
	for(int t=1;t<=k;t++)
	{
		kai[t]=false;
		scanf("%d",&c[t]);
		if(c[t]!=0) pfa=false;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			if(a[j]!=0) pfa=false;
		}
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
			for(int j=i+1;j<=n;j++)
			{
				e[++bs]={i,j,a[i]+a[j],t};
			}
		}
	}
	if(pfa==true) {
		printf("0");
		return 0;
	}
	int ans=0;
	sort(e+1,e+bs+1,cmp);
	for(int i=1;i<=bs;i++)
	{
		int u=e[i].u,v=e[i].v;
		int w=e[i].w,t=e[i].t;
		if(findfa(u)==findfa(v))
			continue;
		fa[u]=v;
		if(t!=-1&&!kai[t])
		{
			kai[u]=true;
			ans+=(c[u]+w);
//			for(int j=i+1;j<=bs;j++)
//				if(e[j].t==t) e[j].w-=w;
//			sort(e+i+1,e+bs+1,cmp);rp++
		}
		else ans+=w;
		cnt++;
		if(cnt==(n-1)) break;
	}
	printf("%d",ans);
	return 0;
}
