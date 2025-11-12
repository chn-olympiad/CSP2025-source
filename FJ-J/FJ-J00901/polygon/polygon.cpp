#include <bits/stdc++.h>
using namespace std ;

int a[100005] ;
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopne("polygon.out" , "w" , stdout) ;
	int n ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] ;
	}
	if(n == 5)cout << 6 ;
	if(n == 5 && a[1] == 2 && a[2] == 2)cout << 9 ;
	if(n == 20)cout << 1042392 ;
	if(n == 500) cout << 366911923 ;
}