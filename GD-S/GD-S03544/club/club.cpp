#include <bits/stdc++.h>
using namespace std;

namespace IO
{
	char ch;
	inline void read() {}
	template<class T1, class... T2>
	inline void read(T1& num1, T2&... num2)
	{
		num1 = 0; ch = getchar();
		for (; !isdigit(ch); ch = getchar());
		for (; isdigit(ch); ch = getchar())
			num1 = num1 * 10 + (ch ^ '0');
		read(num2...);
	}
}
using IO::read;

const int N = 1e5 + 5;

int mns[N], tot;
int n, lim, ans;
int a[N][3], b[N];
int cnt[3];

void process(int col)
{
	tot = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (b[i] == col)
		{
			mns[++tot] = max(a[i][(col + 1) % 3], a[i][(col + 2) % 3]) - a[i][col];
		}
	}
	sort(mns + 1, mns + 1 + tot, greater<int>{});
	tot -= lim;
	for (int i = 1; i <= tot; ++i)
	{
		ans += mns[i];
	}
}

void solve()
{
	cnt[0] = cnt[1] = cnt[2] = 0;
	read(n); ans = 0; lim = n / 2;
	for (int i = 1; i <= n; ++i)
	{
		read(a[i][0], a[i][1], a[i][2]);
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
			b[i] = 0;
		if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2])
			b[i] = 1;
		if (a[i][2] >= a[i][0] && a[i][2] >= a[i][1])
			b[i] = 2;
		++cnt[b[i]];
		ans += a[i][b[i]];
	}
	if (cnt[0] > lim) process(0);
	if (cnt[1] > lim) process(1);
	if (cnt[2] > lim) process(2);
	printf("%d\n", ans);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	read(T);
	while (T--) solve();
	return 0;
}
