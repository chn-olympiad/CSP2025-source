#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005],c[15],a[15][10005],vis[15],cnt,ans;
struct str{
	int u,v,w;
}q[2000005];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
bool cmp(str x,str y){return x.w<y.w;}
void kru()
{
	for(int i=1;i<=m;i++)
	{
		int eu=find(q[i].u);
		int ev=find(q[i].v);
		if(eu!=ev)
		{
			fa[ev]=eu;
			cnt++;
			ans+=q[i].w;
			if(q[i].u>n&&vis[q[i].u]==0) vis[q[i].u]=1;
			else if(q[i].u>n&&vis[q[i].u]==1) 
			if(cnt==n-1) break;
		}
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			q[++m].u=i+n;
			q[m].v=j;
			q[m].w=a[i][j]+c[i];
		}
	}
	sort(q+1,q+1+m,cmp);
	kru();
	printf("%d",ans);
	return 0;
}

