#include <bits/stdc++.h>
using namespace std;
#define LL long long 
const int N = 1e4 + 30;
int n, m, k, num, fa[N], c[15], vis;
pair<int, int> road[N];
priority_queue<pair<int, int> > q;
LL ans;
bool flag[15], flag2[N];
bool spc1 = 1;
int ww[15][N];

int find(int x)
{
	if(fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

bool cp(int x, int y)
{
	return find(x) == find(y);
}

void Ks()
{
	while(!q.empty())
	{
		int w = -q.top().first, u = road[q.top().second].first, v = road[q.top().second].second;
		q.pop();
//		puts("1");
		if(!cp(u, v))
		{
			if(u <= n && !flag2[u]) flag2[u] = 1, vis++;
			if(v <= n && !flag2[v]) flag2[v] = 1, vis++;
			if(((u > n && u <= n + k) || (v > n && v <= n + k)))
			{
				if(vis == n) continue;
				if(flag[max(u, v) - n]) continue;
				flag[max(u, v) - n] = 1;
				for(int i = 1; i <= n; i++) 
				{
//					e[j + n].push_back({i, w + c[j]});	
//					e[i].push_back({j + n, w + c[j]});
					q.push({-(w - ww[max(u, v) - n][i]), ++num});
					road[num] = {i, max(u, v) + k};
				}
			}
			ans += w;
			printf("u:%d, v:%d, w:%d;\n", u, v, w);
//			cout << 114514 << "\n";
			fa[find(u)] = find(v);
		}
	}
}

void KsA()
{
	while(!q.empty())
	{
		int w = -q.top().first, u = road[q.top().second].first, v = road[q.top().second].second;
		q.pop();
		if(!cp(u, v))
		{
			ans += w;
			printf("u:%d, v:%d, w:%d;\n", u, v, w);
//			cout << 114514 << "\n";
			fa[find(u)] = find(v);
		}
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n + 5; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		q.push({-w, ++num});
		road[num] = {u, v};
	}
	for(int j = 1; j <= k; j++)
	{
		scanf("%d", &c[j]);
		if(c[j] != 0) spc1 = 0;
		for(int i = 1; i <= n; i++) 
		{
			scanf("%d", &ww[j][i]);
			q.push({-ww[j][i] - c[j], ++num});
			road[num] = {i, j + n};
		}
	}
	if(spc1 == 1) 
	{
		KsA();
	}
	printf("%lld\n", ans);
	return 0;
}