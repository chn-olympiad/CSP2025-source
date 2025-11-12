#include <bits/stdc++.h>
using namespace std;
int mmap[10000][10000];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = 0, m = 0, k = 0, sum = 0;
	memset(mmap, -1, sizeof(mmap));
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i)
	{
		int u = 0, v = 0, w = 0;
		scanf("%d%d%d", &u, &v, &w);
		mmap[u - 1][v - 1] = w;
		mmap[v - 1][u - 1] = w;
	}
	vector<int> d;
	d.push_back(0);
	for (int i = 1; i < n; ++i)
	{
		int wmin = 1000000001, pos = 0, ppos = 0;
		for (int k : d)
			for (int j = 0; j < n; ++j)
				if (mmap[k][j] != -1)
					if (mmap[k][j] < wmin)
					{
						wmin = mmap[k][j];
						pos = j;
						ppos = k;
					}
		sum += wmin;
		mmap[ppos][pos] = -1;
		mmap[pos][ppos] = -1;
		d.push_back(pos);
	}
	printf("%d", sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
