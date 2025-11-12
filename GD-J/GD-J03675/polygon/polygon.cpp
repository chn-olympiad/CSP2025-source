#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> v)
{
	int sum = 0, maxn = -1;
	for(auto i: v)
	{
		sum += i;
		maxn = max(maxn, i);
	}
	return (sum > 2 * maxn);
}
int get_combinations(vector<int> v, int r)
{
	int n = v.size(), indices[r], i, ans = 0;
	vector<int> temp;
	
	for(i = 0; i <= r-1; i++)
	{
		indices[i] = i;
		temp.push_back(v[indices[i]]);
	}
	
	ans += check(temp);
	temp.clear(); 
	
	while(true)
	{
		bool flag = false;
		for(i = r-1; i >= 0; i--)
		{
			if(indices[i] != i + n - r)
			{
				flag = true;
				break;
			}
		}
		if(not flag)
			break;
			
		indices[i] += 1;
		for(int j = i+1; j <= r-1; j++)
			indices[j] = indices[j-1] + 1;
			
		for(i = 0; i <= r-1; i++)
			temp.push_back(v[indices[i]]);
		ans += check(temp);
		temp.clear(); 
	}
	return ans;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n, temp, ans = 0;
	vector<int> v;
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	
	for(int r = 3; r <= n; r++)
		ans = (ans + get_combinations(v, r)) % 998244353;
	cout << ans;
	return 0;
}
