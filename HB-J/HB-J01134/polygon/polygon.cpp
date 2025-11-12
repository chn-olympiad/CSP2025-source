#include <bits/stdc++.h>
using namespace std;

int n, a[5005], b[5005], m[5005], ans;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	do
	{
		memset(b, 0, sizeof(b));
		memset(m, 0, sizeof(m));
		for (int i = 1; i <= n; i++)
		{
			b[i] = b[i - 1] + a[i];
			m[i] = max(m[i - 1], a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (b[i] > m[i] * 2)
				ans++;
		}
	}while(next_permutation(a + 1, a + n + 1));
	cout << ans % 998244353 << endl;
	return 0;
}
