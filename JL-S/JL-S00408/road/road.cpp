#include <bits/stdc++.h>
using namespace std;
struct node
{
	int to,nxt,w,w2;
	bool f;
	bool repair;
}e[1000010];
int head[1000010];
int tot;
int n,m,k;
int c[10100];
long long ans = 0x3f3f3f;
int cnt;
void add(int u,int v,int w,int f)
{
	e[tot].to = v;
	if(!f)
		e[tot].w = w;
	else e[tot].w2 = w;
	e[tot].nxt = head[u];
	e[tot].f = f;
	e[tot].repair = 0;
	head[u] = tot++;
	c[v]++;
}
void dfs(int u,long long charge)
{
	int res;
	if(cnt == n) 
	{
		ans = min(ans,charge);
		return ;
	}
	for(int i = head[u];i != -1;i = e[i].nxt)
	{
		int v = e[i].to;
		if(c[v] != 0)
		{
			c[v]--;
			cnt++;
			if(!e[i].repair)
			{
				charge += e[i].w;
				e[i].repair = 1;
				if(e[i-1].to == u)
					res = i-1;
				if(e[i+1].to == u) 
					res = i+1;
				e[res].repair = 1;
			}	
			dfs(v,charge);
			e[i].repair = 0;
			e[res].repair = 0;
			cnt--;
			c[v]++;
		}
	}
	return ;
}
int main()
{
	// freopen("road.in","r",stdin);
	// freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w,0);
		add(v,u,w,0);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			int v,w;
			scanf("%d%d",&v,&w);
			//add(i,v,w,1);
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<c[i]<<endl;
	for(int i=1;i<=n;i++)
	{
		c[i] --;
		dfs(i,0);	
		++ c[i];
	}
	printf("%lld",ans);
	return 0;
}
