#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int n,m,ans,t = 0;
int a[110];
bool cmp( int y,int z )
{
	return y > z;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf ( "%d",&n );
	scanf ( "%d",&m );
	for ( int i = 1;i <= n * m;i++ )
	{
		cin >> a[i];
	}
	ans = a[1];
	sort ( a + 1,a + n * m + 1,cmp );
	for ( int i = 1;i <= m;i++ )
	{
		if ( i % 2 == 0 )
		{
			for ( int j = n;j >= 1;j-- )
			{
				t++;
				if ( ans == a[t] )
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else if ( i % 2 == 1 )
		{
			for ( int j = 1;j <= n;j++ )
			{
				t++;
				if ( ans == a[t] )
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
 * a a a
 * a a a
*/

