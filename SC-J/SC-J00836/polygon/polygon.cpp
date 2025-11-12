#include <bits/stdc++.h>
using namespace std;
int n,sum,a;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
	}
	for (int i = 3; i <= n; i++)
	{
		sum = (sum + (2 + n - i) * (1 + n - i) / 2) % 998244353;
	}
	cout << sum;
	return 0;
} 