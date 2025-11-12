#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, a[500005], sum[500005], ans;
map<ll, ll> cnt;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	ll l = 1, r = 0;
	while (r <= n && l <= n)
	{
		ll now = sum[r] ^ sum[l - 1];
		ll need = k ^ now ^ sum[l - 1];
		if (cnt[need])
		{
			if (l == 1 && r == 0)
			{
				cnt[sum[r]]++;
				r++;
				continue;
			}
			ans++;
			cnt.clear();
			l = r + 1;
		}
		cnt[sum[r]]++;
		r++;
	}
	cout << ans << endl;
	return 0;
}
/*
4 2
2 1 0 3

2
*/

/*
4 3
2 1 0 3

2
*/

/*
4 0
2 1 0 3

1
*/

/*
5 1
1 1 1 1 1
*/ 
