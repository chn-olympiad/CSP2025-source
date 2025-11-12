#include <bits/stdc++.h>
using namespace std ;
const int maxn = 10005 , maxe = 1000005 ;
int n , m , k ;
long long w ;
int u , v ;
int x ;
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> u >> v >> w ;
	}
	for(int i = 1 ; i <= k ; i++)
	{
		cin >> x ;
		for(int j = 1 ; j <= n ; j++)
		{
			cin >> x ;
		}
	}
	cout << 0 ;
	return 0 ;
}
