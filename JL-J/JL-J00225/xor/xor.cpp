#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int main()
{
	freopen("xor.in","r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, a[N], sum = 0;
	cin >> k >> n;
	for(int i = 1; i <= k; i++)
		cin >> a[i];
	for(int i = 1; i <= k; i++)
	{
		int d = a[i];
		for(int j = i; j <= k; j++)
		{
			if(j == i)
			{
				sum = max(sum, 1);
				continue;
			}
			d = d ^ a[j];
			if(d == n)
			{
				sum = max(j - i, sum);
			}
		}
	}
	cout << sum;
	return 0;
}
