#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
	int v,w;
};
struct Edge
{
	int u,v,w;	
} e[3500010];

vector<edge> g[10100];
int n,m,k;
int c[55],a[55][10010];

int fa[10100];

int find(int x)
{
	if(x == fa[x]) return fa[x];
	return fa[x] = find(fa[x]);
}
int merge(int x,int y)
{
	fa[find(x)] = find(y);
}
bool cmp(Edge x,Edge y)
{
	if(x.w != y.w) return x.w < y.w;
	return x.u < y.u;
}
int kruskal(int tot)
{
	int cnt = 0,sum = 0;
	int flagn_1 = 0; 
	bool rec[15];
	memset(rec,0,sizeof(rec));
	for(int i = 1;i <= tot;i++)
	{
		int u = e[i].u,v = e[i].v;
		if(find(u) != find(v))
		{
			if(u > n && !rec[u-n]) flagn_1++,rec[u-n] = 1;
			if(v > n && !rec[v-n]) flagn_1++,rec[v-n] = 1;
			sum += e[i].w;
			cnt++;
			merge(u,v);
		}
		if(cnt == n-1+flagn_1) break;
	}
	if(cnt < n-1+flagn_1) return -1;
	else return sum;
}
int vis[15],dubo = 1e9;
void dfs(int dep)
{
	if(dep == k+1)
	{
		int tota = m;
		for(int i = 1;i <= n+k;i++)
			fa[i] = i;
		int ult = 0;
		for(int i = 1;i <= k;i++)
		{
			if(!vis[i]) continue;
			ult += c[i];
			for(int j = 1;j <= n;j++)
			{
				e[++tota].u = n+i;
				e[tota].v = j;
				e[tota].w = a[i][j];
			}
		}
		sort(e+1,e+tota+1,cmp);
		for(int i = 1;i <= k;i++)
			cout << vis[i] << " ";
		cout << endl;
		cout << kruskal(tota)+ult << endl;
		int now = kruskal(tota);
		if(now != -1)
			dubo = min(dubo,now+ult);
		return;
	}
	vis[dep] = 1;
	dfs(dep+1);
	vis[dep] = 0;
	dfs(dep+1);
}
//plz Core Ultra 9 285K
//plz 96GB DDR5
//plz dont let me AFO
//i want to run on the field of OI one more time
//give me a chance plz!!!!!!
//i promise learn algorithm seriously in every day after now!!!!
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int u,v,w; 
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	bool flagA = 1;
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		if(c[i] != 0) flagA = 0;
		bool now = 0;
		for(int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 0) now = 1;
		}
		if(!now) flagA = 0;
	}
	sort(e+1,e+m+1,cmp);
	for(int i = 1;i <= n;i++)
		fa[i] = i;
	int old = kruskal(m);
//	cout << old << endl;
	if(k == 0)
	{
		cout << old;
		return 0;
	}
	if(flagA)
	{
		int tota = m;
		for(int i = 1;i <= n+k;i++)
			fa[i] = i;
		for(int i = 1;i <= k;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				e[++tota].u = n+i;
				e[tota].v = j;
				e[tota].w = a[i][j];
			}
		}
		sort(e+1,e+tota+1,cmp);
		int mia = min(old,kruskal(tota));
		cout << mia;
	}
//	dfs(1);
//	cout << dubo;
	return 0;
}

