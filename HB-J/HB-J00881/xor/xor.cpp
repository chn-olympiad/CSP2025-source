#include <bits/stdc++.h>

using namespace std;

long long n,k,a[550000],s2[550000],l = 0,ll = 0;


int main()
{
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	scanf ("%lld %lld",&n,&k);
	s2[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		scanf ("%lld",&a[i]);
		s2[i] = a[i] ^ s2[i - 1];
	}	
	for (int i = 1;i <= n;i++)
	{
		for (int h = i;h <= n;h++)
		{
			if (i == h) 
			{
				if (s2[h] == k) l++;
			}
			else 
			{
				if (abs(s2[h] - s2[i]) == k) l++;
			}
		}
	}
	printf ("%lld ",l);
	return 0;
}
