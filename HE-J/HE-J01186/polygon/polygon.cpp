#include <bits/stdc++.h>
using namespace std;
long long n;
int a[5005] , num = 0;
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n == 3)
	{
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1])
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	if (n == 4)
	{
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1])
		{
			num++;
		}
		else if (a[1] + a[2] > a[4] && a[1] + a[4] > a[2] && a[2] + a[4] > a[1])
		{
			num++;
		}
		else if (a[3] + a[2] > a[4] && a[3] + a[4] > a[2] && a[2] + a[4] > a[3])
		{
			num++;
		}
		else if (a[1] + a[3] > a[4] && a[1] + a[4] > a[3] && a[3] + a[4] > a[1])
		{
			num++;
		}
		if (a[1] + a[2] + a[3] > a[4] && a[1] + a[2] + a[4] > a[3] && a[1] + a[4] + a[3] > a[2] && a[4] + a[2] + a[3] > a[1])
		{
			num++;
		}
		cout << num;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
