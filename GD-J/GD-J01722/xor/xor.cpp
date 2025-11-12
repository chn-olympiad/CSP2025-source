#include<bits/stdc++.h>

using namespace std;

int a[500001];
int n, k;
int u[3];
int x, y;
int ans;

int main()
{
	freopen( "xor.in", "r", stdin );
	freopen( "xor.out", "w", stdout );
	
	cin >> n >> k;
	
	cout << ( 7 ^ 1 ) << endl;
	
	for( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
		u[a[i]]++;
	}
	
	x = u[0];
	y = u[1];
	
	
	if( k == 1 )
	{
		ans += y;
	}
	else if( k == 0 )
	{
		ans += int( y / 2 );
		ans += x;
	}
	
	cout << ans << endl;
}

// 2 * 1 = 0
// 1 * 1 = 1
// 2 * 0 = 0
// 1 * 0 = 0
