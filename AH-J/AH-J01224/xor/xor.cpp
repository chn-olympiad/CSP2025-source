#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 5;
int a[N];
int sum[N];
int n, k;
 
int main()
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	int cnt = 0;
	int p;
	for (int i = 1;i <= n;i ++)
	{
		p = i;
		for (int j = i;j <= n;j ++)
		{
			if ((sum[j] ^ sum[i - 1]) == k)
			{
				p = j;
				cnt ++;
				break;
			}
		}
		i = p;
	}
	cout << cnt;
	return 0;
}
