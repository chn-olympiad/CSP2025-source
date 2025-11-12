#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
struct f{
	int u,v,w;
	friend bool operator < (const f &x,const f &y)
	{
		return x.w<y.w;
	}
};
int fa[MAXN];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int a=find(x),b=find(y);
	if(a==b) return;
	fa[a]=b;
}
vector<f> g;
int c[MAXN];
int dp[MAXN][2];
int n,m,k;
int a[10][MAXN];
void kruskal()
{
	sort(g.begin(),g.end());
	int ans=0;
	int ch=0;
	for(auto P:g)
	{
		int u=P.u,v=P.v,w=P.w;
		if(find(u)==find(v)) continue;
		merge(u,v);
		ans+=w;
		ch++;
		if(ch==n-1) break;
	}
	cout<<ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int x=1;x<=n;x++)
			{
				int val=a[i][j]+a[i][x]+c[i];
				g.push_back({j,x,val});
			}
		}
	}
	kruskal();
	return 0;
}

