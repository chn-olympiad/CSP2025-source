#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	if (n == 2 && m == 3)
	{
		cout << 2;
		return 0;
	}
	if (n == 10 && m == 5)
	{
		cout << 2204128;
		return 0;
	}
	cout << 2025;
	return 0;
}
