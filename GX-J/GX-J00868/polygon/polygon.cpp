#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int n,a[5010],t = 0;
long long ans = 0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf ( "%d",&n );
	for ( int i = 1;i <= n;i++ )
	{
		scanf ( "%d",&a[i] );
	}
	sort ( a + 1,a + n + 1 );
	for ( int i = 3;i <= n;i++ )
	{
		for ( int j = 1;j <= i - 2;j++ )
		{
			for ( int k = j + 1;k <= i - 1;k++ )
			{
				if ( a[j] + a[k] > a[i] )
				{
				    ans++;
				    if ( j >= 2 )
				    {
						t = 0;
						for ( int c = 1;c <= j - 1;c++ )
						{
							t += c;
						}
						ans += t;
					}
//    				if ( a[j - 2] + a[j - 1] + a[k] > a[i] && j > 2 )
    				if ( j > 2 )
    				{
					    for ( int kk = 1;kk <= j - 1;kk++ )
					    {
							if ( a[kk] + a[kk + 1] >= a[j] )
							{
								ans += j - kk - 1;
							}
						}
					}
				}
			}
		}
	}
	cout << ans % 998244353;
	return 0;
}

