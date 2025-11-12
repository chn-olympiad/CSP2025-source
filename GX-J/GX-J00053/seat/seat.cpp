#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std ;
int n , m ;
int a[101] , sum = 0 , ans = 0 ;
bool cmp (int a , int b)
{
	return a > b ;
}
int main()
{
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	cin >> n >> m ;
	for (int i=1 ; i<=n*m ; i++)
	{
		cin >> a[i] ;
	}
	sum = a[1] ;
	sort (a+1 , a+n+1 , cmp) ;
	for (int i=1 ; i<=n*m ; i++)
	{
		if (a[i] == sum)
		{
			ans = i ;
			break ;
		}
	}
	int g = ans / n ;
	if (ans % n == 0)
	{
		cout << g << " " ;
		if (g % 2 == 1)
		{
			cout << n ;
		}
		else
		{
			cout << 1 ;
		}
	}
	else
	{
		cout << g + 1 << " " ;
		if (g % 2 == 1)
		{
			cout << ans % n ;
		}
		else if (g % 2 == 0)
		{
			cout << n - (ans % n) + 1 ;
		}
	}
	return 0 ;
}
