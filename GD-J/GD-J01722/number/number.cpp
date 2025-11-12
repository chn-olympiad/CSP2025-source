#include<bits/stdc++.h>

using namespace std;

string s;
int a[11];
int len;

int main()
{
	freopen( "number.in", "r", stdin );
	freopen( "number.out", "w", stdout );
	
	cin >> s;
	
	len = s.length();
	
	for( int i = 0; i < len; i++ )
	{
		if( s[i] > '9' || s[i] < '0' )
		{
			continue;
		}
		
		a[s[i]-'0']++;
	}
	
	for( int i = 9; i >= 0; i-- )
	{
		for( int j = 1; j <= a[i]; j++ )
		{
			cout << i;
		}
	}
	
	return 0;
}
