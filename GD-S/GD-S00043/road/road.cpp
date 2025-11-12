#include <bits/stdc++.h>
using namespace std;
vector<int>e[10005];
int w[10005][10005];
int c[15],a[15][10005];
long long dis[10005];
bool vis[10005];
long long sum=0;
queue<int>q;
void tps()
{
	q.push(1);
	while(!q.empty())
	{
		int pos=q.front();
		vis[pos]=1;
		for(int i=1;i<=e[pos].size();i++)
		{
			int nxt=dis[e[pos][i]]+w[pos][e[pos][i]];
			if(dis[e[pos][i]]>nxt)
			{
				if(vis[pos]==0)sum+=nxt;
				else sum-=dis[e[pos][i]]-nxt;
				q.push(e[pos][i]);
				dis[e[pos][i]]=nxt;
			}
		}
	}
	printf("%d",sum);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w1;
		scanf("%d %d",&u,&v,&w1);
		w[u][v]=w1;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	bool fa=1;
	for(int j=1;j<=k;j++)
	{
		scanf("%d",c[j]);
		if(c[j]!=0)fa=0;
		bool ffa=0;
		for(int l=1;l<=n;l++)
		{
			scanf("%d",a[j][l]);
			if(a[j][1]==0)ffa=1;
		}
		fa=ffa;
	}
	if(k==0)
	{
		tps();
	}
	return 0;
}
