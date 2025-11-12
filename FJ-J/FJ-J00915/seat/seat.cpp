#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], k;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	k = a[1];
	sort(a + 1, a + n * m + 1);
	reverse(a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == k)
		{
			k = i;
			break;
		}
	}
	if (k % n == 0)
	{
		cout << k / n << " ";
		if (k / n % 2 == 1)
		{
			cout << n;
		}
		else
		{
			cout << 1; 
		}
	}
	else
	{
		cout << k / n + 1 << " ";
		if (k / n % 2 == 0)
		{
			cout << k % n;
		}
		else
		{
			cout << n - k % n + 1; 
		}
	}
	return 0;
}
