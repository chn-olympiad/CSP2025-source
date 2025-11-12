#include<bits/stdc++.h>
#define int long long
#define fore(x,m,n) for(int x=m;x<=n;x++)
using namespace std;

const int maxn=1e4+5,maxm=1e6+5;
int n,m,k,ans;
int a[11][maxn];
struct edge
{
	int u,v,w;
	bool operator< (edge other)
	{
		return w<other.w;
	}
};
vector<edge> E;

int fa[maxn];
int find(int x)
{
	if(fa[x]==x) return fa[x];
	else
	{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void init()
{
	fore(i,1,n) fa[i]=i;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	init();
	fore(i,1,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		E.push_back({u,v,w});
	}
	fore(i,1,k)
	{
		int t;
		cin>>t;
		fore(j,1,n)
		{
			cin>>a[i][j];
		}
	}
	sort(E.begin(),E.end());
	int cnt=0;
	for(edge t:E)
	{
		int u=t.u,v=t.v,w=t.w;
		int fu=find(u),fv=find(v);
		if(fu!=fv)
		{
			fa[fa[u]]=v;
			ans+=w;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
}
