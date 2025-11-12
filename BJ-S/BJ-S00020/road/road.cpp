#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+100;
const ll M=1e6+5;
const ll K=10+5;
ll n,m,k,cnt=0,fa[N],ans=0;
struct g
{
	ll u,v,w;
}e[M];
ll find(ll x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void merge(ll x,ll y)
{
	x=find(x),y=find(y);
	if(x==y)return ;
	fa[y]=x;
}
void Kruskal()
{
	ll sum=0;
	for(int i=1;i<=m;i++)
	{
		ll u=e[i].u;
		ll v=e[i].v;
		ll w=e[i].w;
		if(find(u)!=find(v))
		{
			merge(u,v);
			ans+=w;
			sum++;
			if(sum==n-1)return ;
		}
	}
	cout<<ans;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
	}
	Kruskal();
	return 0;
}
