#include <iostream>
#include <cstdio>

using namespace std;
long long a[1100] , c , n , m , ans = 0 , r;
int sum = 0 ;
int main()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin >> n >> m ;
	{
	for (int i = 1 ; i <= n ; i++)
	{cin >> a[i] ;}
	
	for (int i =1 ; i <= n * m ; i++)
	{
		if(r >= n)
		for (int j =1 ; j <= n ; j++)
		{
			c++;
			r++;
		}
	}
	cout << c  << " " << r ;
	}
	return 0;
}

