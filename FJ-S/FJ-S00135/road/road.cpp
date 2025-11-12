#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxx = 1e1 + 1;
const int maxn = 1e6 + 1;
bool vis[maxx];
ll step[maxn];
queue<int> q;
int n, m, k;
ll ans;

struct node
{
	int to, price;
};

vector<node> vec[maxn];

void bfs()
{
	q.push(1);
	step[1] = 0;
	while(!q.empty())
	{
		int u = q.front();
		for(int i = 0; i < vec[u].size(); i++)
		{
			if(step[u] + vec[u][i].price < step[vec[u][i].to])
			{
				step[vec[u][i].to] = step[u] + vec[u][i].price;
				ans += vec[u][i].price;
				q.push(vec[u][i].to);
			}
		}
		q.pop();
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(step, 0x3f3f3f, sizeof(step));
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		vec[u].push_back({v, w});
		vec[v].push_back({u, w});
	}
	bfs();
	printf("%lld", ans);
	return 0;
}
