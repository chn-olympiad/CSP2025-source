#include<bits/stdc++.h>
using namespace std;
int line,cross,point[114514],fx = 1,fy = 1,fp;
int main()
{
	freopen( "seat.in","r",stdin );
    freopen( "seat.out","w",stdout );
	scanf( "%d%d",&line,&cross );
	for( int i = 1 ; i <= line * cross ; i ++ )
		scanf( "%d",&point[i] );
	fp = point[1];
	sort( point + 1,point + line * cross + 1 );
	for( int i = line * cross ; i >= 1 ; i -- )
	{	
		if( fp == point[i] )
		{
			cout << fx << ' ' << fy;
			break;
		}
		if( fx % 2 )
		{
			if( fy == line ) fx ++;
			else fy ++;
		}
		else
		{
			if( fy == 1 ) fx ++;
			else fy --;
		}
	}
	return 0;
}