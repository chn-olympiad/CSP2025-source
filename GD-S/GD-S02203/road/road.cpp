#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+7;
ll n,m,k;
struct Node
{
	ll x,y,w;
}a[N],st[N],eg[N];
ll top,tp;
ll ct[11];
ll link[11][N];
inline bool cmp(Node A,Node B)
{
	return A.w<B.w;
}
ll fa[N];
inline ll Find(ll x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
struct EDGE
{
	ll to,val;
};
bool vis[11];
ll Max;
ll ans;
inline void dfs(ll X)
{
	if(X==k+1)
	{
		for(ll i=1;i<=n+k;i++) fa[i]=i;
		tp=0;
		ll res=0;
		for(ll i=1;i<=top;i++) eg[++tp]=st[i];
		ll all=n-1;
		for(ll i=1;i<=k;i++)
		{
			if(vis[i])
			{
				all++;
				res+=ct[i];
				for(ll j=1;j<=n;j++)
				{
					if(link[i][j]<Max)
						eg[++tp]={i+n,j,link[i][j]};
				}
			}
		}
		if(res>=ans) return;
		stable_sort(eg+1,eg+1+tp,cmp);
		for(ll i=1;i<=tp;i++)
		{
			ll x=eg[i].x;
			ll y=eg[i].y;
			ll xx=Find(x);
			ll yy=Find(y);
			if(xx!=yy)
			{
				fa[xx]=yy;
				res+=eg[i].w;
				if(res>=ans) return;
				all--;
				if(!all) break;
			}
		}
		ans=min(ans,res);
		return;
	}
	vis[X]=1;
	dfs(X+1);
	vis[X]=0;
	dfs(X+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++) fa[i]=i;
	for(ll i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	for(ll i=1;i<=k;i++)
	{
		cin>>ct[i];
		for(ll j=1;j<=n;j++)
		{
			cin>>link[i][j];
		}
	}
	sort(a+1,a+1+m,cmp);
	for(ll i=1;i<=m;i++)
	{
		ll x=a[i].x;
		ll y=a[i].y;
		ll xx=Find(x);
		ll yy=Find(y);
		if(xx!=yy)
		{
			fa[xx]=yy;
			st[++top]={x,y,a[i].w};
			Max=a[i].w;
			ans+=a[i].w;
		}
	}
	dfs(1);
	cout<<ans;
}
