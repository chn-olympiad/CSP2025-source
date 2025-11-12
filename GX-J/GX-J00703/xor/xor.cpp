#include<bits/stdc++.h>
using namespace std;
long long n , k , a[500002] , b[500002] , z ;
int f( int a , int b )
{
	if ( a == b )
	{
		return 0 ;
	}
	string a1 = "", b1 = "";
	int z = 0 , ans = 0 ;
	while(a)
	{
		if ( a % 2 == 0 )
		{
			a1 = '0' + a1 ;
		}
		else 
		{
			a1 = '1' + a1 ;
		}
		a /= 2 ;
	} 
	while(b)
	{
		if ( b % 2 == 0 )
		{
			b1 = '0' + b1 ;
		}
		else 
		{
			b1 = '1' + b1 ;
		}
		b /= 2 ;
	} 
	if ( a1.size() > b1.size())
	{
		int zz = a1.size() - b1.size();
		for ( int i = 1 ; i <= zz ; i++)
		{
			b1 = '0'+b1; 
		}
	}
	if ( a1.size() < b1.size())
	{
		int zz = a1.size() - b1.size();
		for ( int i = 1 ; i <=  zz ; i++)
		{
			a1 = '0'+a1; 
		}
	}
	int n = a1.size() ;
	for ( int i = 0 ; i < n ; i ++)
	{
		if ( a1[i] == b1[i] )
		{
			z = z*10+0;
		}
	}
	int d = 1 ;
	while(z)
	{
		if ( z%10 == 1 )
		{
			ans += d ;
		}
		d *= 2 ;
		z /=10;
	}
	return ans;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; i ++)
    {
		cin >> a[i] ;
		if ( a[i] == k )
		{
			b[i]=1;
			z++ ;
		}
	}
	for ( int i = 1 ; i < n ; i ++)
	{
		int d = a[i] ;
		if ( b[i] == 0 )
		for ( int j = i+1 ; j <= n ; j ++)
		{
			if ( b[j] == 1 )
			{
				i = j+1;
				break ;
			}
			d = f(a[j],d);
			if ( d == k )
			{
				z++;
				i = j+1 ;
				break ;
			}
		}
	}
	cout << z ;
    return 0;
}
