#include <bits/stdc++.h>
#define int long long
#define endl putchar('\n')
using namespace std;
int read()
{
	char ch = getchar();
	int sum = 0;
	for (ch;ch < '0' || ch > '9';ch = getchar());
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum;
}
void write(int x)
{
	if (x < 10) return putchar(x + '0'), void();
	write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 5e3 + 5, mod = 998244353;
int poww(int a, int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ret;
}
int n, a[N], ans, frac[N], inv[N];
void dfs(int now, int cnt, int sum, int lst)
{
	if (now > n)
	{
		if (cnt >= 3 && sum > (lst << 1)) ans++;
		return;
	}
	dfs(now + 1, cnt + 1, sum + a[now], a[now]);
	dfs(now + 1, cnt, sum, lst);
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int maxx = -1;
	n = read();
	for (int i = 1;i <= n;i++) a[i] = read();
	sort(a + 1, a + n + 1);
	if (a[n] == 1)
	{
		frac[0] = inv[0] = 1;
		for (int i = 1;i <= n;i++) frac[i] = frac[i - 1] * i % mod;
		inv[n] = poww(frac[n], mod - 2);
		for (int i = n;i > 1;i--) inv[i - 1] = inv[i] * i % mod;
		for (int i = 3;i <= n;i++) ans += frac[n] * inv[i] % mod * inv[n - i] % mod;
	}
	else dfs(1, 0, 0, 0);
	write(ans);
	return 0;
}
/*
我时常在追忆过去。
时间像软绵的细沙，
当你不在意它时，它悄然从你手中流逝；
但是当你攥紧手心，想将它挽留时，它却越流越快。
漫漫OI路，满打满算还有三年，
可我真的有三年吗？
我不知何时何故将要AFO，也不知内心的热爱还能留存多久。
我意识到了自己在OI上缺乏天赋，
尽管这事要在上了高中后才能盖棺定论，可万一鱼和熊掌兼不得呢？
人生充满了万一，万一今年没考好、万一文化课没学好……
现实太残酷了，于是，我开始追忆过去，怀念曾经那个“无所不能”的自己，
怀念着、怀念着，直到现在也变成了过去……
				——written by LYD
*/
