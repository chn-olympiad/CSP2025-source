#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5,M = 1e6+5,K = 15;
struct edge {int u,v,w;} edges[M],gedges[N];
int n,m,k,val[N],idx = 0,dsu[N],dis[K][N],village[K][N];
long long ans = 0;
bool box[K];

bool cmp(edge x,edge y) {return x.w < y.w;}

int find(int x)
{
	if(dsu[x] == x) return x;
	return dsu[x] = find(dsu[x]);
}

void unionn(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x != y) dsu[x] = y;
	return;
}

long long novillage_kruskal()
{
	stable_sort(edges+1,edges+m+1,cmp);
	int pt = 0;
	long long the_ans = 0;
	for(int i = 1;i <= n;i++) dsu[i] = i;
	for(int i = 1;i <= m && pt < n-1;i++)
	{
		int u = edges[i].u,v = edges[i].v,w = edges[i].w;
		if(find(u) != find(v))
		{
			the_ans += w;
			unionn(u,v);
			pt++;
			gedges[pt] = edges[i];
		}
	}
	m = n-1;
	return the_ans;
}

long long get_ans(void)
{
	for(int i = 1;i <= n+k;i++) dsu[i] = i;
	m = n-1;
	for(int i = 1;i <= m;i++) edges[i] = gedges[i];
	int cntv = 0;
	for(int i = 1;i <= k;i++)
	{
		if(box[i] == 0) continue;
		cntv++;
		for(int v = 1;v <= n;v++) edges[++m] = {i+n,v,village[i][v]};
	}
	stable_sort(edges+1,edges+m+1,cmp);
	int pt = 0;
	long long the_ans = 0;
	for(int i = 1;i <= m && pt < n+cntv-1;i++)
	{
		int u = edges[i].u,v = edges[i].v,w = edges[i].w;
		if(find(u) != find(v))
		{
			the_ans += w;
			unionn(u,v);
			pt++;
		}
	}
	return the_ans;
}

void dfs(int steps,long long sum)
{
	if(steps > k)
	{
		ans = min(ans,get_ans()+sum);
		return;
	}
	box[steps] = 1;
	dfs(steps+1,sum+val[steps]);
	box[steps] = 0;
	dfs(steps+1,sum);
	return;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
	for(int u = 1;u <= k;u++)
	{
		cin >> val[u];
		for(int v = 1;v <= n;v++) cin >> village[u][v];
	}
	ans = novillage_kruskal();
	dfs(1,0);
	cout << ans;
	return 0;
}
