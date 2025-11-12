#include<bits/stdc++.h>
using namespace std;
pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {1, 0}};
const int N = 15, M = 110;
pair<int, int> a[M];//first表分数，second表编号 
int solve()
{
	int n, m; scanf("%d %d", &n, &m);
	int num = n * m;
	for (int i = 1; i <= num; i++)
		scanf("%d", &a[i].first), a[i].second = i;
	sort(a + 1, a + num + 1, greater<pair<int, int> >());
	int x = 1, y = 1, d = 0;
	for (int i = 1; i <= num; i++)
	{
		//cout << x << ' ' << y << '\n';
		if (a[i].second == 1) {printf("%d %d", x, y); break;}
		if (d == 1 or d == 3) d = (d + 1) % 4;
		int dx = x + dir[d].first, dy = y + dir[d].second;
		if (dy > n or dy < 1)
			d = (d + 1) % 4, dx = x + dir[d].first, dy = y + dir[d].second;;
		x = dx, y = dy;
	}
	return 0;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
