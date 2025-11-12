# include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("xor.in", "r", stdin);
	
	freopen("xor.out", "w", stdout);
	
	int n, k;
	
	cin >> n >> k;
	
	vector<int> a(n);
	
	vector<pair<int, int>> vis;
	
	map<int, bool> mp;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	int result = 0;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			int sum = a[i];
			
			for(int k = i + 1; k <= j; k++)
			{
				sum = sum ^ a[k]; 
			}
			
			if(sum == k)
			{
				result++;
				
				for(int x = i; x <= j; x++)
				{
					if(mp[x])
					{
						result--;
						
						break;
					}
					
					mp[x] = true;
				}
			}
		}
	}
	
	cout << result; 
	
	return 0; 
}
