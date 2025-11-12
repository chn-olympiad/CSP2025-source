#include <iostream>
#include <cstdio>
using namespace std;
int iStudents[ 100 ];
int mn;
void Number1( int x )
{
	int change = 0;
	if( iStudents[ x ] < iStudents[ x + 1 ] )
	{
		change = iStudents[ x ];
		iStudents[ x ] = iStudents[ x + 1 ];
		iStudents[ x + 1 ]  = change;
	}
}
void Number2( int turn )
{
	for( int i = 0 ; i < ( mn - turn )+1 ; i++ )
		Number1( i );
}
int main()
{
	int m,n;
	int x = 1,y = 0;
	freopen( "seat.in" , "r" , stdin );
	freopen( "seat.out" , "w" , stdout );
	cin >> n >> m;
	mn = n*m;
	for( int i = 0 ; i < mn ; i++ )
		cin >> iStudents[ i ];
	int r = iStudents[0];
	for( int i = 1 ; i < mn - 1 ; i++ )
		Number2( i );
	for( int i = 0 ; i < mn ; i++ )
	{
		cout << iStudents[i] << endl;
	}
	for( int i = 0 ; i < mn ; i++ )
	{
		y++;
		if( y % n == 0 )
		{
			y = 0;x++;
		}
		if( r == iStudents[ i ] )
			cout << x << " " << y;
	}
	return 0;
}
