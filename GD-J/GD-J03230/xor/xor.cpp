#include <bits/stdc++.h>
using namespace std;

int arr[500000];
vector<int> ans(1);

void dfs(vector<int> vec, int pos, int n, int k)
{
	if (!vec.empty())
	{
		int t = vec[0];
		
		for (int i = 1; i < vec.size(); ++i)
		{
			t ^= vec[i];
		}
		
		if (t == k)
		{
			++ans[ans.size() - 1];
			
			vec.clear();
		}
	}
	
	if (pos + 1 >= n)
	{
		ans.push_back(0);
	}
	
	for (int i = pos + 1; i < n; ++i)
	{
		vec.push_back(arr[i]);
		
		dfs(vec, i, n, k);
		
		vec.pop_back();
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k, maxx = 0;
	bool A = true, B = true;
	
	cin >> n >> k;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		
		if (arr[i] != 1) A = false;
		if (arr[i] > 1) B = false;
	}
	
	if (A)
	{
		cout << n / 2;
	}
	
	else if (B)
	{
		int w = 0;
		
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] == k)
			{
				++w;
			}
			
			else if (i < n - 1 && arr[i] != k && arr[i + 1] != k && k == 0)
			{
				++w;
				++i;
			}
		}
		
		cout << w;
	}
	
	else
	{
		for (int i = 0; i < n; ++i)
		{
			vector<int> vec;
			
			dfs(vec, -1, n, k);
		}
		
		for (int e : ans)
		{
			maxx = max(maxx, e);
		}
		
		cout << maxx;
	}
	
	return 0;
}
