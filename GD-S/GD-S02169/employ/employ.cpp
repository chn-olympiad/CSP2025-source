#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 5e2 + 5, P = 998244353;
int n, m, ans, cnt, s[N], c[N];

void read(int &x)
{
	x = 0;char c = getchar();
	while(c < 48 || 57 < c)c = getchar();
	while(48 <= c && c <= 57)x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
}
void reads()
{
	int i = 0;char c = getchar();
	while(c < 48 || 57 < c)c = getchar();
	while(48 <= c && c <= 57)s[++i] = c ^ 48, c = getchar();
}

int p[N];
void solve18()
{
	for(int i = 1;i <= n;i++)p[i] = i;
	do
	{
		int cnts = 0, cntf = 0;
		for(int i = 1;i <= n;i++)
		{
			if(c[p[i]] <= cntf)cntf++;
			else if(s[i])cnts++;
			else cntf++;
		}
		ans = (ans + (m <= cnts)) % P;
	}
	while(next_permutation(p + 1, p + n + 1));
}
void solveN()
{
	for(int i = 1;i <= n;i++)
		if(!c[i] || !s[i])
			return void(ans = 0);
	ans = 1;for(int i = 1;i <= n;i++)ans = 1ll * ans * i % P;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	read(n), read(m), reads();
	for(int i = 1;i <= n;i++)read(c[i]), cnt += s[i];
	if(cnt < m)return puts("0") & 0;
	if(n <= 18)solve18();
	else if(n == m)solveN();
	printf("%d\n", ans);
	return 0;
}
