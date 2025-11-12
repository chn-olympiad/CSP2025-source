#include <bits/stdc++.h>
const int maxn = 2e5+10;
typedef std::pair<int, int> pii;
using namespace std;

int fa[maxn];
int bel(int x)
{
	if(x==fa[x]) return x;
	else return fa[x]=bel(fa[x]);
}
void cmb(int x, int y)
{
	fa[bel(x)] = bel(y);
}
bool ist(int x, int y)
{
	return bel(x) == bel(y);
} 
struct edge
{
	int u,v,w;
} edges[maxn];
int tot = 0;
int c[maxn];
int conn[15][maxn];
bool cmp(edge a, edge b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i] = i;
	//cout<<"Start scanning cities.\n";
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edges[++tot] = {u,v,w};
	}
	//cout<<"Complete scanning cities.\n";
	for(int i=1;i<=k;i++) 
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>conn[i][j];
	}
	//cout<<"Complete scanning countrysides.\n";
	for(int t=1;t<=k;t++)
	{
		sort(edges+1, edges+tot+1, [t](edge a, edge b){
			return conn[t][a.u]+conn[t][a.v] < conn[t][b.u]+conn[t][b.v];
		});
		vector<bool> sel(n+1);
		for(int i=1;i<=tot;i++)
		{
			int cu = edges[i].u, cv = edges[i].v;
			int d1 = sel[cu]?0:conn[t][cu];
			int d2 = sel[cv]?0:conn[t][cv];
			edges[i].w = min(edges[i].w, d1+d2);
			sel[cu] = sel[cv] = true;
		}
	}
	sort(edges+1, edges+1+tot, cmp);
	int tobe = n-1;
	int i = 1;
	int mst = 0;
	while(tobe)
	{
		int cu = edges[i].u, cv = edges[i].v, cw = edges[i].w;
		if(!ist(cu,cv))
		{
			cmb(cu,cv);
			tobe--;
			mst+=cw;
		}
		i++;
	}
	cout<<mst;
	fclose(stdin);
	fclose(stdout);
}
