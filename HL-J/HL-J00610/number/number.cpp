#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	string s;
	int iNumber = 0;
	string sOut;
	string sNumber;
	freopen( "number.in" , "r" , stdin );
	freopen( "number.out" , "w" , stdout );
	cin >> s;
	for( int i = 0 ;  ; i++ )
	{
		if( s[ i ] > 49 && s[i] < 57 ) 
		{
			sNumber += s[ i ];
			iNumber++;
		}
		if( int( s[ i ] ) == 0 ) break;
	}
	for( int i = 57 ; i > 48 ; i-- )
	{
		for( int j = 0 ; j < iNumber ; j++ )
		{	
			if( int( sNumber[ j ] ) == i )cout << sNumber[ j ];
		}
	}
	return 0;
} 
