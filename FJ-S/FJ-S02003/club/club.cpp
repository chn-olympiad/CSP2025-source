#include <bits/stdc++.h>
using namespace std;

int highest, maxs = -1;
int a[100005][5], f[5];
long long sum = 0;
int n;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cin >> n;
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[j][1] >> a[j][2] >> a[j][3];
			if (f[1] < n/2 && a[j][1] > a[j][2])
			{
				sum += a[j][1];
				f[1]++;
			}
			else
			{
				sum += a[j][2];
			}
		}
		cout << sum << endl;
		sum = 0;
	}
	return 0;
}
