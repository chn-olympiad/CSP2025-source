#include <bits/stdc++.h>
using namespace std;

const int p = 998244353;
int a[507];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0') flag = false;
	}
	if (flag)
	{
		int cnt = n;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 0) cnt--;
		}
		if (cnt < m) cout << 0;
		else
		{
			long long mul = 1;
			for (int i = 1; i <= n; i++)
			{
				mul = mul * i % p;
			}
			cout << mul;
		}
	}
	return 0;
}
