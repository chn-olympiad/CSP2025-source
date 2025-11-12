#include <bits/stdc++.h>

using namespace std;

long long n,m,a[500],r = 1,C,R;


int main()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	scanf ("%lld %lld",&n,&m);
	for (int i = 1;i <= n * m;i++)
	{
		scanf ("%lld",&a[i]);
	}
	for (int i = 1;i <= n * m;i++)
	{
		for (int h = i;h <= n * m;h++)
		{
			if (a[h] > a[i])
			{
				if (r == h) r = i;
				if (r == i) r = h;
				long long ll = a[h];
				a[h] = a[i];
				a[i] = ll;
			}
		}
	}
	if (r % n == 0)
	{
		C = r / n;
	}
	else
	{
		C = r / n + 1;
	}
	if (C % 2 == 1)
	{
		if (r % n == 0) R = n;
		else R = r % n;
	}
	else
	{
		if (r % n == 0) R = 1;
		else R = n - r % n + 1;
	}
	printf ("%lld %lld",C,R);
	return 0;
}
