#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w; 
};
vector<edge> g[100010];
int c[100010];
struct node{
	int u,v,w;
	bool operator<(const node &a)const
	{
		return a.w<w;
	}
};
priority_queue<node> q;
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		g[i].push_back({x,y,w});
		g[i].push_back({y,x,w});
	}
	for(int i=m+1;i<=m+k+1;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			g[i].push_back({i,j,x});
		}
	}
	for(int i=0;i<=vector.size();i++)
	return 0;
}
