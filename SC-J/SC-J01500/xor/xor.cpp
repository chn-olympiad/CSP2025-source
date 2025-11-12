#include <bits/stdc++.h>
using namespace std;
int a[500010], cnt;
map<pair<int, int>, bool> mp;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, xxor1, xxor2; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int l1 = 1; l1 <= n; l1++)
	{
		for (int r1 = l1; r1 <= n; r1++)
		{
			for (int l2 = l1; l2 <= n; l2++)
			{
				for (int r2 = l2; r2 <= n; r2++)
				{
					if (l2 < r1 || l1 > r2) continue;
					for (int i = l1; i <= r1; i++) xxor1 ^= a[i];
					if (l1 == r1) xxor1 = a[l1];
					if (l2 == r2) xxor2 = a[l2];
					for (int i = l2; i <= r2; i++) xxor2 ^= a[i];
					if (xxor1 == k && xxor2 == k) cnt ++;
					xxor1 = 0; xxor2 = 0; mp[{l1, r1}] = true; mp[{l2, r2}] = true;
				}
			}
		}
	}
	for (int l = 1; l <= n; l++)
	{
		for (int r = 1; r <= n; r++)
		{
			if (mp[{l, r}]) continue;
			for (int i = l; i <= r; i++) xxor1 ^= a[i];
			if (xxor1 == k) cnt ++;
			xxor1 = 0;
		}
	}
	cout << cnt;
}