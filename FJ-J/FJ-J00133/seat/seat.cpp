#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e2 + 1;
int n, m;
bool vis;

struct node
{
	int id, score;
}
ranking[maxn];

bool cmp(node x, node y)
{
	return x.score > y.score;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++)
	{
		scanf("%d", &ranking[i].score);
		ranking[i].id = i;
	}
	sort(ranking + 1, ranking + n * m + 1, cmp);
	int pos = 1;
	for(int i = 1; i <= m; i++)
	{
		if(vis)
		{
			break;
		}
		if(i & 1)
		{
			for(int j = 1; j <= n; j++)
			{
				if(ranking[pos++].id == 1)
				{
					printf("%d %d", i, j);
					vis = true;
					break;
				}
			}
		}
		if(!(i & 1))
		{
			for(int j = n; j >= 1; j--)
			{
				if(ranking[pos++].id == 1)
				{
					printf("%d %d", i, j);
					vis = true;
					break;
				}
			}
		}
	}
	return 0;
}
