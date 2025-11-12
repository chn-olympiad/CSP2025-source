#include<bits/stdc++.h>

using namespace std;

int n;

struct node
{
	int a, b, c;
	int mi, ma, x;
} s[100001];
long long int x, y, z, t, ans;
bool A, B;

void dfs( long long int sum, int i, int a, int b, int c )
{
	if( i == n )
	{
		ans = max( ans, sum );
		return ;
	}
	
	if( a + 1 <= n / 2 ) dfs( sum + s[i+1].a, i + 1, a + 1, b, c );
	if( b + 1 <= n / 2 ) dfs( sum + s[i+1].b, i + 1, a, b + 1, c );
	if( c + 1 <= n / 2 ) dfs( sum + s[i+1].c, i + 1, a, b, c + 1 );
}

bool cmp( node a, node b )
{
	return a.a > b.a;
}

bool cmp( node a, node b )
{
	return ( a.ma - a.x ) > ( b.ma - b.x );
}

int main()
{
	freopen( "club.in", "r", stdin );
	freopen( "club.out", "w", stdin );
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	
	while( t-- )
	{
		ans = 0;
		cin >> n;
		
		for( int i = 1; i <= n; i++ )
		{
			cin >> s[i].a >> s[i].b >> s[i].c;
			s[i].ma = max( max( s[i].a, s[i].b ), s[i].c );
			s[i].mi = min( s[i].a, min( s[i].b, s[i].c ) );
			
			if( s[i].c < s[i].ma && s[i].c > s[i].mi )
			{
				s[i].x = s[i].c;
			}
			if( s[i].b < s[i].ma && s[i].b > s[i].mi )
			{
				s[i].x = s[i].b;
			}
			if( s[i].a < s[i].ma && s[i].a > s[i].mi )
			{
				s[i].x = s[i].a;
			}
			
			if( s[i].b != 0 || s[i].c != 0 )
			{
				A = true;
			}
			if( s[i].c != 0 )
			{
				B = true;
			}
		}
		
		sort( s + 1, s + 1 + n, cmp );
		
		if( n <= 10 )
		{
			dfs( 0, 0, 0, 0, 0 );
			cout << ans << endl;
			continue;
		}
		else if( A == false )
		{
			for( int i = 1; i <= n / 2; i++ )
			{
				ans += s[i].a;
			}
			
			cout << ans << endl;
			continue;
		}
		else if( B == false )
		{
			sort( s + 1, s + 1 + n, cmp );
			
			for( int i = 1; i <= n; i++ )
			{
				if( x + 1 <= n / 2 )
				{
					ans += s[i].ma;
					x++;
				}
				else
				{
					ans += s[i].x;
				}
			}
			
			cout << ans << endl;
			continue;
		}
		else
		{
			sort( s + 1, s + 1 + n, cmp );
			
			for( int i = 1; i <= n; i++ )
			{
				if( x + 1 <= n / 2 )
				{
					ans += s[i].ma;
					x++;
				}
				else
				{
					ans += s[i].x;
				}
			}
			
			cout << ans << endl;
			continue;
		}
	}
}
