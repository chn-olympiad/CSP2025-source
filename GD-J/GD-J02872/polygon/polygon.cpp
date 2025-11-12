#include <bits/stdc++.h>
using namespace std;
int mg[5005];
int n;
long long ans;
void dfs(int num,int sum,int maxx,int m)
{
	if (num == n)
	{
		if (m >= 3 &&sum > maxx * 2)
		{
			ans++;
			ans %= 998244353;
		}
		return ;	
	}
	dfs(num+1,sum+mg[num+1],max(maxx,mg[num+1]),m+1);
	dfs(num+1,sum,maxx,m);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> mg[i];
	}
	dfs(0,0,0,0);
	cout << ans;
	return 0;
} 
