#include <bits/stdc++.h>
using namespace std;

long long n, a[200002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	if (n == 3)
	{
		if (a[0] + a[1] > a[2])
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	cout << n << endl;
	return 0;
}
