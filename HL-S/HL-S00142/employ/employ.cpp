#include <bits/stdc++.h>
using namespace std ;
#define int long long
int n , m ;
string s ;
int c[505] ;
bool visited[505] ;
int sunxu[505] ;
int ans ;
void dfs ( int p )
{
	if ( p == n )
	{
		int count = 0 ;
		for ( int i = 0 ; i < p ; i ++ )
		{
			if ( s[i] == '0' || count >= c[sunxu[i]] )
			{
				count ++ ;
			}
		}
		if ( n-count >= m )
		{
			ans ++ ;
			ans %= 998244353 ;
		}
	}
	for ( int i = 0 ; i < n ; i ++ )
	{
		if ( visited[i] == false )
		{
			visited[i] = true ;
			sunxu[p] = i ;
			dfs(p+1);
			visited[i] = false ;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s ;
	bool allone = true ;
	for ( int i = 0 ; i < s.size() ; i ++ )
	{
		if ( s[i] == '0' )
		{
			allone = false ;
			break ;
		}
	}
	if ( allone )
	{
		int jiecheng = 1 ;
		for ( int i = 1 ; i <= n ; i ++ ) 
		{
			jiecheng *= i ;
			jiecheng %= 998244353 ;
		}
		cout << jiecheng%998244353 ;
		return 0 ;
	}
	for ( int i = 0 ; i < n ; i ++ ) cin >> c[i] ;
	dfs(0);
	cout << ans ;
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}
