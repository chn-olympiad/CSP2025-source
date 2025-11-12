#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+7;
ll n,m,k;
struct node
{
	ll v,w;
};
vector<node> t[N];
ll ans=0;
bool vis[N]={};
void dfs(ll u)
{
	ll len=t[u].size();
	vis[u]=1;
	ll num=LONG_LONG_MAX,id=0;
	for(ll i=0;i<len;i++)
	{
		ll v=t[u][i].v,w=t[u][i].w;
		if(!vis[v])
		{
			num=min(num,w);
			id=v;
		}
	}
	if(id)
	{
		ans+=num;
		dfs(id);
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		t[u].push_back((node){v,w});
		t[v].push_back((node){u,w});
	}
	for(ll i=1;i<=k;i++)
	{
		ll sum;
		cin>>sum;
		for(ll j=1;j<=n;j++)
		{
			ll num;
			cin>>num;
			t[i].push_back((node){j,sum+num});
			t[j].push_back((node){i,sum+num});
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
