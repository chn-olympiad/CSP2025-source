#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,K=15;
typedef long long ll;
ll c[K],a[K][N];
int f[N],zhi[N];
vector<pair<ll,pair<int,int> > >e;
int F(int x)
{
	if(f[x]==x)
		return x;
	f[x]=F(f[x]);
	return f[x];
}
void G(int x,int y)
{
	x=F(x);
	y=F(y);
	if(zhi[x]<zhi[y])
		f[x]=y;
	else
	{
		f[y]=x;
		zhi[x]+=(zhi[x]==zhi[y]);
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,x,y,w;
	ll ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		e.push_back({w,{x,y}});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		int flag=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
				flag=j;
		}
		for(int j=1;j<=n;j++)
		{
			if(j==flag)
				continue;
			e.push_back({a[i][j],{flag,j}});
		}
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(e.begin(),e.end());
	for(int i=0;i<e.size();i++)
	{
		if(F(e[i].second.first)!=F(e[i].second.second))
		{
			ans+=e[i].first;
			G(e[i].second.first,e[i].second.second);
		}
	}
	cout<<ans<<'\n';
	return 0;
}