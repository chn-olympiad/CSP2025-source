#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,c[10005],zbs;
bool dis[10005];
struct node
{
	long long to;
	long long val;
}a[10005];
long long mn=0x3f3f3f3f;
vector <node> e[10005];
queue<node> q;
void bfs()
{
	q.push(a[1]);
	dis[1]=0;
	while(!q.empty())
	{
		long long tot=e[1].1.to;
		long long va=q.front().val;
		q.pop();
		for(auto i:e[k])
		{
			if(dis[a[i].to]!=0)
			{
				
			}
		}
	}
}
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	zbs=m+n*k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u].to=v,a[u].val=w;
		a[v].to=u,a[v].val=w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>u;
		for(int j=1;j<=n;j++)
		{
			cin>>v>>w;
			a[u].to=v,a[u].val=w;
			e[u].push_back({v,w});
		}
	}
	bfs();
	cout<<mn;
	return 0;
}
