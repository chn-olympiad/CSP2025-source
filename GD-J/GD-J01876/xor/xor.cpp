#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, a[500005], sxr[500005], top;

struct stu
{
	int l, r;
}b[500005];

bool cmp(stu x, stu y)
{
	return x.r < y.r;
}

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sxr[i] = sxr[i - 1] ^ a[i];
	}
	
	for (int l = 1; l <= n; ++l)
	{
		for (int r = l; r <= n; ++r)
		{
			if ((sxr[r] ^ sxr[l - 1]) == k)
			{
				b[++top] = {l, r};
			}
		}
	}
	
	sort(b + 1, b + top + 1, cmp);
	
	int ans = 1, rn = b[1].r;
	for (int i = 1; i <= top; ++i)
	{
		if (b[i].l <= rn)continue;
		++ans;
		rn = b[i].r;
	}
	cout << ans;
	return 0;
}
