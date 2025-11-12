#include<bits/stdc++.h>
using namespace std;
int sum[100005];
int main()
{
    freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, tagi, a[100005], ans = 0;
	cin >> n >> tagi;
	for (int i = 1; i <= n; i++)
	    cin >> a[i];
	sum[1] = a[1];
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int m = 0, num = 0;
			for (int k = i; k <= j; k++)
			{
				m ^= a[k];	
				num += m;
			}
			if (num == tagi)
			    ans++;
		}
	}
	cout << ans;
	return 0;	
} 
