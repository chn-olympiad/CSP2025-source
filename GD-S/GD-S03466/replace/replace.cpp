#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, q, cnt1, cnt2, ans, nxt[N];
char t1[N], t2[N], s1[N][N], s2[N][N];
bool check(int s, int x)
{
	for(int i = s; i < s + (int)strlen(s1[x] + 1); ++i)
	{
		if(t1[i] != s1[x][i - s + 1]) return false;
	}
	return true;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i) scanf("%s%s", s1[i] + 1, s2[i] + 1);
	for(int i = 1; i <= q; ++i)
	{
		scanf("%s%s", t1 + 1, t2 + 1);
		int len = strlen(t1 + 1);
		cnt1 = cnt2 = 0;
		ans = 0;
		for(int j = 1; j <= len; ++j)
		{
			if(t1[j] == t2[j]) ++cnt1;
			else break;
		}
		for(int j = len; j >= 1; --j)
		{
			if(t1[j] == t2[j]) ++cnt2;
			else break;
		}
		for(int j = 1; j <= cnt1; ++j)
		{
			for(int k = 1; k <= n; ++k)
			{
				int l = strlen(s1[k] + 1);
				if(len - j - l > cnt2) continue;
				if(check(j, k)) ++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
