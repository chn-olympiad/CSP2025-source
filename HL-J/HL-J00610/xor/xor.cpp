#include <iostream>
#include <cstdio>
using namespace std;
int A[100000];
int solve( int a , int b )
{
	a++;
	if( b == a )return A[a]^A[b];
	return solve( a , b );
}
int choose( int a , int b , int k )
{
	int out = 0;
	for( int i = a ; i <= b ; i++ )
	{
		for( int j = b ; j > i ; j-- )
		{

			if( solve( i , j ) == k )
			{cout << out << endl; 
				out++;
				if( a - i == 0 ) out += solve( j , b );
				else
				{
					out += solve( a , i );
					out += solve( j , b );
				}
			}
		}
	}
	return out;
}
int main()
{
	//freopen( "xor.in" , "r" , stdin );
	//freopen( "xor.out" , "w" , stdout );
	int iNumber,k;
	cin >> iNumber >> k;
	for( int i = 0 ; i < iNumber ; i++ )
		cin >> A[i];
	cout << choose( 0 , iNumber-1 , k );
}
