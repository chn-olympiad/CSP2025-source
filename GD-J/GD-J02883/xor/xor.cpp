#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 5e5 + 10;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while('0' > ch || ch > '9'){ if(ch == '-'){ w = -1;} ch = getchar();}
	while('0' <= ch && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
	return s * w;
}
int n, k;
int a[N], s;
map<int, int> mp;
struct segm
{
	int l, r;
}p[N];
int tot = 0;
bool cmp(segm a, segm b)
{
	if(a.l == b.l) return a.r > b.r;
	return a.l > b.l;
}
int dp[N];
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	mp[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		s ^= a[i];
		if(mp.count(s ^ k)) p[++tot] = {mp[s ^ k] + 1, i};
		else if(a[i] == k) p[++tot] = {i, i};
		mp[s] = i;
	}
	sort(p + 1, p + tot + 1, cmp);
//	for(int i = 1; i <= tot; i++) printf("[%d, %d]\n", p[i].l, p[i].r);
	int ans = 0;
	for(int i = 1; i <= tot; i++)
	{
		int l = 1, r = i - 1, idx = 0;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if(p[mid].l > p[i].r) idx = mid, l = mid + 1;
			else r = mid - 1;
		}
		dp[i] = dp[idx] + 1;
		dp[i] = max(dp[i], dp[i - 1]);
		ans = max(ans, dp[i]);
//		cout << i << "    " << dp[i] << " " << idx << endl;
	}
	printf("%d\n", ans);
	return 0;
}
/*
4 2
2 1 0 3
6 0
1 2 3 7 6 1
*/
