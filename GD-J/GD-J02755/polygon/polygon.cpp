#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int mod = 998244353;
int a[N] , Ans , maxx;
int  dfs(int x , int sum , int num , int len)
{
	if(x == len)
	{
		if(num >= 2 && sum > a[len])
			return 1;
		return 0;
	}
	int ans = 0;
	ans += dfs(x + 1 , sum + a[x] , num + 1 , len);
	ans %= mod;
	ans += dfs(x + 1 , sum , num , len);
	ans %= mod;
	return ans;
}
int n;
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" ,stdout);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%d" , &a[i]);
		maxx = max(maxx , a[i]);
	}
	if(n < 3)
	{
		puts("0");
		return 0;
	}
	if(maxx == 1)
	{
		for(int j = 3 ; j <= n ; j ++)
		{
			int x = 1;
			for(int i = n ; i >= n - j + 1 ; i --)
			{
			//	cout << j << ' '<< i << endl;
				x *= i;
				x %= mod;
			}
			for(int i = 1 ; i <= j ; i ++)
			{
				x /= i;
				x %= mod; 
			}
			//cout << j << ' '<< x << endl;
			Ans += x;
			Ans %= mod;
			//cout << Ans << endl;
		}
		printf("%d" , Ans);
		return 0;
	}
	sort(a + 1 , a + n + 1);
	for(int i = 3 ; i <= n ; i ++)
	{
		Ans += dfs(1 , 0 , 0 , i);
		Ans %= mod;
	}
	printf("%d" , Ans);
}
