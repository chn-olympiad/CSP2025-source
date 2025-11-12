#include <bits/stdc++.h>

using namespace std;
int cnt[15];

int main()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin >> a;
	int len = a.size();
	for (int i = 0;i < len;i ++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			cnt[a[i] - '0'] ++;
		}
	}
	bool f = 0;
	for (int i = 9;i >= 1;i --)
	{
		for (int j = 1;j <= cnt[i];j ++)
		{
			f = 1;
			cout << i;
		}
	}
	if (f == 0)
	{
		cout << 0;
	}
	else
	{
		for (int i = 1;i <= cnt[0];i ++)
		{
			cout << 0;
		}
	}
	return 0;
}
