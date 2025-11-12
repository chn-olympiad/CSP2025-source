#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int n, m;
int a[maxn];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	int k = a[1];
	int f = 0;
	sort(a + 1, a + 1 + n * m);
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == k)
		{
			f = n * m - i + 1;
			break;
		}
	}
	int x = f / n;
	if(f % n != 0)
		x++;
	cout << x << ' ';
	if(f % (2 * n) <= n)
	{
		if(f % (2 * n) == 0)
			cout << 1;
		else
			cout << f % (2 * n);
	}
	else
		cout << n + n + 1 - f % (2 * n);
	return 0;
}
/*
4 3
7 6 1 2 3 4 5 8 9 10 11 12
*/
