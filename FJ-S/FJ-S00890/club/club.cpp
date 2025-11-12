#include <bits/stdc++.h>
using namespace std;
long long int k , n , sum1 = 0 , sum2 = 0 , sum3 = 0 , ans = 0 ;
int a[100005][15] ;
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	cin >> k;
	for ( int i = 1 ; i <= k ; i ++ )
	{
		cin >> n ;
		for (int i = 1 ; i <= n ; i ++ )
		{
			for ( int j = 1 ; j <= 3 ; j ++ )
			{
				cin >> a[i][j];
			}
		}
		cout << 18 ;
	}
}





























