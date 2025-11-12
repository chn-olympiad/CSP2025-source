#include <bits/stdc++.h>
using namespace std;

int a[5005];
int n;
int ans = 0;
void dfs(int step, int sum, int maxn, int cnt)
{
	if(step > n)
	{
		if(cnt < 3) 	return;
		if(sum > 2 * maxn)	ans++;
		return;
	}
	dfs(step + 1, sum + a[step], max(maxn, a[step]), cnt + 1); 
	dfs(step + 1, sum, maxn, cnt);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if(n < 3)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)	cin >> a[i];
	dfs(1, 0, -1e9, 0);	
	cout << ans << endl;	
	return 0;
}
