#include<bits/stdc++.h>

using namespace std;

long long int a[10001][10001];
long long int q[10001][10001];
long long int d[10001];
long long int c[10001];
bool s[10001];
long long int n, m, k;
long long int u, v, w;

void dij()
{
	for( int i = 1; i <= n; i++ )
	{
		int t = -1;
		
		for( int j = 1; j <= n; j++ )
		{
			if( s[j] == false && ( t == -1 || d[t] > d[j] ) )
			{
				t = j;
			}
		}
		
		s[t] = true;
		
		for( int j = 1; j <= n; j++ )
		{
			d[j] = min( d[j], d[t] + a[t][j] );
			
			for( int p = 1; p <= k; p++ )
			{
				if( c[p] == 0 )
				{
					d[j] = min( d[j], d[t] + q[p][t] + q[p][j] );
				}
			}
		}
	}
}

int main()
{
	freopen( "road.in", "r", stdin );
	freopen( "road.out", "w", stdin );

	memset( a, 0x7f7f7f7f, sizeof a );
	
	cin >> n >> m >> k;
	
	for( int i = 1; i <= m; i++ )
	{
		cin >> u >> v >> w;
		a[u][v] = min( a[u][v], w );
		a[v][u] = min( a[v][u], w );
	}
	
	for( int i = 1; i <= k; i++ )
	{
		cin >> c[i];
		
		for( int j = 1; j <= n; j++ )
		{
			cin >> q[i][j];
		}
	}
	
	memset( d, 0x7f7f7f7f, sizeof d );
	d[1] = 0;
	dij();
	
	cout << d[n];
}
