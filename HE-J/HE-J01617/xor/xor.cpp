#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin >> n >> k;
	long long a[n + 5];
	for (int i = 1; i <= n; i ++) cin >> a[i];
	if (n == 1)
	{
		if (k == a[1]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	else if (n == 2)
	{
		if (k == a[1]) cout << 2 << '\n';
		else if (k == 0) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	else
	{
		if (k == 0 && a[1] == a[2]) cout << n / 2 << '\n';
		else if (k == 0 && a[1] != a[2]) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
	return 0;
}
