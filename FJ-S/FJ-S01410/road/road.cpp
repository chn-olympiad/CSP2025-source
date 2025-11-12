#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int u,v,w;
	bool operator<(const edge x)const
	{
		return w<x.w;
	}
	void read()
	{
		cin>>u>>v>>w;
	}
}e[1000001];
priority_queue<edge,vector<edge>,greater<edge> >pq;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a[11][10001],c[11];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		e[i].read();
		pq.push(e[i]);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(k==0)
	{
		cout<<0;
		return 0;
	}
	return 0;
 } 
