#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
int n,m,k,cnt,ans;
struct node
{
	int v,w;
}g[N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(g[u]!=0)
		{
			if(g[u].w>w)
			{
				g[u].v=v;
				g[u].w=w;
				continue;
			}
			else
			{
				continue;
			}
		}
		g[u].v=v;
		g[u].w=w;
	}
	for(int i=1;i<=m;i++)
	{
		ans+=g[i].w;
	}
	cout<<ans;
	return 0;
}
