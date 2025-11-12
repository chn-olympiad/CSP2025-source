#include <bits/stdc++.h>
#define subs(h, l, r) (h[(r)] - h[(l - 1)] * ex[(r) - (l - 1)])
#define ll long long
using namespace std;
const int N = 2e3 + 5, M = 2005;
const ll MOD = 1e9 + 7;
int read()
{
	char c = ' ';
	int res = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
	return res;
}

int n, m1, m2, q, l[N], k[N][M];
ll h[N], h2[N], th[M], th2[M], ex[M];
char s1[M], s2[M], t1[M], t2[M];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ex[0] = 1;
	for(int x = 1; x < M; x++) ex[x] = (ex[x - 1] * 26) % MOD;
	n = read(), q = read();
	for(int x = 1; x <= n; x++)
	{
		scanf("%s %s", s1 + 1, s2 + 1), l[x] = strlen(s1 + 1);
		/*for(int y = 2, i = 0; y <= l[x]; y++)
		{
			while(i && s[x][i + 1] != s[x][y]) i = k[x][i];
			if(s[x][i + 1] == s[x][y]) ++i;
			k[x][y] = i;
		}*/
		for(int y = 1; y <= l[x]; y++) h[x] = (h[x] * 26 + (s1[y] - 'a')) % MOD;
		for(int y = 1; y <= l[x]; y++) h2[x] = (h2[x] * 26 + (s2[y] - 'a')) % MOD;
	}
	for(int x = 1; x <= q; x++)
	{
		scanf("%s %s", t1 + 1, t2 + 1), m1 = strlen(t1 + 1), m2 = strlen(t2 + 1);
		if(m1 != m2)
		{
			printf("0\n");
			continue;
		}
		for(int y = 1; y <= m1; y++)
		{
			th[y] = (th[y - 1] * 26 + t1[y] - 'a') % MOD;
			th2[y] = (th2[y - 1] * 26 + t2[y] - 'a') % MOD;
		}
		
		int ans = 0;
		for(int y = 1; y <= m1; y++)
		{
			for(int z = 1; z <= n; z++)
			{
				int p = y - l[z] + 1;
				if(y >= l[z] && subs(th, 1, p - 1) == subs(th2, 1, p - 1) && subs(th, p, y) == h[z] && subs(th2, p, y) == h2[z] && subs(th, y + 1, m1) == subs(th2, y + 1, m2))
				{
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
