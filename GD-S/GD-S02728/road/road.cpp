#include<bits/stdc++.h>
using namespace std;
struct node{int v,w;};
int n,m,k,vis[10095],d[10095],maxx,x[10005];
vector<node> g[10095];
int c[11],a[11][10091];
bool flag[15];
struct point
{
	int v,w;
	bool operator<(point a)const{return w>a.w;}
};
priority_queue<point> q;
set<int> st;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w; 
		g[u].push_back((node){v,w});
		g[v].push_back((node){u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) 
		{
			cin>>a[i][j];
			g[j].push_back((node){i+n,a[i][j]});
			g[i+n].push_back((node){j,a[i][j]});
		}
	}
	memset(d,0x7f,sizeof d);
	d[1]=0;
	q.push((point){1,0});
	while(!q.empty())
	{
		int u=q.top().v;
		q.pop();
		if(vis[u]) continue;
		if(u<=n) vis[u]=true;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].v,w=g[u][i].w;
			if(d[v]>d[u]+w)
			{
				if(u>n) vis[u]=true;
				if(v>n&&!flag[v-n]) d[v]=c[v]+d[u]+w,flag[v-n]=true;
				else d[v]=d[u]+w;
				x[v]=u;
				q.push((point){v,d[v]});
			}
		}
	}
	for(int i=1;i<=n;i++) maxx+=d[i];
	for(int i:st) if(i>n) maxx+=d[i];
	cout<<maxx;
	return 0;
}//Ren5Jie4Di4Ling5%
//
