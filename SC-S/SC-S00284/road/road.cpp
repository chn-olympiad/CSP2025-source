#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
const ll MAXX=1e18+10;
ll n,m,k,nn; 
struct node{
	ll fa,edge,son;
	bool operator<(const node &b) const
	{
		return edge<b.edge;	
	} 
};
ll fa[N];
ll c[N];
ll get(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
ll minn=MAXX;
node e[N];
ll tot=0;
ll lans=0;
void solve()
{
	vector<node> ne;
	ll ans=0;
	bool vis[N];
	memset(vis,0,sizeof vis);
	for(int i=1;i<=nn;i++) fa[i]=i;
	sort(e+1,e+tot+1);
	for(int i=1;i<=tot;i++)
	{
		ll x=e[i].fa,y=e[i].son,z=e[i].edge;
		ll fx=get(x),fy=get(y);
		if(fx!=fy)
		{
			if(x>n)
			{
				vis[x-n]=true;
			}
			if(y>n)
			{
				vis[y-n]=true;
			}
			fa[fy]=fx;
			ne.push_back({x,z,y});
			ans+=z;
		}
	}
	for(int i=1;i<=(nn-n);i++)
	{
		if(vis[i]) ans+=c[i+n];
	}
	if(minn>ans)
	{
		minn=ans;
		tot=0;
		for(int i=0;i<ne.size();i++)
		{
			e[++tot]=ne[i];
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		e[++tot]={x,z,y};
	}
	nn=n;
	solve();
	for(int i=1;i<=k;i++)
	{
		nn++;
		cin>>c[nn];
		for(int j=1;j<=n;j++)
		{
			ll z;
			cin>>z;
			e[++tot]={nn,z,j};
		}
		solve();
	}
	cout<<minn;
	return 0;
}