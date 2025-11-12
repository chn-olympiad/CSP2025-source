#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cmath>
#include<stack>
#include<string>
#include<cstring>
using namespace std;
int n,k,ans = 0;
int a[200010],s;
int t;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf ( "%d",&n );
	scanf ( "%d",&k );
	for ( int i = 1;i <= n;i++ )
	{
		scanf ( "%d",&a[i] );
	}
	for ( int i = 1;i <= n - 1;i++ )
	{
		for ( int j = i + 1;j <= n;j++ )
		{
			for ( int kk = i;kk <= j;kk++ )
			{
				if ( a[kk] == a[kk + 1] )
				{
					a[kk + 1] = 0;
				}
			    else if ( a[kk] != a[kk + 1] )
			    {
					    a[kk + 1] = 1;
				}
				if ( kk + 1 > j )
				{
					t = a[kk];
				    break;
				}
				if ( a[kk + 1] == k )
				{
					ans++;
				    i += j - i;
				    break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

