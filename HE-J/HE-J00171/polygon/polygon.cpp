#include<bits/stdc++.h>
using namespace std;

int a[1005], n, sum = 0, maxn = -1e9;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
		maxn = max(maxn, a[i]);
	}
	if (sum > 2 * maxn) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
