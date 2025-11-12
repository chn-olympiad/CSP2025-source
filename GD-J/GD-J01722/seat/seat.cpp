#include<bits/stdc++.h>

using namespace std;

int a[101][101];
int b[10001];
int n, m, q, p;
int u, v;

int main()
{
	freopen( "seat.in", "r", stdin );
	freopen( "seat.out", "w", stdout );
	
	cin >> n >> m;
	p = n * m;
	
	if( p == 0 )
	{
		return 0;
	}
	
	for( int i = 1; i <= p; i++ )
	{
		cin >> b[i];
	}
	
	q = b[1];
	
	sort( b + 1, b + 1 + p );
	
	for( int i = 1; i <= p; i++ )
	{
		if( b[i] == q )
		{
			q = i;
			break;
		}
	}
	
	q = p - q + 1;
	u = 1;
	v = 0;
	
	for( int i = 1; i <= q; i++ )
	{
		
		if( u % 2 == 1 )
		{
			v++;
		}
		else
		{
			v--;
		}
		
		if( v == m + 1 )
		{
			v--;
			u++;
		}
		
		if( v == 0 )
		{
			v++;
			u++;
		}
	}
	
	cout << u << " " << v << endl;
	
	return 0;
}
