# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 5e5 + 10;
int n, k;
int a[N];
int sum[N]; 
int l, r;
int ans;
map < int, vector < int > > cnt;
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	cnt[0].push_back(0);
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
		cnt[sum[i]].push_back(i);
	}
	for (int i = 1; i <= n; i ++)
	{
		int x = k ^ sum[i];
		if (!cnt.count(x)) continue;
		int pos = upper_bound(cnt[x].begin(), cnt[x].end(), i) - cnt[x].begin();
		pos --;
		if (cnt[x][pos] == i) pos --;
		if (pos < 0) continue;
		int X = cnt[x][pos] + 1, y = i;
		if (X > l && X > r)
		{
			ans ++;
			l = X;
			r = y;
		}
	}
	cout << ans;
	return 0;
}
