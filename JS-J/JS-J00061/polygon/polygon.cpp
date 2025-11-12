#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[5005];
int cnt;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (a[i] + a[j] > a[k] && a[j] + a[k] > a[i] && a[i] + a[k] > a[j])
				{
					cnt++;
					cnt %= 998244353;
				}
			}
		}
	}
	cout << cnt % 998244353;
	return 0;
}
