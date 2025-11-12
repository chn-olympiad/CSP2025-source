#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int qp(int x , int y)
{
	if(y == 0)return 1;
	int t = qp(x , y / 2);
	if(y % 2 == 0)return t * 1ll * t % p;
	return t * 1ll * t % p * x % p;
}
int ans = 0;
int sum[5001] , a[5001] , flag[5001];
int n;
int c(int x , int y)
{
	int ans = 1;
	for(int i = x ; i >= x - y ; i--)
	{
		ans = ans * i % p;
	}
	for(int i = y ; i >= 1 ; i--)
	{
		ans = ans * qp(i , p - 2) % p;
	}
	return ans;
}
void dfs(int step , int sum , int maxn , int i)
{
	if(step >= 3 && sum > 2 * maxn)ans++;
	if(step == n)
	{
		return;
	}
	i++;
	for( ; i <= n ; i++)
	{
		if(!flag[i])
		{
			flag[i] = true;
			dfs(step + 1 , sum + a[i] , max(maxn , a[i]) , i);
			flag[i] = false;
		}
	}
}
int main()
{
	freopen("polygon.in" , "r" , stdin); 
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	bool flag = true;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		if(a[i] != 1)flag = false;
	}
	if(flag)
	{
		for(int i = 3 ; i <= n ; i++)
		{
			ans = (ans + c(n , i)) % p;
		}
	}
	else if(n <= 20)dfs(0 , 0 , 0 , 0);
	cout << ans << endl;
	return 0;
}
