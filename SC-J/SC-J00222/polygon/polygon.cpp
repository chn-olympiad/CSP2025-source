#include <bits/stdc++.h>
using namespace std;

const int N = 5005 , mod = 998244353;
int a [N] , cnt;
int n;
bool vis [N];

void dfs (int step , int maxn , int sum)
{
	if (step >= 3 && sum >= 2 * maxn)
	{
		cnt ++;
		return ;
	}
	if (step > n)
	{
		return ;
	}
	dfs (step + 1 , max (maxn , a [step]) , sum + a [step]);
	dfs (step + 1 , maxn , sum);
}

int main ()
{
	freopen ("polygon.in" , "r" , stdin);
	freopen ("polygon.out" , "w" , stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a [i];
	}
	dfs (1 , 0 , 0);
	cout << cnt % mod;
	return 0;
} 