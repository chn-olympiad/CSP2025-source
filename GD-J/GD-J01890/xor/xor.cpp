#include <bits/stdc++.h>
using namespace std;
long long n , k , f[500005] , len , l[500005];
struct node
{
	long long x , y;
}a[500005];
bool cmp (node xx , node yy)
{
	return xx.y == yy.y ? xx.x < yy.x : xx.y < yy.y;
}
int main ()
{
	
	freopen ("xor.in" , "r" , stdin);
	freopen ("xor.out" , "w" , stdout);
	cin >> n >> k;
	scanf ("%lld" , &l[1]);
	f[1] = l[1];
	for (int i = 2;i <= n;i ++)
	{
		scanf ("%lld" , &l[i]);
		f[i] = f[i - 1] ^ l[i];
	}
	for (int i = 1;i <= n;i ++)
	{
		if (f[i] == k)
		{
			a[++ len].x = 1;
			a[len].y = i;
		}
		for (int j = 2;j <= i;j ++)
		{
			if (i == j && l[i] == k)
			{
				a[++ len].x = j;
				a[len].y = i;
			}
			if ((f[i] ^ f[j - 1]) == k)
			{
				a[++ len].x = j;
				a[len].y = i;
			}
		}
	}
//	for (int i = 1;i <= len;i ++)
//	{
//		cout << a[i].x << " " << a[i].y << endl;
//	}
	sort (a + 1 , a + len + 1 , cmp);
	long long ans = 1;
	long long flag = a[1].y;
	for (int j = 2;j <= len;j ++)
	{
		long long w = INT_MAX;
		for (int i = j;i <= len;i ++)
		{
			if (a[i].x > flag && a[i].y < w)
			{
				w = a[i].y;
			}
		}
		if (w != INT_MAX) ans ++ , flag = w;
	}
	printf ("%lld" , len >= 1 ? ans : 0);
	return 0;
}
