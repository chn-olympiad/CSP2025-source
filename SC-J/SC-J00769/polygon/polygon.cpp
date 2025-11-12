#include<bits/stdc++.h>
using namespace std;
int len,check[114514],ans;
int main()
{
	freopen( "polygon.in","r",stdin );
    freopen( "polygon.out","w",stdout );
    scanf( "%d",&len );
    for( int i = 1 ; i <= len ; i ++ )
    	scanf( "%d",&check[i] );
    sort( check + 1,check + len + 1 );
    if( len == 3 )
    {
    	if( check[1] + check[2] > check[3] )
			cout << 1;
		else cout << 0;	
	}
	return 0;
}