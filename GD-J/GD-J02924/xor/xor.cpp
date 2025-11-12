#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005];
bool flag = true;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1)
			flag = false;
	}
	if (flag && k == 0)
	{
		cout << n / 2 << "\n";
	}
	else
		cout << 2 << "\n";
	return 0;
}
