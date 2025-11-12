#include <bits/stdc++.h>
using namespace std;
int n,m;int pre[2*1000086];int k0;long long k;long long kw[12],ka[12][1000086];bool bk[12];long long ans1=1e9;
bool ba[1000086];int da[1000086];int da1[1000086];
long long ans;
struct node
{
	int from,to;
	long long w;
	int last;
}edge[2*1010086];
void add(int u,int v,int w0){
	edge[++k0].from=u;
	edge[k0].to=v;
	edge[k0].w=w0;
	edge[k0].last=pre[u];
	pre[u]=k0;
}
int dfs(int x){
	ba[x]=true;
	for(int i=pre[x];i!=0;i=edge[i].last)
	{
		int t=edge[i].to;
		int u=edge[i].from;
		if(edge[i].w+da[u]<da[t]&&ba[t]==false)
		{
			da[t]=edge[i].w+da[u];
			ans+=edge[i].w;
			dfs(t);
		}
	}
	ba[x]=false;
}
int dfs2(int x)
{
	ba[x]=true;
	for(int i=pre[x];i!=0;i=edge[i].last)
	{
		int t=edge[i].to;
		int u=edge[i].from;
		if(edge[i].w+da[u]+kw[k]<da[t]&&ba[t]==false)
		{
			da[t]=edge[i].w+da[u]+kw[k];
			ans+=edge[i].w;
			dfs(t);
		}
	}
	ba[x]=false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%lld",&n,&m,&k);
	memset(da,0x3f3f3f,sizeof(da));
	int a1,a2;long long w0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&a1,&a2,&w0);
		add(a1,a2,w0);
		add(a1,a2,w0);
	} 
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&kw[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&ka[i][j]);
		}
	}
	da[1]=0;
	dfs(1);
	/*for(int i=1;i<=n;i++)
	{
		cout<<da[i]<<" ";
	}*/
	cout<<ans;

/*	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			add(j,n+k,ka[i][j]);
			add(n+k,j,ka[i][j]);
		}
	}*/
/*	for(int i=1;i<=n;i++)
	{
		da1[i]=da[i];
	}
	for(int i=1;i<=k;k++)
	{
		
		ans+=kw[i];
		dfs2(1);
		ans1=min(ans1,ans);
		ans-=kw[i];
		for(int i=1;i<=n;i++)
		{
			da[i]=da1[i];
		}
	}
	cout<<ans1;*/
	return 0;
} 
