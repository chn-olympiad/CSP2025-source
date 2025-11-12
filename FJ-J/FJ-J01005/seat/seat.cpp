#include <bits/stdc++.h>
using namespace std;
long long int n , m , x , y = 0 ;
int a[100005] ;
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	
	cin >> n >> m ;
	for ( int i = 1 ; i <= n * m ; i ++ )
	{
		cin >> a[i];
	}
	int c = a[1] ;
 	sort( a + 1 , a + 1 + n*m );
	for( int i = 1 ; i <= n*m / 2 ; i ++ )
	{
		int t = a[i];
		a[i] = a[n*m-i+1];
		a[n*m-i+1] = t ;
	}
	for ( int i = 1 ; i <= n*m ; i ++ )
	{
		if ( a[i] == c )
		{
			for ( int j = 1 ; j <= n ; j ++ )
			{
				if ( i >= m*(j-1) + 1 && i <= j * m )
				{
					y = j ;
				}
			}
			while ( i > m )
			{
				i -= m ;
			}
			if ( y % 2 == 1 )
			{
				x = i ;
			}
			else
			{
				x = m - i + 1 ;
			}
			cout << y << " " << x ; 
			break;
		}
	}
	return 0; 	
}

