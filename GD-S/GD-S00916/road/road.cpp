#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int c = 1, s = 0;
	char ch = getchar();
	for (;!isdigit(ch);ch = getchar()) if (ch == '-') c = -1;
	for (;isdigit(ch);ch = getchar()) s = (s << 1) + (s << 3) + (ch ^ '0');
	return c * s;
}

const int N = 10010, M = 100010;

int n, m ,k, road[N][N], ans;
bool r1[N][N];

int dfs(int x, int step, int num)
{
	if (step == n) return num;
	int minn = 0x3f3f3f3f;
	for (int i = 1;i <= n;i++)
	{
		if (r1[i][x]) continue;
		if (i != x)
		{
			r1[x][i] = 1;
			r1[i][x] = 1;
			minn = min(dfs(i, step + 1, num + road[i][x]), minn);
			r1[x][i] = 0;
			r1[i][x] = 0;
		}
	}
	return minn;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(road, 0x3f3f3f3f, sizeof road);
	n = read();m = read();k = read();
	for (int i = 1;i <= m;i++)
	{
		int a, b, c;
		a = read();b = read();c = read();
		road[a][b] = min(road[a][b], c);
		road[b][a] = min(road[b][a], c);
	}
	for (int i = 1;i <= k;i++)
	{
		int a;
		a = read();
		for (int j = 1;j <= n;j++)
		{
			int b;
			b = read();
			road[i][j] = min(road[i][j], a + b);
			road[j][i] = min(road[j][i], a + b);
		}
	}
	int minx = 0x3f3f3f3f;
	for (int i = 1;i <= n;i++)
	{
		minx = min(minx, dfs(i, 0, 0));
	}
	printf("%d", minx);
	return 0;
}

