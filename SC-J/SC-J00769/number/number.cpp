#include<bits/stdc++.h>
using namespace std;
string check;
int f[114];
int main()
{
	freopen( "number.in","r",stdin );
	freopen( "number.out","w",stdout );
	cin >> check;
	for( int i = 0 ; i < check.size() ; i ++ )
	{
		if( check[i] >= '0' && check[i] <= '9' )
			f[check[i] - '0'] ++;
	}
	for( int i = 9 ; i >= 0 ; i -- )
		while( f[i] )
		{
			printf( "%d",i );
			f[i] --;
		}
	return 0;
 } 