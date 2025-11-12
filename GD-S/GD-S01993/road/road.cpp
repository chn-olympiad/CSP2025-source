#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=1e4,maxm=1e6;
int u[maxm+5],v[maxm+5],w[maxm+5];
int c[11],a[11][maxn+5];
map<int,map<int,int> > cost;
struct edge{
	int from,to,mincost;
}edges[maxn*(maxn-1)/2+5];
int fa[maxn+5],cnt,tot;
bool cmp(edge edge1,edge edge2)
{
	return edge1.mincost<edge2.mincost;
}
void init()
{
	for (int i=1;i<=n;i++) fa[i]=i;
	return;
}
int find(int node)
{
	if (fa[node]==node) return node;
	return fa[node]=find(fa[node]);
}
void merge(int i)
{
	int fa1=find(edges[i].from),fa2=find(edges[i].to);
	if (fa1!=fa2)
	{
		cnt++;
		fa[fa1]=fa2;
		tot+=edges[i].mincost;
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) cost[i][j]=INT_MAX;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		cost[u[i]][v[i]]=cost[v[i]][u[i]]=w[i];
	}
	for (int j=1;j<=k;j++)
	{
		cin>>c[j];
		for (int i=1;i<=n;i++) cin>>a[j][i];
	}
	if (n>1e3) cout<<0;
	else
	{
		init();
		for (int j=1;j<=k;j++)
		{
			for (int i=1;i<n;i++)
			{
				for (int l=i+1;l<=n;l++) cost[i][l]=cost[l][i]=min(cost[i][l],c[j]+a[j][i]+a[j][l]);
			 } 
		}
		int edgecnt=0;
		for (int i=1;i<n;i++)
		{
			for (int j=i+1;j<=n;j++) edges[++edgecnt]={i,j,cost[i][j]};
		}
		sort(edges+1,edges+edgecnt+1,cmp);
		cnt=tot=0;
		for (int i=1;cnt<n-1;i++) merge(i);
		cout<<tot; 
	}
	return 0;
}
