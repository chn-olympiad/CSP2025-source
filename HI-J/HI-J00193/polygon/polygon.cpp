#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a, x, n, t = 0;
	cin >> a;
	for (int i = 1;i <= a;i++)
	{
		cin >> x;
		t += x;
	}
	cout << t - 6;
	return 0;
}
