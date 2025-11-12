#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+20;
const int maxm=1e6+10;
const int mnod=1e9+7;
int n,m,k,u,v,w,c[20],a[20][maxn],ans;
int fa[maxn];
struct edge{int u,v,w;};
vector <edge> g;
bool cmp(edge d1,edge d2){return d1.w<d2.w;}
int find(int x){return (x==fa[x]?x:fa[x]=find(fa[x]));}
void merge(int x,int y){fa[find(x)]=find(y);}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for (int i=1;i<=n+k;i++) fa[i]=i;
	for (int i=1;i<=m;i++) cin >> u >> v >> w,g.push_back({u,v,w});
	for (int i=1;i<=k;i++)
	{
		cin >> c[i];
		for (int j=1;j<=n;j++) cin >> a[i][j],g.push_back({n+i,j,a[i][j]});
	}
	sort(g.begin(),g.end(),cmp);
	for (auto d:g)
	{
		int u=d.u,v=d.v,w=d.w;
		if (find(u)==find(v)) continue;
		merge(u,v);
		ans+=w;
	}
	cout << ans;
	return 0;
}
