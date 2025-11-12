#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
long long x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			cin >> a[(i - 1) * m + j];
		}
	}
	x = a[1];
	sort(a + 1,a + n * m + 1);
	reverse(a + 1,a + n * m + 1);
	int i = 0;
	int r = 1,l = 0;
	while (i < n * m)
	{
		if (r % 2 == 1)
		{
			l++;
		}
		else
		{
			l--;
		}
		if (l <= 0)
		{
			l = 1;
			r++;
		}
		if (l >= n + 1)
		{
			l = n;
			r++;
		}
		i++;
		if (a[i] == x)
		{
			cout << r << " " << l;
			break;
		}
	}
	return 0;
}
