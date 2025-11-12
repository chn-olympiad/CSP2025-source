#include<bits/stdc++.h>
using namespace std;
struct node{
	int to;
	int w;
	int next;
}e[1000005];
int cnt=0;
int head[1000005];
int u,v,w;
void add(int u,int v,int w){
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=u;
	cnt++;
}
queue <int> q;
int dis[1000005]; 
int ans=0;
void SPFA(int x)
{
	q.push(u);
	int h=q.front();
	q.pop();
	while (!q.empty())
	{
		if (dis[x]==1)
		{
			continue;
		}
		dis[x]=1;
		for (int i=head[x]; i!=0; i-=h)
		{
			ans+=e[i].w;
			x++;
			q.push(x);
			q.pop();
		}
		q.pop();
	}
	cout<<ans;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
	}
	SPFA(1);
	return 0;
} 
