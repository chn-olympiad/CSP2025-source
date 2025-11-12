#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[1000005],sum;
int xro(int a,int b)
{
	int sa[1005],sb[1005],sc[1005];
	int i = 1,c = 0;
	while (a > 0)
	{
		sa[i] = a % 2;
		a /= 2;
		i++;
	}
	sa[0] = i - 1;
	if (sa[0] < 1)
	{
		sa[0] = 1;
	}
	i = 1;
	while (b > 0)
	{
		sb[i] = b % 2;
		b /= 2;
		i++;
	}
	sb[0] = i - 1;
	if (sb[0] < 1)
	{
		sb[0] = 1;
	}
	int h = max(sa[0],sb[0]);
	for (int i = 1;i <= h;i++)
	{
		if (sa[i] == 1 && sb[i] == 1)
		{
			sc[i] = 0;
		}
		else if (sa[i] == 0 && sb[i] == 1)
		{
			sc[i] = 1;
		}
		else if (sa[i] == 1 && sb[i] == 0)
		{
			sc[i] == 1;
		}
		else if (sa[i] == 0 && sb[i] == 0)
		{
			sc[i] = 0;
		}
	}
	int u = 1;
	for (int i = 1;i <= h;i++)
	{
		c += sc[i] * u;
		u *= 2;
	}
	return c;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int l = 1,sw = 0,y = 0;
	while (l <= n)
	{
		if (a[l] == k)
		{
			sum++;
			sw = l;
			l++;
			continue;
		}
		else
		{
			y = xro(y,a[l]);
			if (y == k)
			{
				sw = l;
				sum++;
				y = 0;
			}
			l++;
		}	
	}
	cout << sum;
	return 0;
} 
