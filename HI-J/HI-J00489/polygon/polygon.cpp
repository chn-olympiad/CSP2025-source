#include <bits/stdc++.h>
using namespace std;

int cnm(int n , int m)
{
	long long ans1 = 1 , ans2 = 1;
	for (int i = m - n ; i <= m ; ++i)
	{
		ans1 *= i;
	}
	for (int i = 1 ; i <= n ; ++i)
	{
		ans2 *= i;
	}
	return ans1 / ans2;
}

int sigma(int i , int m)
{
	long long ans = 0;
	for (int j = i ; j <= m ; ++j)
	{
		ans += j;
	}
	return ans;
}

int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	long long n , l;
	int a[100000005] = {};
	for (int i = 1 ; i <= n ; ++i)
	{
		cin >> l;
		a[i] = l;
	}
	
	int ans = 0;
	for (int i = 3 ; i <= n ; ++i)
	{
		ans += cnm(i,n);
	}
	cout << ans;
	return 0;
}
