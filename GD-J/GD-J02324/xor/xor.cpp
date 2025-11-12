#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		if (a[i] == k)
		{
			ans++;
			continue;
		}
		long long x = a[i];
		for (int j = i + 1;j <= n;j++)
		{
			x = x ^ a[j];
			if (x == k)
			{
				ans++;
				i = j;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
