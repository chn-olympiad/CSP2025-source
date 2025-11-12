#include <bits/stdc++.h>
using namespace std;
long long n , m;
int a[105];
int b , sum = 0;
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >>n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	b = a[1];
	sort(a + 1 , a + n * m + 1);
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == b)
		{
			sum = i;
		}
	}
	if (sum == 1)
	{
		cout << m << " " << n;
	}
	else if (n <= 1)
	{
		cout << m - sum + 1 << " " << n;
	}
	else if (n <= 2 && m <= 2)
	{
		if (sum < 2)
		{
			cout << m << " " << sum;
		}
		else if (sum = 3)
		{
			cout << 2 << " " << 2;
		}
		else
		{
			cout << 1 << " " << 2;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
