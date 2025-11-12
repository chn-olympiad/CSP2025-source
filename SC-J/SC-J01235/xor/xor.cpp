#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define x first
#define y second
#define V vector
using namespace std;

const int maxn = 5e4;
const int maxa = 1<<20;

int n, k;
int lst[maxa + 5];
int r = 0;

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(lst, 0xff, sizeof lst);
	cin >> n >> k;
	int f = 0;
	lst[0] = 0;
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		int x; cin >> x;
		f ^= x;
		if(r <= lst[f^k])
		{
			r = i,
			++ans;
		}
		lst[f] = i;
	}
	cout << ans << '\n';

	return 0;
}
/*
8:57
*/