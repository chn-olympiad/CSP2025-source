/*
	RP++!
	freopen!!!(last year CSP-J -100pts)
*/
#define ll long long
#include<bits/stdc++.h>
using namespace std;
ll n,m,k,ans,fa[10100];
struct edge{
	ll v,w;
};
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
vector<edge> g[10100];
ll find(ll x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	ll fx=find(x),fy=find(y);
	fa[fy]=fx;
	fx=find(x),fy=find(y);
}
void MST()
{
	for(ll i=1;i<=n;i++)
	{
		for(auto ed:g[i])
		{
			if(find(i)!=find(ed.v))
			{
				merge(i,ed.v);
				ans+=ed.w;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		g[u].push_back((edge){v,w});
		g[v].push_back((edge){u,w});
	}
	MST();
	cout<<ans;
}//MST! 
