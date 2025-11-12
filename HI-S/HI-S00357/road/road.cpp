#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+10;
struct node{
	int u,v,l;
}edge[N];
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int fa[N];
int fid(int x)
{
	int tmp=x;
	while(x!=fa[x])
	{
		x=fa[x];
	}
	while(tmp!=fa[tmp])
	{
		int temp=tmp;
		tmp=fa[tmp];
		fa[temp]=x;
	}
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].l;
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	int ans=0;
	sort(edge,edge+m,cmp);
	for(int i=0;i<m;i++)
	{
		int fu=fid(edge[i].u);
		int fv=fid(edge[i].v);
		if(fu!=fv)
		{
			fa[fu]=fv;
			ans+=edge[i].l;
		}
	}
	cout<<ans;
	return 0;
 } 
