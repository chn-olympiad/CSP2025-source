#include<bits/stdc++.h>
using namespace std;
int want,len,check[1919810],ans,f[1919810],f1;
int main()
{
	freopen( "xor.in","r",stdin );
    freopen( "xor.out","w",stdout );
	scanf( "%d%d",&len,&want );
	for( int i = 1 ; i <= len ; i ++ )
	{
		scanf( "%d",&check[i] );
		if( check[i] == want )
		{
			f[i] ++;
			ans ++;
		}
	}
	for( int i = 2 ; i <= len ; i ++ )
		for( int j = 1 ; j <= len - i + 1 ; j ++ )
		{
			if( f[j] ) j ++;
			f1 = check[j];
			for( int k = j + 1 ; k < j + i ; k ++ )
			{
				if( f[k] ) 
				{
					f1 = -1;
					j --;
					j += i;
					break;
				}
				f1 ^= check[k];
			}
			if( f1 == want )
			{
				ans ++;
				for( int k = j ; k <= j + i ; k ++ )
					f[k] ++;
			} 
		}
	cout << ans;
	return 0;
}