#include<iostream>
int main()
{
	int a[ 232 ]/*ÐÐ,ÁÐ*/ , n , m , i , j , ans , c;
	scanf( "%d %d" , &n , &m );
	for( i = 0; i < n * m; i ++ )
	{
		scanf( "%d" , &a[ i ] );
	}
	ans = a[ 0 ];
	for( i = 0; i < n * m - 1; i ++ )
	{
		int x = i , y;
		for( j = i + 1; j < n * m; j ++ )
		{
			if( a[ j ] < a[ x ] )
			{
				x = j;
			}
		}
		/*
		printf( "now check a:" );
		for( int b = 0; b < n * m; b ++ )
		{
			printf( "%d " , a[ b ] );
		}
		printf( "\n" );
		//*/
		y = a[ i ] , a[ i ] = a[ x ] , a[ x ] = y;
	}
	for( i = 0; i < n * m; i ++ )
	{
		if( a[ i ] == ans )
		{
			ans = n * m - i;
			break;
		}
	}
	//*
	printf( "now check a:" );
	for( int b = 0; b < n * m; b ++ )
	{
		printf( "%d " , a[ b ] );
	}
	printf( "\nnow check ans: %d\n" , ans );	
	//*/
	c = ( ans - 1 ) / n + 1;
	if( c % 2 == 0 )
	{
		if( n % 2 == 0 )
		{
			printf( "%d %d" , c , n - ( ans % n ) );
		}
		else
		{
			printf( "%d %d" , c , n - ( ans % n ) + 1 );
		}
	}
	else 
	{
		printf( "%d %d" , c , ans % n );
		if( n % 2 == 0 )
		{
			printf( "%d %d" , c , ans % n );
		}
		else
		{
			printf( "%d %d" , c , ans % n + 1 );
		}
	}
	return 0;
}
