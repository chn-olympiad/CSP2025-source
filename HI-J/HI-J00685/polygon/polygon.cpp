# include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353; 

int main()
{
	freopen("polygon.in", "r", stdin);
	
	freopen("polygon.out", "w", stdout);
	
	int n;
	
	cin >> n;
	
	vector<int> a(n);
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i]; 
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++) 
		{
			int sum = 0;
			
			int temp = -INT_MAX; 
			
			for(int k = i; k <= j; k++)
			{
				sum += a[k];
				
				if(a[k] > temp)
				{
					temp = a[k];
				}
			}
			
			// cout << "temp is " << temp << " sum is " << sum << ", When i is " << i << " j is " << j << endl; 
			
			if((j - i + 1) >= 3 && sum > (temp * 2))
			{
				ans = (ans + 1) % MOD;
			}
		}
	}
	
	cout << ans;
	
	return 0; 
}
