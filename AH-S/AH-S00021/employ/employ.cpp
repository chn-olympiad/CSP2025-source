#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, c[501];
char s[501];
int Sub1()
{
	int p = 1;
	for (int i = 1; i <= n; ++i)
		p = 1LL * p * i % MOD;
	printf("%d", p);
	return 0;
}
int Sub2()
{
	for (int i = 1; i <= n; ++i)
		if (s[i] == '0') { puts("0"); break;}
int p = 1;
	for (int i = 1; i <= n; ++i)
		p = 1LL * p * i % MOD;
	printf("%d", p);
	return 0;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	bool flg = 1;
	for (int i = 0; i < n; ++i) if (s[i] != '1') { flg = false; break; }
	for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
	if ((m == n) || flg)
		return Sub1();
	return Sub2();
}
