#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[110];
int R, now;
int x, y;

bool cmp(int x, int y)
{
	return x > y;
}


int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++)
	{
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int l = 1, r = n * m, mid;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(a[mid] == R)
		{
			now = mid;
			break;
		}
		else if(a[mid] < R)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	x = now / n;
	if(now % n)
	{
		x ++;
	}
	y = (now - 1) % n + 1;
	if(x&1)
	{
		cout << x << ' ' << y << '\n';
	}
	else
	{
		cout << x << ' ' << n - y + 1 << '\n';
	}
	return 0;
}
