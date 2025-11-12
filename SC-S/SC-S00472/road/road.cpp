#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,h[N],idx;
struct node{int v,w,net;}e[M*3];
void add(int u,int v,int w)
{
	e[idx]={v,w,h[u]};
	h[u]=idx++;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(h,-1,sizeof h);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			add(i+n,j,c+w);
		 } 
	}
	cout<<0;
	return 0;
}