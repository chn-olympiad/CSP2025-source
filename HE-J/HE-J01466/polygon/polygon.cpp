#include <bits/stdc++.h>
using namespace std;
const int A = 5e3 + 10;
int a[A], ans, cnt, n, num, sum;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	for (int i = 7; i < (1 << n); i ++)
	{
		cnt = num = sum = 0;
		for (int j = 0; j < n; j ++)
			if (i & (1 << j))
				cnt ++, num = max(num, a[j]), sum += a[j];
		if (cnt < 3)
			continue;
		if (sum > num * 2)
			ans ++;
	}
	cout << ans;
	return 0;
}
