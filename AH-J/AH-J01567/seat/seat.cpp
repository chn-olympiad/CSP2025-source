#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],r,l = 1;
bool cmp(long long a1,long long a2)
{
	return a1 > a2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for (long long i = 1;i <= n * m;i++)
	{
		if (a[i] == r)
		{
			r = i;
			break;
		}
	}
	while (r > n)
	{
		l++;
		r -= n;
	}
	cout << l << " ";
	if (l % 2 == 0)
	{
		cout << (n - r + 1);
	}
	else
	{
		cout << r;
	}
}
