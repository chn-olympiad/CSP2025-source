#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std ;

const int N = 1e2 + 5 ;

int n, m, rk = 1, resLine, resCol,  a[N] ;

int main()
{
	freopen("seat.in", "r", stdin) ;
	freopen("seat.out", "w", stdout) ;
	
	cin >> n >> m ;
	for (int i = 1 ; i <= n * m ; i ++ )
		cin >> a[i] ;
	
	for (int i = 2 ; i <= n * m ; i ++ )
		if (a[i] > a[1])
			rk ++  ;
	
	resCol = ceil(1.0 * rk / n) ;
	if (resCol & 1)
	{
		resLine = rk % n ;
		if (!resLine) resLine = n ;
	}
	else resLine = n - rk % n + 1 ;
	
	cout << resCol << ' ' << resLine << '\n' ;
	
	return 0 ;
}
