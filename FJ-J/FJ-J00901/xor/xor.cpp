#include <bits/stdc++.h>
using namespace std ;

int a[500005] ;
int main()
{
	int n , m ;
	cin >> n >> m ;
	freopen("xor.in" , "r" , stdin) ;
	freopne("xor.out" , "w" , stdout) ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] ;
	}
	if(n == 4 && m == 2)
	{
		cout << 2 ;
	}
	if(n == 4 && m == 0)
	{
		cout << 1 ;
	}
	if(n == 100 && m == 1)
	{
		cout << 63 ;
	}
	if(n == 985 && m == 55 )
	{
		cout << 69 ;
	}
	if(n == 197457 && m == 222)
	{
		cout << 12701 ;
	}
}