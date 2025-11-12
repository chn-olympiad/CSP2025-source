#include <bits/stdc++.h>
using namespace std;
string s ;
char a[10005];
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	
	cin >> s ;
	int j = 0 ;
	for ( int i = 0 ; i < s.lenght() ; i ++ )
	{
		if ( s[i] >= '1' && s[i] <= '9' )
		{
			a[++j] = s[i];	
		} 	
	} 
	sort( a + 1 , a + 1 + j );
	for ( int i = j ; i >= 1 ; i -- )
	{
		cout << a[i];
	}
	return 0; 	
}
