#include<bits/stdc++.h>

using namespace std;

int a[10001];
int b[1001][1001];
int maxn, n, ans;

void f()
{
	b[1][1] = 1;
	b[2][1] = 1;
	b[2][2] = 1;
	
	for( int i = 3; i <= 900; i++ )
	{
		for( int j = 1; j <= i; j++ )
		{
			b[i][j] = b[i-1][j] + b[i-1][j-1];
			b[i][j] = b[i][j] % 998244353;
		}
	}
}

void dfs( int n, int m, int x, int maxx, int sum )
{
	if( m == 0 )
	{
		if( sum > 2 * maxx )
		{
			ans++;
		}
		
		return ;
	}
	if( m != 0 && x == n )
	{
		return ;
	}
	else
	{
		for( int i = x + 1; i <= n - m + 1; i++ )
		{
			dfs( n, m - 1, i, max( maxx, a[i] ), sum + a[i] );
		}
	}
}

int main()
{
	freopen( "polygon.in", "r", stdin );
	freopen( "polygon.out", "w", stdout );
	
	cin >> n;
	
	maxn = 0;
	
	for( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
		maxn = max( maxn, a[i] );
	}
	
	if( maxn == 1 )
	{
		f(); ans = 0;
		for( int i = 2; i <= n + 1; i++ )
		{
			ans += b[n+1][i];
			ans = ans % 998244353;
		}
		
		cout << ans;
	}
	else
	{
		ans = 0;
		
		for( int i = 3; i <= n; i++ )
		{
			dfs( n, i, 0, 0, 0 );
		}
		
		cout << ans << endl;
	}
}
