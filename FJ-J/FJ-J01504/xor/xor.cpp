#include <bits/stdc++.h>
using namespace std;
long long n, a[500005], k, ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int x = 0;
	for (int i = 1; i <= n; i++)
	{
		x = x ^ a[i];
		if (x == k)
		{
			ans++;
			x = 0;
		}
	}
	cout << ans;
	return 0;
}
