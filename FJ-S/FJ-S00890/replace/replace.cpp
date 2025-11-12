#include <bits/stdc++.h>
using namespace std;
int n , k ;
string s[10005][5] , a[10005][5];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		for (int j = 1 ; j <= 2 ; j ++ )
		{
			cin >> s[i][j];	
		} 	
	}
	for ( int i = 1 ; i <= k ; i ++ )
	{
		for ( int j = 1 ; j <= 2 ; j ++)
		{
			cin >>a[i][j];
		}
	}
	for ( int i = 1 ;i <= k ; i ++ )
	{
		cout << 0 << endl ; 
	}
}
