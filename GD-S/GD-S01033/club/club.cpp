#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a , b , c;
	
}a[100001];
int n;
int dp[201][201][201];
int work1()
{
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= i ; j++)
		{
			for(int k = 0 ; k <= i - j ; k++)
			{
				if(j > 0)dp[i][j][k] = max(dp[i][j][k] , dp[i - 1][j - 1][k] + a[i].a);
				if(k > 0)dp[i][j][k] = max(dp[i][j][k] , dp[i - 1][j][k - 1] + a[i].b);
				if(k + j < i)dp[i][j][k] = max(dp[i][j][k] , dp[i - 1][j][k] + a[i].c);
			}
		}
	}
	int ans = 0;
	for(int i = 0 ; i <= n / 2 ; i++)
	{
		for(int j = n / 2 - i ; j <= n / 2 ; j++)
		{
			if(i + j < n / 2)continue;
			ans = max(ans , dp[n][i][j]);
		}
	}
	return ans;
}
bool cmp(node a , node b)
{
	return a.a > a.b;
}
void work2()
{
	sort(a + 1 , a + n + 1);
	int ans = 0;
	for(int i = 1 ; i <= n / 2 ; i++)
	{
		ans += a[i].a;
	}
	cout << ans << endl;
}
void work3()
{
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		ans += max(a[i].a , a[i].b , a[i].c);
	}
	cout << ans << endl;
}
void work()
{
	bool flag = true;
	memset(dp , 0 , sizeof dp);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i].a >> a[i].b >> a[i].c;
		if(a[i].b != 0 || a[i].c != 0)flag = false;
	}
	if(flag)work2();
	else if(n <= 200)cout << work1() << endl;
	else work3();
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin >> t;
	while(t--)
	{
		work();
	}
	return 0;
 } 
