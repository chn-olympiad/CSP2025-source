#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=0;
long long ans;
int fa[10020];
int cost[20][10020];
bool vis[20];
struct graph{
	int x,y,z,type;
}edge[1000020];
bool cmp(graph a,graph b)
{
	return a.z<b.z;
}
int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>edge[++cnt].x>>edge[cnt].y>>edge[cnt].z,edge[cnt].type=0;
	for(int i=1;i<=k;i++)
	{
		cin>>cost[i][0];
		for(int j=1;j<=n;j++)
			cin>>cost[i][j];
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
				for(int K=1;K<=k;K++)
					edge[++cnt].x=i,edge[cnt].y=j,edge[cnt].z=cost[K][i]+cost[K][j]+cost[K][0],edge[cnt].type=K;
	sort(edge+1,edge+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int x=find(edge[i].x),y=find(edge[i].y);
		if(x==y)
			continue;
		ans+=edge[i].z;
		fa[y]=x;
		if(!vis[edge[i].type])
			vis[edge[i].type]=1;
		else
			ans-=cost[edge[i].type][0];
	}
	cout<<ans;
}
