#include <bits/stdc++.h>
#define MAXN 5010
#define MOD 998244353
using namespace std;
map<long long, long long> sum[2];
int n;
long long a[MAXN];
long long ans = 0;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i & 1].clear();
		for (auto it = sum[(i - 1) & 1].begin(); it != sum[(i - 1) & 1].end(); it++)
		{
			sum[i & 1][a[i] + it->first] += it->second;
			sum[i & 1][it->first] += it->second;
		}
		sum[i & 1][a[i]]++;
		if (i < 3)
		{
			continue;
		}
		auto ptr = sum[i & 1].lower_bound(2 * a[i]); // 第一个小于等于2倍当前值的元素位置
		if (ptr == sum[i & 1].end())
		{
			continue;
		}
		if (ptr->first > a[i] * 2)
		{
			ans++;
		}
		ptr++;
		if (ptr == sum[i & 1].end())
		{
			continue;
		}
		for (auto it = ptr; it != sum[i & 1].end(); it++)
		{
			ans += it->second - (it->first == i);
			ans %= MOD;
		}
	}
	cout << ans % MOD;
}