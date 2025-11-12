#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+100;
ll n,m,k,c[100],v[100],sum,ans=-1,s,vis[N];
struct node{
	ll v,w;
};
vector<node> a[N];
void mit(int p)
{
	priority_queue<ll> q;
	ll ans2=0;
	int s=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=k;i++) vis[n+i]=v[i],s+=v[i];
	q.push(-1);
	for(int i=1;i<=n+k-s;i++)
	{
		while(vis[0-(q.top()%100000)]) q.pop();
		int now=0-(q.top()%100000);
		ans2+=0-(q.top()/100000);
		vis[now]=1;
		q.pop();
		for(auto j:a[now])
			if(!vis[j.v]) q.push(0-(j.w*100000+j.v));
	}
	if(ans==-1) ans=ans2+p;
	else ans=min(ans,ans2+p);
}
void dfs(int z,int w)
{
	if(z>k)
	{
		mit(w);
		return;
	}
	dfs(z+1,w);
	v[z]=1;
	dfs(z+1,w-c[z]);
	v[z]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		sum+=c[i];
		for(int j=1,w;j<=n;j++)
		{
			cin>>w;
			a[n+i].push_back({j,w});
			a[j].push_back({n+i,w});
		}
	}
	dfs(1,sum);
	cout<<ans;
	return 0;
}

