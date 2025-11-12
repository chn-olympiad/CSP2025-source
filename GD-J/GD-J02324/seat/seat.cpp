#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	x = a[1];
	sort (a + 1,a + n * m + 1);
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == x)
		{
			cnt = n * m - i + 1;
		}
	}
	//cout << cnt << ' '; 
	if ((cnt + n - 1) / n % 2 == 1)
	{
		cout << (cnt + n - 1) / n << ' ' << (cnt + n - 1) % n + 1;
	}
	else
	{
		cout << (cnt + n - 1) / n << ' ' << n - ((cnt + n - 1) % n + 1) + 1;
	}
	return 0;
}
