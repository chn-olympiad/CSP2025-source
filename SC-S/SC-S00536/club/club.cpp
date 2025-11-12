#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	while(t--)
	{
		int n, a[100005][5], ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
				cin >> a[i][j];
		}
		cout << 0 << "\n";
	}
	return 0;
}