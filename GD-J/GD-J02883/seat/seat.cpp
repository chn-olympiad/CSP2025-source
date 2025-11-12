#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 1e2 + 10;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while('0' > ch || ch > '9'){ if(ch == '-'){ w = -1;} ch = getchar();}
	while('0' <= ch && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
	return s * w;
}
int n, m;
//int a[N];
struct node
{
	int x, idx;
}a[N];
bool cmp(node a, node b)
{
	return a.x > b.x;
}
bool vis[N][N];
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n * m; i++) a[i] = {read(), i};
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n; i++) vis[i][0] = 1, vis[i][m] = 1;
//	for(int i = 1; i <= n * m; i++) cout << a[i].x << " " << a[i].idx << endl; 
	int x = 1, y = 1;
	bool lst = 0;
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i].idx == 1) return printf("%d %d\n", x, y), 0;
//		cout << x << " " << y << endl;
		vis[x][y] = 1;
		if((y == m || (y == 1 && x != 1)) && !lst)
		{
			x++;
			lst = 1;
		}
		else
		{
			lst = 0;
			if(vis[x][y - 1]) y++;
			else y--;
		}
	}
	printf("%d %d\n", n, m);
	return 0;
}
/*
4 4
5 4 2 9 3 10 11 12 13 34 45 23 54 65 99 100
1 2 3 4 5 6  7  8  9  10 11 12 13 14 15 16
*/
