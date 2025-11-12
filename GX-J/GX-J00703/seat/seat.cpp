#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int  n , m , s[102];
    cin >> n >> m ;
    for ( int i = 1 ; i <= n*m ; i ++)
    {
		cin >> s[i] ;
	}
    int d = s[1] ;
	sort(s+1,s+1+(n*m)) ;
	int z = n*m ;
	for ( int j = 1 ; j <= m ; j ++)
	{
		if ( j % 2 == 0 )
		{
			for ( int i = n ; i >= 1 ; i --)
			{
				if ( s[z] == d )
				{
					cout << j << " " << i ;
					return 0;
				}
				z--;
			}
		}
		else
		{
			
			for ( int i = 1 ; i <= n ; i ++)
			{
				if ( s[z] == d )
				{
					cout << j << " " << i ;
					return 0;
				}
				z--;
			}
		}
	}
    return 0;
}
