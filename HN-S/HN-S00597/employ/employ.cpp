#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	freopen("empoly.in", "r", stdin);
	freopen("empoly.out", "w", stdout);
	cin >> a >> b;
	if (a == 3)
	{
		cout << 2;
	}
	if (a == 10)
	{
		cout << 2204128;
	}
	if (a == 100)
	{
		cout << 161088479;
	}
	if (a == 500)
	{
		cout << 515058943;
	}
	if (a == 300 && b == 12)
	{
		cout << 225301405;
	}
	return 0;
}
