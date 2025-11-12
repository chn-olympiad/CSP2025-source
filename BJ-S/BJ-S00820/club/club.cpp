#include "bits/stdc++.h"
#define ll long long
using namespace std;
int T, n, a, b, c, ta, tb, tc, cnt[4], ans;
struct X
{
	int id, ch, mx1, mx2, val;
	bool operator <(X z)
	{
		return ch > z.ch;
	}
}f[100005];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		ans = cnt[1] = cnt[2] = cnt[3] = 0;
		for(int i = 1;i <= n;i++)
		{
			cin >> a >> b >> c;
			ta = 1, tb = 2, tc = 3;
			if(a > b)	swap(a, b),swap(ta, tb);
			if(b > c)	swap(b, c),swap(tb, tc);
			if(a > b)	swap(a, b),swap(ta, tb);
			f[i].id = i, f[i].ch = c - b, f[i].mx1 = tc, f[i].mx2 = tb, f[i].val = c;
		}
		sort(f + 1, f + n + 1);
		for(int i = 1;i <= n;i++)
		{
			if(cnt[f[i].mx1] == n / 2)
			{
				cnt[f[i].mx2]++;
				ans += f[i].val - f[i].ch;
			}else
			{
				cnt[f[i].mx1]++;
				ans += f[i].val;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
