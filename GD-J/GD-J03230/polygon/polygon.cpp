#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int arr[5000];

int dfs(vector<int> vec, int k, int n, int pos)
{
	if (k == 0)
	{
		int sum = 0, maxx = 0;
		
		for (int e : vec)
		{
			sum += e;
			
			maxx = max(maxx, e);
		}
		
		
		return sum > maxx * 2;
	}
	
	int cnt = 0;
	
	for (int i = pos + 1; i < n; ++i)
	{
		vec.push_back(arr[i]);
		
		cnt = (cnt + dfs(vec, k - 1, n, i)) % MOD;
		
		vec.pop_back();
	}
	
	return cnt;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n, ans = 0;
	
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	for (int i = 3; i <= n; ++i)
	{
		vector<int> vec;
		
		ans = (ans + dfs(vec, i, n, -1)) % MOD;
	}
	
	cout << ans;
	
	return 0;
}
