#include <bits/stdc++.h>
using namespace std;
const int N = 520;
int n, m;
int a[N];
int score, pos = 0;
int mp[N][N];
bool _CMP_(int a, int b) { return a > b; }
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[(i - 1) * m + j]);
	score = a[1];
	sort(a + 1, a + n * m + 1, _CMP_);
	for (int x = 1; x <= m; x++)
		if (x & 1)
			for (int y = 1; y <= n; y++)
				mp[y][x] = a[++pos];
		else
			for (int y = n; y > 0; y--)
				mp[y][x] = a[++pos];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mp[i][j] == score)
			{
				printf("%d %d", j, i);
				break;
			}
	return 0;
}