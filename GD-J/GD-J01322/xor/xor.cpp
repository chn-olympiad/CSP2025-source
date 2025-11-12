#include<iostream>
using namespace std;

int n, m, a[500010], vis[500010], ans;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n - i + 1; j++)
		{
			bool flg = true;
			int sum = a[j];
			if(vis[j]) continue;
			for(int k = j + 1; k <= j + i - 1; k++)
			{
				if(vis[k])
				{
					flg = false;
					break;
				}
				sum = sum ^ a[k];
			}
			if(!flg)
			{
				continue;
			}
			if(sum == m)
			{
//				cout << i << ' ' << j << endl;
//				cout << a[j] << endl;
				for(int k = j; k <= j + i - 1; k++)
				{
					vis[k] = 1;
				}
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
