#include <iostream>
#include <cstring>
#include <cmath>
using namespace std ;
long long a[5005] , v[5005] ;
bool used[5005] ;
int n , cnt = 0 ;
const int N = 998244353 ;
void dfs (int start , int deep , int num)
{
	int pos = deep ;
	used[start] = true ;
	v[deep] = a[start] ;
	if (deep == num)
	{
		long long sum = 0 , maxn = -1 ;
		for (int j = 1 ; j <= deep ; j++)
		{
			sum += v[j] ;
			maxn = max(maxn , v[j]) ;
		}
		if (sum > maxn * 2)
		{
			cnt ++ ;
		}
		deep = pos ;
		return ;
	}
	for (int i = start + 1 ; i <= n ; i++)
	{
		if (!used[i])
		{
			used[i] = true ;
			deep ++ ; 
			v[deep] = a[i] ;
			dfs(i , deep , num) ;
			used[i] = false ;
			deep = pos ;
		}
	}
}
int main ()
{
	freopen("polygon.in" , "r" , stdin) ;
	freopen("polygon.out" , "w" , stdout) ;
	cin >> n ;
	memset(used , false , sizeof (used)) ;
	for (int i = 1 ; i <= n ;i++)
	{
		cin >> a[i] ;
	}
	long long ans = 0 ;
	for (int j= 1 ; j <= n; j++)
	{
		for(int i = 3 ; i <= n ; i++)
		{
			dfs(j , 1 , i) ;
		}
	}
	
	cout << cnt % N ;
	return 0 ;
}
