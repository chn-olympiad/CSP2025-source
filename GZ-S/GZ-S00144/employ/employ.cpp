//GZ-S00144 幸进尧 贵阳市云城中学
#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 1 << 20;
char buff[SIZE], *ptr1, *ptr2;

#define gc() (ptr1 == ptr2 && (ptr2 = (ptr1 = buff) + fread(buff, 1, SIZE, stdin), ptr1 == ptr2) ? EOF : *ptr1++)
#define dg(c) (c >= '0' && c <= '9')
#define sp(c) (c <= 32 || c == 127)

int readI()
{
	int x = 0, c = gc();
	while (!dg(c)) c = gc();
	while (dg(c)) x = x * 10 + (c & 15), c = gc();
	return x;
}

string readS()
{
	string s; char c = gc();
	while (sp(c)) c = gc();
	while (!sp(c)) s.push_back(c), c = gc();
	return s;
}

#undef gc
#undef dg
#undef sp

constexpr int N = 505, MOD = 998244353;

int n, m;
string str;
int val[N];

namespace subN10
{
	int p[N];
	
	void solve()
	{
		for (int i = 1; i <= n; i ++) p[i] = i;
		
		int res = 0;
		do
		{
			int c = 0;
			for (int i = 1; i <= n; i ++)
				if (str[i - 1] == '0' || c >= val[p[i]])
					++c;
			res += n - c >= m;
		}
		while(next_permutation(p + 1, p + n + 1));
		printf("%d\n", res);
	}
}

namespace subA
{
	void solve()
	{
		int res = 1;
		for (int i = 1; i <= n; i ++)
			res = 1ll * res * i % MOD;
		printf("%d\n", res);
	}
}

namespace subM1
{
	void solve()
	{
		int tot = 1;
		for (int i = 1; i <= n; i ++)
			tot = 1ll * tot * i % MOD;
		
		int cnt0 = 0, cnt1 = 0, res = 1;
		for (int i = n, j = n; i; i --)
			if (str[i - 1] == '0') ++cnt0;
			else
			{
				while (j && val[j - 1] >= i - 1) --j;
				res = 1ll * res * (n - j + 1 - cnt1) % MOD;
				++cnt1;
			}
		while (cnt0) res = 1ll * res * cnt0 % MOD, --cnt0;
		res = (tot + MOD - res) % MOD;
		printf("%d\n", res); 
	}
}

namespace subB
{
	int one[N], pre[N];
	
	void solve()
	{
		int cnt = 0, cnt0 = 0;
		for (int i = 1; i <= n; i ++)
			if (str[i - 1] == '1')
				one[++cnt] = i, pre[cnt] = cnt0;
			else ++cnt0;
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	n = readI(), m = readI(), str = readS();
	for (int i = 1; i <= n; i ++) val[i] = readI();
	sort(val + 1, val + n + 1);
	
	int flagA = 1;
	for (char c : str) flagA &= c == '1';
	if (n <= 10) subN10::solve();
	else if (flagA) subA::solve();
	else if (m == n) puts("0");
	else if (m == 1) subM1::solve();
	else subB::solve();
	
	return 0;
}
