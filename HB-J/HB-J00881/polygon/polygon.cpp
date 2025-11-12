#include <bits/stdc++.h>

using namespace std;

long long n,a[10000],s = 0;
bool bo = 1;


int main()
{
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	scanf ("%lld",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf ("%lld",&a[i]);
		if (a[i] != 1) bo = 0;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int h = i;h <= n;h++)
		{
			if (a[h] > a[i])
			{
				long long ll = a[h];
				a[h] = a[i];
				a[i] = ll;
			}
		}
	}
	if (bo = 1) printf ("%lld",a[1] * 2 -1);
	else printf ("%lld",a[1] / 2 + 1);
	return 0;
}	
