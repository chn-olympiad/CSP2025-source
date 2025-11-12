#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define x first
#define y second

const int N = 1e5 + 5, M = 1e7 + 5;
const LL INF = 0x7fffffffffffffff; 

int n, m, k;

int head[N], idx;
struct Edge
{
	int to;
	LL val;
	int nxt;
}edge[M];

void Add(int u, int v, LL w)
{
	idx ++ ;
	edge[idx].to = v, edge[idx].val = w;
	edge[idx].nxt = head[u], head[u] = idx;
}

int t;

int cnt;
LL sum, tmp, res = INF;
LL dis[N];
bool vis[N];
priority_queue<pair<LL, int>, vector<pair<LL, int> >, greater<pair<LL, int> > > q;
void Prim(int s)
{
	cnt = 0, sum = 0;
	memset(vis, false, sizeof vis);
	memset(dis, 0x7f, sizeof dis); dis[s] = 0;
	while (!q.empty()) q.pop();
	q.push({0, s}); 
	
	bool flag = false;
	while (!q.empty())
	{
		int u = q.top().y;
		q.pop();
		
		if (vis[u]) continue;
		vis[u] = true;
		
		cnt ++ ;
		sum += dis[u];
		if (s == 1 && cnt == t || s == 0 && cnt > t) break;
		
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			LL w = edge[i].val;
			
			if (dis[v] > w)
			{
				dis[v] = w;
				q.push({dis[v], v});
			}
		}
	}
	
	res = min(res, sum);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	t = n;
	while (m -- )
	{
		int u, v; LL w; cin >> u >> v >> w;
		Add(u, v, w), Add(v, u, w);
	}
	Prim(1);
	while (k -- )
	{
		int c; cin >> c;
		t ++ ;
		Add(0, t, c);
		for (int i = 1; i <= n; i ++ )
		{
			LL a; cin >> a;
			Add(t, i, a);
		}
	}
	Prim(0);
	
	cout << res << '\n';

	return 0;
}

