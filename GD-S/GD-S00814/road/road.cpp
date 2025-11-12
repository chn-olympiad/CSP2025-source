#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

struct edge
{
	long long u, v, w;
};

edge e[1000010];
edge e2[1000010];
long long fa[1000010];
long long p[1000010];
pair<long long, long long> w[20][100010];
long long n, m, m2, k;
const long long inf = 1e18;

struct node2
{
	long long u, id;
	bool operator < (node2 b) const
	{
		return w[u][id].first > w[b.u][b.id].first;
	}
};

priority_queue<node2> que;

bool cmpw(edge a, edge b)
{
	return a.w < b.w;
}

long long find(long long u)
{
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(long long i = 1; i <= m; i++) scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	sort(e + 1, e + m + 1, cmpw);
	for(long long i = 1; i <= n; i++) fa[i] = i;
	for(long long i = 1; i <= m; i++)
	{
		long long fu = find(e[i].u), fv = find(e[i].v);
		if(fu != fv)
		{
			fa[fu] = fv;
			e2[++m2] = e[i]; 
		}
	}
	for(long long i = 0; i < k; i++)
	{
		scanf("%lld", &p[i]);
		for(long long j = 1; j <= n; j++) scanf("%lld", &w[i][j].first), w[i][j].second = j;
		sort(w[i] + 1, w[i] + n + 1);
	}
	
	long long ans = inf;
	for(long long i = 0; i < (1 << k); i++)
	{
		long long sss = n;
		long long res = 0;
		while(!que.empty()) que.pop();
		for(long long j = 0; j < k; j++)
		{
			if(i & (1 << j))
			{
				que.push({j, 1});
				res += p[j];
				sss++;
			}
		}
		for(long long j = 0; j <= n + k + 1; j++) fa[j] = j;
		for(long long j = 1, cnt = 0; cnt < sss - 1; )
		{
			if(que.empty())
			{
				long long fu = find(e2[j].u), fv = find(e2[j].v);
				if(fu != fv)
				{
					fa[fu] = fv;
					res += e2[j].w;
					cnt++;
				}
				j++;
				continue;
			}
			if(j > m2)
			{
				node2 nd = que.top();
				que.pop();
				
				long long fu = find(n + nd.u + 1), fv = find(w[nd.u][nd.id].second);
				if(fu != fv)
				{
					fa[fu] = fv;
					res += w[nd.u][nd.id].first;
					cnt++;
				}
				
				if(nd.id < n) que.push({nd.u, nd.id + 1});
				continue;
			}
			node2 nd = que.top();
			if(w[nd.u][nd.id].first < e2[j].w)
			{
				que.pop();
				
				long long fu = find(n + nd.u + 1), fv = find(w[nd.u][nd.id].second);
				if(fu != fv)
				{
					fa[fu] = fv;
					res += w[nd.u][nd.id].first;
					cnt++;
				}
				
				if(nd.id < n) que.push({nd.u, nd.id + 1});
			}
			else
			{
				long long fu = find(e2[j].u), fv = find(e2[j].v);
				if(fu != fv)
				{
					fa[fu] = fv;
					res += e2[j].w;
					cnt++;
				}
				j++;
			}
		}
//		printf("%lld\n", res);
		ans = min(ans, res);
	}
	
	printf("%lld\n", ans);
	return 0;
}
