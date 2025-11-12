#include <bits/stdc++.h>
using namespace std;
long long n , m , a[105];
bool cmp (long long x , long long y)
{
	return x > y;
}
int main ()
{
	
	freopen ("seat.in" , "r" , stdin);
	freopen ("seat.out" , "w" , stdout);
	cin >> n >> m;
	long long k = n * m;
	cin >> a[1];
	long long t = a[1];
	for (int i = 2;i <= k;i ++)
	{
		cin >> a[i];
	}
	sort (a + 1 , a + k + 1 , cmp);
	long long p = 0;
	for (int i = 1;i <= k;i ++)
	{
		if (t == a[i])
		{
			p = i;
			break;
		}
	}
	long long l;
	if (p % n != 0)
	{
		l = p / n + 1;
	}
	else
	{
		l = p / n;
	}
	long long l2;
	if (l % 2 == 0)
	{
		if (p % n == 0)
		{
			l2 = 1;
		}
		else
		{
			l2 = n - (p % n) + 1;
		}
	}
	else 
	{
		if (p % n == 0)
		{
			l2 = n;
		}
		else
		{
			l2 = p % n;
		}
	}
	cout << l << " " << l2;
	return 0;
}
