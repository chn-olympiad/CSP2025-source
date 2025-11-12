#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 15;
int n, m, y[N][N];
struct num
{
	int code, id;
}  x[N*N];
bool cmp(const num &x, const num &y)
{
	return x.code > y.code;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> x[i].code, x[i].id = i;
	sort(x+1, x+n*m+1, cmp);
	
	for (int j = 1; j <= m; j += 2)
		for (int i = 1; i <= n; i++)
			y[i][j] = x[(j-1) * n + i].id;
	
	for (int j = 2; j <= m; j += 2)
		for (int i = n; i >= 1; i--)
			y[i][j] = x[j * n - i + 1].id;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (y[i][j] == 1)
				cout << j << ' ' << i;
	return 0;
}
