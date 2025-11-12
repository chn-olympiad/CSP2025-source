#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	int p, pr, v;
	double pro;
	bool operator<(node n2)
	{
		if (pro == n2.pro)
			return v > n2.v;
		return pro > n2.pro;
	}
} sat[(int)1e6 + 1];
int idx = 0;
int capa[4];
bool pvis[(int)1e6 + 1];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(sat, 0, sizeof(sat));
		memset(capa, 0, sizeof(capa));
		memset(pvis, 0, sizeof(pvis));
		idx = 0;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			sat[idx++] = { i, 1, a, 2 * a - b - c };
			sat[idx++] = { i, 2, b, 2 * b - a - c };
			sat[idx++] = { i, 3, c, 2 * c - a - b };
		}
		sort(sat, sat + idx);
		ll ans = 0;
		for (int i = 0; i < idx; i++)
		{
			if (!pvis[sat[i].p] && capa[sat[i].pr] < n / 2)
			{
				pvis[sat[i].p] = true;
				capa[sat[i].pr]++;
				ans += sat[i].v;
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
