#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m, a[N * N], p, x, y, len;

bool cmp(int num1, int num2)
{
	return num1 > num2;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	len = n * m;
	for(int i = 1; i <= len; i++)
	{
		scanf("%d", a + i);
	}
	p = a[1];
	sort(a + 1, a + 1 + len, cmp);
	for(int i = 1; i <= len; i++)
	{
		if(a[i] == p)
		{
			x = (i % (2 * n));
			if(x == 0) x = n;
			if(x > n)
			{
				x = x - n;
				x = n - x + 1;
			}
			if(i % n != 0)
				y = i / n + 1;
			else y = i / n;
			break;
		}
	}
	printf("%d %d\n", y, x);
	return 0;
}
