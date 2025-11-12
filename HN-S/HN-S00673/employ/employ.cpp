#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	long long ans = 1;
	while (m--)
	{
		ans *= n;
		ans %= 998244353;
		n--;
	}
	cout << ans;
	return 0;
}
