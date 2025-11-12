#include<bits/stdc++.h>

using namespace std;

int n, m;
int a[10001];
string s;
long long int ans = 1;
int k[10001];
int x;

int main()
{
	freopen( "employ.in", "r", stdin );
	freopen( "employ.out", "w", stdin );

	cin >> n >> m;
	
	cin >> s;
	x = n;
	
	for( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
//		cout << x;
		if( a[i] == 0 )
		{
			x--;
			cout << x << endl;
		}
	}
	
	for( int i = 0; i < s.length(); i++ )
	{
		if( s[i] == '0' && m == n )
		{
			cout << 0 << endl;
			return 0;
		}
		
		if( a[i] == 0 && m == n )
		{
			cout << 0 << endl;
			return 0;
		}
	}
	
	if( m == n )
	{
		ans = 1;
		for( int i = 1; i <= n; i++ )
		{
			ans *= i;
		}
		
		cout << ans << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	
}
