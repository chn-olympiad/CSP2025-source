#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std ;
int n ;
int a[5001] , b[5001] , ans = 0 ;
long long ah[5001] ;
bool cmp (int a , int b)
{
	return a < b ;
}
int main()
{
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	cin >> n ;
	for (int i=1 ; i<=n ; i++)
	{
		cin >> a[i] ;
	}
	for (int i=1 ; i<=n ; i++)
	{
		b[i] = a[i] * 2 ;
	}
	for (int i=1 ; i<=n ; i++)
	{
		for (int j=1 ; j<=i ; j++)
		{
			ah[i] += a[j] ;
		}
	}
	for (int i=1 ; i<=n ; i++)
	{
		if (b[i] < ah[i])
		{
			ans ++ ;
			ans %= 998244353 ;
		}
	}
	cout << ans % 998244353 ;
	return 0 ;
}
