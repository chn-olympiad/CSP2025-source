#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5, M=1e6+5, K=3e6+5;
const ll INF=1e18;

struct node
{
	int u1, v1;
	ll w1;
}b[12][N], c[K];
int n, m, k, u1, v1, tot=0, f[N], sub=0;
ll w1, p[N], ans=0, vis[M], cd[M];
bool cmp(node a, node b)
{
	return a.w1<b.w1;
}
int find(int x)
{
	if (f[x]==x) return x;
	return f[x]=find(f[x]);
}
ll kru(int cnt)
{
	ll ret=0;
	int num=0;
	
	for (int i=1; i<=n+cnt; i++) f[i]=i;
	sort(c+1, c+1+tot, cmp);
//	for (int i=1; i<=tot; i++) printf("%d %d %lld\n", c[i].u1, c[i].v1, c[i].w1);
	
	for (int i=1; i<=tot; i++)
	{
		int u=c[i].u1, v=c[i].v1;
		int fu=find(u), fv=find(v);
		ll w1=c[i].w1;
		
		if (fu!=fv) 
		{
			f[fu]=fv, ret+=w1, num++;
			if (u>n) cd[u]++, vis[u]=w1;
		}
		if (num==n+cnt-1) break;
	}
	
	return ret;
}
void calc(int i)
{
	tot=m;
	ll res=0;
	int cnt=0;
		
	for (int j=0; j<k; j++)
		if ((i>>j)&1) 
		{
			res+=p[j+1], cnt++;
			for (int u=1; u<=n; u++) c[++tot]=b[j+1][u];
		}
		
	ans=min(ans, res+kru(cnt));
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%lld", &u1, &v1, &w1);
		c[++tot]={u1, v1, w1};
	}
	if (k==0)
	{
		printf("%lld", kru(0));
		return 0;
	}
	
	for (int i=1; i<=k; i++)
	{
		scanf("%lld", &p[i]);
		if (!p[i]) sub++;
		for (int j=1; j<=n; j++)
		{
			scanf("%lld", &w1);
			b[i][j]={n+i, j, w1};
		}
	}
	
	if (sub==k)
	{
		ans=INF;
		calc((1<<k)-1);
		printf("%lld", ans);
		return 0;
	}
	
	ans=INF;
	for (int i=0; i<(1<<k); i++) calc(i);
	printf("%lld", ans);

	
	return 0;
}
/*
4 4 2 
1 4 6 
2 3 7 
4 2 5 
4 3 4 
1 1 8 2 4 
100 1 3 2 4 


*/
