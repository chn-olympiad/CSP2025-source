#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main ()
{
	freopen ("polygon.in" , "r" , stdin);
	freopen ("polygon.out" , "w" , stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1 , a + n + 1);
	if (n <= 3)
	{
		if (a[1] + a[2] > a[3])
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		int cnt = 0;
		for (int i = 1; i <= n - 2; i++)
		{
			cnt += i;
		}
		cout << cnt;
	}
	return 0;
} 
