#include <bits/stdc++.h>
using namespace std;
int n, m; 
int a[5005]; 
int dfs(int step, int nums, int maxn)
{
	if(step == n + 1)
	{
		if(nums > 2 * maxn) return 1; 
		else return 0; 
	}
	return dfs(step + 1, nums, maxn) + dfs(step + 1, nums + a[step], max(maxn, a[step])); 
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n; 
	for(int i = 1; i <= n; i++)
		cin >> a[i], m += a[i]; 
	sort(a + 1, a + n + 1); 
	cout << dfs(1, 0, 0); 
	return 0; 
}

