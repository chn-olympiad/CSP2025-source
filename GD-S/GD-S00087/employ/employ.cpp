#include <iostream>
#include <algorithm>

using namespace std ;

const int N = 5e2 + 5, MOD = 998244353 ;

int n, m, total, a[N] ;

int sl ;
string s ;
int res[N] ;
bool vis[N] ;
void dfs(int cur, int already, int sum)
{
	if (cur == n + 1)
	{
		total += (sum >= m) ;
		total %= MOD ;
		return ;
	}
	
	for (int i = 1 ; i <= n ; i ++ )
		if (!vis[i])
		{
			vis[i] = true ;
			res[cur] = i ;
			if (s[cur] == '0' && a[i] > already)
				dfs(cur + 1, already + 1, sum) ;
			else dfs(cur + 1, already, sum + (s[cur] == '1')) ;
			vis[i] = false ;
		}
}

int main()
{
	freopen("employ.in", "r", stdin) ;
	freopen("employ.out", "w", stdout) ;
	ios::sync_with_stdio(false) ;
	
	cin >> n >> m >> s ;
	sl = s.size(), s = "*" + s ;
	for (int i = 1 ; i <= n ; i ++ )
		cin >> a[i] ;
	
	bool flag = true ;
	for (int i = 1, Len = s.size() ; i <= sl ; i ++ )
		if (s[i] != '0')
		{
			flag = false ;
			break ;
		}
	dfs(1, 0, 0) ;
	cout << total << '\n' ;
	
	return 0 ;
}
