#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int a[MAXN];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = a[i], cur = i;
		if (temp == k)
		{
			ans++;
			continue;
		}
		for (int j = i + 1; j <= n; j++, i++)
		{
			if (temp == k) break;
			temp = temp xor a[j];
		}
		if (temp == k)
		{
			ans++;
		}
		else
		{
			i = cur;
		}
	}
	cout << ans << "\n";
	return 0;
}
