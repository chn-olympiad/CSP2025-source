#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x, num;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) 
		cin >> a[i];
	x = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == x)
		{
			num = i;
			break;
		}
	}
	cout << (num + n - 1) / n << " ";
	if ((num + n - 1) / n % 2)
	{
		if (num % n == 0)
			cout << n;
		else
			cout << num % n;
	}
	else
	{
		if (num % n == 0)
			cout << 1;
		else
			cout << n - num % n + 1;
	}
	return 0;
}
