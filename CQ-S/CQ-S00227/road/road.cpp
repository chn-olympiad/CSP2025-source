/*
	最小生成树 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int fa[10009],c[19],w[10009];

struct edge
{
	int u,v,dis;
}e[52000009];

int found(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=found(fa[x]);
}

void Merge(int x,int y)
{
	int zx=found(x),zy=found(y);
	if(zy>zx)swap(zx,zy);
	fa[zx]=zy;
}

bool Judge(int a,int b)
{
	return found(a)==found(b);
}

bool cmp(edge a,edge b)
{
	return a.dis<b.dis;
}


signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)fa[i]=i;
	
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i]={u,v,w};
	}
	
	int cnt=m;
	
	for(int i=1;i<=k;i++)
	{
//		scanf("%d",c+i);
//		for(int j=1;j<=n;j++)
//		{
//			scanf("%d",w+j);
//			e[++cnt]={n+i,j,w[j]};
//		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				e[++cnt]={i,j,w[i]+w[j]};
			}
		}
	}
	
	if(k==0)
	{
		int ans=0;
		
		sort(e+1,e+m+1,cmp);
		
		for(int i=1;i<=m;i++)
		{
			int u=e[i].u,v=e[i].v,dist=e[i].dis;
			if(!Judge(u,v))
			{
				Merge(u,v);
				ans+=dist;
			}
		}
		
		cout<<ans;
	}
	else
	{
		int ans=0;
		
		sort(e+1,e+cnt+1,cmp);
		
		for(int i=1;i<=cnt;i++)
		{
			int u=e[i].u,v=e[i].v,dist=e[i].dis;
			if(!Judge(u,v))
			{
				Merge(u,v);
				ans+=dist;
			}
		}
		
		printf("%d",ans);		
	}
	
	return 0;
} 
