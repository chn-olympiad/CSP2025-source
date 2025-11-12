#include <bits/stdc++.h>
using namespace std;
int a[1005],n;
int maim()
{
	freopen("number.in",r,stdin);
	freopen("number.out",w,stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] == 9)
		{
			cout << 9;
		}
		else if (a[i] == 8)
		{
			cout << 8;
		}
		else if (a[i] == 7)
		{
			cout << 7;
		}
		else if (a[i] == 6)
		{
			cout << 6;
		}
		else if (a[i] == 5)
		{
			cout << 5;
		}
		else if (a[i] == 4)
		{
			cout << 4;
		}
		else if (a[i] == 3)
		{
			cout << 3;
		}
		else if (a[i] == 2)
		{
			cout << 2;
		}
		else if (a[i] == 1)
		{
			cout << 1;
		}
	}
	return 0;
}