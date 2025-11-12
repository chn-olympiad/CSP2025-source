#include <bits/stdc++.h>
using namespace std;

int ori_arr[5005];
int book[5005];
int n;
int ans;

void dfs(int count, int temp_arr[5005], int last)
{
	if(count > 2)
	{
		int sum = 0;
		int maxn = 0;
		for(int i = 0; i < count; i++)
		{
			sum += temp_arr[i];
			maxn = max(maxn, temp_arr[i]);
		}
		
		if(sum > (2 * maxn))
		{
			ans ++;
			for(int i = 0; i < count; i++)
				cout << temp_arr[i] << " ";
			cout << endl;
		}
			
	}
	
	if(count > 0)
	{
		for(int i = last; i <= n; i++)
			if(book[i] != 1)
			{
				book[i] = 1;
				temp_arr[count] = ori_arr[i];
				dfs(count + 1, temp_arr, i);
				book[i] = 0;
			}
	}
	
	if(count == 0)
	{
		for(int i = 1; i <= n - 2; i++)
		{
			temp_arr[count] = ori_arr[i];
			book[i] = 1;
			dfs(count + 1, temp_arr, i);
		}
	}
	
	return ;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	int temp_arr[5005];
	
	for(int i = 1; i <= n; i ++)
		cin >> ori_arr[i];
		
	dfs(0, temp_arr, 0);
	cout << ans % 998244353;
	
	return 0;
}
