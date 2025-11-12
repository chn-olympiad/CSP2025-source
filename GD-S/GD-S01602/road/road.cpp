#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m,k;
struct Edge
{
	int a,b;
	ll v;
}edge[3000005];
ll c[15][10005];
int fa[10005];
int find(int now)
{
	if(fa[now]==now)
	return now;
	fa[now]=find(fa[now]);
	return fa[now];
}
bool cmp(Edge x,Edge y)
{
	return x.v<y.v;
}
int head[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll ans=0;
	bool cheat=1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&edge[i].a,&edge[i].b,&edge[i].v);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i][0]);
		if(c[i][0]!=0)
		cheat=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&c[i][j]);
		}
	}
//	cout<<cheat<<endl;
//	cout<<"?\n";
	if(cheat)
	{
//		cout<<"?\n";
		ll shortcut;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				shortcut=99999999999;
				for(int qq=1;qq<=k;qq++)
				{
					shortcut=min(shortcut,c[qq][i]+c[qq][j]);
				}
				m++;
				edge[m].a=i;
				edge[m].b=j;
				edge[m].v=shortcut;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	
//	for(int i=1;i<=m;i++)
//	cout<<edge[i].v<<' ';
//	cout<<endl;
//	if(cheat||k==0)
//	{
		sort(edge+1,edge+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			if(find(edge[i].a)!=find(edge[i].b))
			{
				fa[find(edge[i].b)]=find(edge[i].a);
				ans+=edge[i].v;
			}
		}
		printf("%lld",ans);
//	} 
//	else
//	{
//		for(int i=1;i<=m;i++)
//		{
//			edge[m+i].a=edge[i].b;
//			edge[m+i].v=edge[i].v;
//			edge[m+i].b=edge[i].a;
//			head[a]=i;
//			head[b]=m+i;
//		}
//		for(int i=0;i<=(1<<k)-1;i++)
//		{
//			
//		}
//	}
	return 0;
}
