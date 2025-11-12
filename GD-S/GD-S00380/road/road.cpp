#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, vis[11005], dis[11005];
bool flag[11005];
vector<int> p[11005], g[11005];
int ans;

void spfa()
{
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for (int i = 0; i < p[x].size(); i++)
		{
			int y = p[x][i];
			if (g[x][i] + dis[x] < dis[y])
			{
				dis[y] = dis[x] + g[x][i];
				if (vis[y] == 0)
				{
					q.push(y);
					vis[y] = 1;
				}
			}
		}
	}
}

void f()
{
	for (int i = 1; i <= n + k; i++)
	{
		int ansj = 0, minn = 1e9;
		for (int j = 1; j <= n + k; j++)
		{
			if (dis[j] < minn && flag[j] == 0)
			{
				minn = dis[j];
				ansj = j;
			}
		}
		flag[ansj] = 1;
		ans += minn;
		for (int j = 0; j < p[ansj].size(); j++)
		{
			int K = p[ansj][j];
			dis[K] = min(dis[K], g[K][ansj]);
		}
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		p[a].push_back(b);
		p[b].push_back(a);
		g[a].push_back(c);
		g[b].push_back(c);
	}
	for (int i = 1; i <= k; i++)
	{
		int a;
		cin >> a;
		for (int j = 1; j <= n; j++)
		{
			int c;
			cin >> c;
			p[n + i].push_back(j);
			p[j].push_back(n + i);
			g[n + i].push_back(c);
			g[j].push_back(c);
		}
	}
	spfa();
	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << endl;
	}
	f();
	cout << ans;
	return 0;
}
