#include<iostream>
#include<string>
int main()
{
	std::string a;
	long long aa , b[ 13 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } , i , c;
	std::cin >> a;
	aa = a.size();
	for ( i = 0; i < a.size(); i ++ )
	{
		int x = int( a[ i ] - '0' );
		if( x >= 0 && x <= 9 )
		{
			b[ x ] ++;
			//printf( "check x:%d\n" , x );
		}
	}
	//printf("check i:%d\n" , i ); 
	//printf( "check 1:%d\ncheck 2:%d\ncheck 3:%d\ncheck 4:%d\ncheck 5:%d\ncheck 6:%d\ncheck 7:%d\ncheck 8:%d\ncheck 9:%d\n" , b[ 0 ] , b[ 1 ] , b[ 2 ] , b[ 3 ] , b[ 4 ] , b[ 5 ] , b[ 6 ] , b[ 7 ] , b[ 8 ] , b[ 9 ] );
	
	for( i = 9; i >= 0; i -- )
	{
		for( int j = b[ i ]; j > 0; j -- )
		{
			printf( "%d" , i );
		}
	}
	return 0;
}
