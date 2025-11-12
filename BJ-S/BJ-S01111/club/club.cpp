#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int NR = 1e5+10;
int a[NR][5], d[NR];

bool cmp(int i, int j)
{
	return d[i] < d[j];
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", a[i] + 1, a[i] + 2, a[i] + 3);
		vector<int> v[5];
		v[1].clear(), v[2].clear(), v[3].clear();
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int t = 1;
			d[i] = a[i][1] - max(a[i][2], a[i][3]);
			if (a[i][2] > a[i][t]) t = 2, d[i] = a[i][2] - max(a[i][1], a[i][3]);
			if (a[i][3] > a[i][t]) t = 3, d[i] = a[i][3] - max(a[i][1], a[i][2]);
			ans += a[i][t], v[t].push_back(i);
			
		}
		int t = 1;
		if (v[2].size() > v[t].size()) t = 2;
		if (v[3].size() > v[t].size()) t = 3;
		sort(v[t].begin(), v[t].end(), cmp);
		for (int i = 0; i < int(v[t].size()) - (n >> 1); i++)
			ans -= d[v[t][i]];
		printf("%d\n", ans);
	}
	return 0;
}