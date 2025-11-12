#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 100 + 10;
int n, m, a[N], R, rk;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n * m; ++ i)
		scanf("%d", &a[i]);
	R = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for(int i = 1;i <= n * m; ++ i)
		if(a[i] == R)
		{
			rk = i;
			break;
		}
	int x = (rk - 1) / n + 1;
	int y = (rk - 1) % n + 1;
	if(x % 2 == 0)
		y = n + 1 - y;
	printf("%d %d\n", x, y);
	return 0;
}
