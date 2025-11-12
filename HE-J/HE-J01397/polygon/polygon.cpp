#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n, a[5005], cnt;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n - 2; i++)
	{
		int sum = 0, maxn = 0;
		for(int j = i; j <= n; j++)
		{
			sum += a[j];
			maxn = max(maxn, a[j]);
			if((j - i >= 3) && (sum > maxn * 2)) cnt++; 
		}
	}
	cout << cnt % 998244353;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
