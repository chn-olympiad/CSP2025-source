#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,f[10010];
int find(int u)
{
	if(u == f[u]) return u;
	return f[u] = find(f[u]);
}
void merge(int u, int v)
{
	f[find(u)] = find(v);
}
struct node
{
	int u,v,w;
	bool operator<(const node&x)const{
		return w < x.w;
	}
};
node r[2000010];
int s;
int adj[10010][10010];
int c[10010];
int ans,cnt;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin >> n >> m >> k;
	memset(adj,0x3f3f3f3f,sizeof(adj));
	for(int i=1; i<=m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		r[++s] = {u,v,w};
	}
	for(int i=1; i<=k; i++)
	{
		int id = 0;
		for(int j=0; j<=n; j++)
		{
			cin >> c[j];
			if(c[j] == 0) id = j;
		}
		for(int j=1; j<=n; j++)
		{
			if(j == id) continue;
			r[++s] = {id,j,c[j]};
		}
	}
	for(int i=1; i<=n; i++) f[i] = i;
	sort(r+1,r+s+1);
	for(int i=1; i<=s; i++)
	{
		node cur = r[i];
		int u = cur.u, v = cur.v, w = cur.w;
		u = find(u);
		v = find(v);
		if(u == v) continue;
		cnt++;
		ans += w;
		merge(u,v);
		if(cnt == n-1) break;
	}
	cout << ans;
	return 0;
}
