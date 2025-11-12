#include <bits/stdc++.h>
using namespace std;
const int A = 2e5 + 10;
int ans, m = 1, n, num[A];
bool a[A], k;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if (a[i] == 0)
			num[++ m] = i;
	}
	num[++ m] = n + 1;
	for (int i = 1; i < m; i ++)
		ans += (num[i + 1] - num[i] - 1) / 2;
	cout << ans + m - 2;
	return 0;
}
