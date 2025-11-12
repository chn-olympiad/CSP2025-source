#include<bits/stdc++.h>
using namespace std ;
int n , a[5010] , res ;
bool vis[5010] ;
void dfs(int m , int sum , int maxx , int cnt)
{
	if(cnt == m)
	{
		
		if(sum > maxx * 2)
		{
			res ++ ;
			//cout << m << ' ' << sum << endl ;
		}
		
		return ;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		if(vis[i] == false  )
		{
			int mm = max(maxx , a[i]) ;
			vis[i] = true ;
			dfs(m , sum + a[i] , mm , cnt + 1) ;
			vis[i] = false ;
		}
	}
	return ;
}
int main()
{
	freopen("polygon.in" , "r" , stdin) ;
	freopen("polygon.out" , "w" , stdout) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i] ;
	if( n == 3)
	{
		int maxx = 0 ;
		maxx =max(max(a[1] , a[2]) , a[3]) ;
		int sum = a[1] + a[2] + a[3] ;
		if(sum > maxx * 2) cout << 1 ;
	}
	else
	{
		sort(a + 1 , a + 1 + n );
		for(int i = 3 ; i <= n ; i ++)
		{
				dfs(i , 0 , 0 , 0) ;
		}
		cout << res ;
	}
	return 0 ;
}