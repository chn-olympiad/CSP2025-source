# include <bits/stdc++.h>
# define int long long
using namespace std;

const int N = 1e4+5;
struct node
{
	int now,d;
	bool operator <(const node &h)const
	{
		return h.d < d;
	}
};
int n,m,k,b,ans,f[N+20],mp[N+20][N+20],ma[N][N];
bool vis[N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	memset(ma,-1,sizeof(ma));
	for (int i = 1,u,v,w; i <= m; i++) 
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		ma[u][v] = w;
		ma[v][u] = w;
	}
	for (int i = n+1,w; i <= n+k; i++) 
	{
		scanf("%lld",&w);
		f[i] = w;
		for (int j = 1,s; j <= n; j++) scanf("%lld",&s),mp[i][j] = mp[j][i] = s;
	}
	priority_queue<node> q;
	q.push({1,0});
	while (1)
	{
		int u = q.top().now;
		int d = q.top().d;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		b++;
		ans += d;
		if (b == n)
		{
			printf("%lld",ans);
			break;
		}
		for (int i = 1; i <= n; i++)
		{
			if (i == u) continue;
			int p = mp[u][n+1] + mp[n+1][i] + f[n+1];
			for (int j = n+2; j <= n+k; j++) p = min(p,mp[u][j] + mp[j][i] + f[j]);
			if (ma[u][i] >= 0) p = min(p,ma[u][i]);
			q.push({i,p});	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
