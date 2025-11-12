#include <bits/stdc++.h>
using namespace std ;
const int MOD = 998244353 ;
int n , m ;
string k ;
int a[514] ;
int c[514] ;
int s[514] ;
bool book[514] ;
int ans ;
void dfs(int step , int out)
{
	if (step == n + 1 && (n - out) >= m){
		ans++ ;
		return ;
	} 
	for (int i = 1 ; i <= n ; i++){
		if (book[i] == 0){
			book[i] = 1 ;
			if (out >= c[i] || a[step] == 0) dfs(step + 1 , out + 1) ;
			else dfs(step + 1 , out) ;
			book[i] = 0 ;
		}	
	}
	return ;
}
int main()
{
	freopen("employ.in" , "r" , stdin) ;
	freopen("employ.out" , "w" , stdout) ;
	cin >> n >> m ;
	cin >> k ;
	for (int i = 0 ; i < n ; i++) a[i + 1] = k[i] - '0' ;
	for (int i = 1 ; i <= n ; i++){
		cin >> c[i] ;
		if (a[i] == 1) s[i] = s[i - 1] + 1 ;
		else s[i] = s[i - 1] ;
	}
	dfs(1 , 0) ;
	cout << ans ;
	return 0 ;
}
