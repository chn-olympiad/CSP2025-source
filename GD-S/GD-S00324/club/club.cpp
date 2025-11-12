#include <bits/stdc++.h>
using namespace std;

int t, n, ans = -1e9, flag;
int a[110000][4], b[110000]; 

void dfs(int k, int v, int cnt1, int cnt2, int cnt3)
{
	if(k == n)
	{
		ans = max(ans, v);
		return;
	} 
	
	if (cnt1 + 1 <= n / 2)
		dfs(k + 1, v + a[k+1][1], cnt1 + 1, cnt2, cnt3);
	if (cnt2 + 1 <= n / 2)
		dfs(k + 1, v + a[k+1][2], cnt1, cnt2 + 1, cnt3);
	if (cnt3 + 1 <= n / 2)
		dfs(k + 1, v + a[k+1][3], cnt1, cnt2, cnt3 + 1);
		
	dfs(k + 1, v, cnt1, cnt2, cnt3);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	
	while(t--)
	{
		ans = -1e9;
		
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
				
			}
			if (a[i][2] || a[i][3])
				flag = true;
		}
		
		if (flag)
			dfs(0, 0, 0, 0, 0);
		else
		{
			for (int i = 1; i <= n; i++)
			{
				b[i] = a[i][1];
			}
			sort(b+1, b+1+n, greater<int>());
			
			ans = 0;
			for (int i = 1; i <= n/2; i++)
				ans += b[i];
		}
	
		cout << ans << endl;
	}
	
	return 0;
} 
