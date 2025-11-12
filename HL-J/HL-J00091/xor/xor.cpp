#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, sum = 0;
	cin >> n >> k;
	int a[n];
	for(long long i = 0; i < n; i++) cin >> a[i];
	for(long long i = 0; i < n; i ++)
	{
		if(a[i] == k)
		{
			sum ++;
			continue;
		}
		int cnt = 0, h = a[i];
		if(a[i + 1] != k)
		{
			for(long long j = i + 1; j < n; j ++)
			{
				h ^= a[j];
				cnt ++;
				if(h == k)
				{
					sum ++;
					break;
				}
			}
		}
		i += cnt;
	}
	cout << sum;
	return 0;
}
