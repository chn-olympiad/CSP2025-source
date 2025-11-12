#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
bool o[10001][10001];
struct node{
	long long u,v,w;
}a[1000200];
struct node1{
	int v,w;
};
struct node2{
	int need;
	int e[10020];
}kneed[11];
vector<node1> m1[10010];
bool vis[10200];
queue<int> q;
queue<int> q1;
bool cmp(node b,node c){return b.w>c.w;}
void bfs()
{
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		int w=q1.front();
		q1.pop();
		ans+=w;
		for(int i=0;i<=m1[v].size()-1;i++)
		{
			if(vis[m1[v][i].v]==0)
			{
				node1 r=m1[v][i];
				vis[r.v]=1;
				q.push(r.v);
				q1.push(r.w);
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[i].u=u;a[i].v=v;a[i].w=w;
		o[u][v]=o[v][u]=1;
		node1 r;
		r.v=v;
		r.w=w;
		m1[u].push_back(r);
		r.v=u;
		m1[v].push_back(r);
	}
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		
		scanf("%d",&kneed[i].need);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&kneed[i].e[j]);
			sum+=kneed[i].e[j];
		}
		sum+=kneed[i].need;	
	}
	if(k==0)
	{
		q.push(a[1].u);
		q1.push(a[1].w);
		vis[a[1].u]=1;
		bfs();
	}
	if(k!=0&&sum==0)
	{
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=k;i++)o[a[i].u][a[i].v]=o[a[i].v][a[i].u]=a[i].w=0;
		q.push(a[1].u);
		q1.push(a[1].w);
		vis[a[1].u]=1;
		bfs();
	}
	cout<<ans;
	return 0;
}
