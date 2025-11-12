#include <bits/stdc++.h>
using namespace std;
int n, q, b[1005][1005], a[1005], t;
bool m[1005][1005];
bool cmp(int a, int b)
{
	return a > b;
}
void dfs(int s, int num, int x, int y)
{
	if(num == t)
	{
		cout << x << " " << y ;
		exit(0);
	}
	if(m[x + 1][y] == 0 && x + 1 <= n)
	{
		int p = s + 1;
		dfs(s + 1, a[p], x + 1, y);
	}
	if(m[x - 1][y] == 0 && x - 1 >= 1)
	{
		int p = s + 1;
		dfs(s + 1, a[p], x - 1, y);
	}
	if(x + 1 > n || x - 1 < 1)
	{
		int p = s + 1;
		dfs(s + 1, a[p], x, y + 1);
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> q ;
	for(int i = 1; i <= n * q; i++)
	{
		cin >> a[i] ;
	}
	t = a[1];
	sort(a + 1, a + n * q + 1, cmp);
	m[1][1] = 1;
	b[1][1] = a[1];
	dfs(1, a[1], 1, 1);
	return 0;
}
