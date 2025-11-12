#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5010,p = 998244353;
int n,a[N],flg = 1,dp[N][N];
int dfs(int x,int sum,int mx,int tot)
{
	if(x == n + 1)
	{
		return sum > mx * 2 && tot >= 3;
	}
	return dfs(x + 1,sum + a[x],a[x],tot + 1) + dfs(x + 1,sum,mx,tot);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i],flg = (i == 1 || a[i] == a[i - 1] ? flg : 0);
	sort(a + 1,a + 1 + n);
	if(n <= 20)
		cout << dfs(1,0,0,0);
	else if(flg)
	{
		int sum = 1;
		for(int i = 1 ; i <= n ; i ++)
			sum = sum * 2 % p;
		cout << ((sum - 1 - n - n * (n - 1) / 2) % p + p) % p;
	}
	else
		cout << dfs(1,0,0,0);
	return 0;
}