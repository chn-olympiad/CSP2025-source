#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int T, n;
LL g[N][5], ans;
int s1, s2, s3;
int a[N], b[N], c[N];

bool cmp(int s, int t)
{
	LL mx1 = max(max(g[s][1], g[s][2]), g[s][3]);
	LL mx2 = max(max(g[t][1], g[t][2]), g[t][3]);
	LL c1 = 0, c2 = 0;
	bool flag = false;
	for(int i = 1;i <= 3; ++ i)
		if(g[s][i] == mx1 && !flag) flag = true;
		else c1 = max(c1, g[s][i]);
	flag = false;
	for(int i = 1;i <= 3; ++ i)
		if(g[t][i] == mx2 && !flag) flag = true;
		else c2 = max(c2, g[t][i]);
	return mx1 - c1 < mx2 - c2;
}

void modify(int x[], int sz)
{
	sort(x + 1, x + sz + 1, cmp);
	for(int i = 1;i <= sz - n / 2; ++ i)
	{
		LL mx = max(max(g[x[i]][1], g[x[i]][2]), g[x[i]][3]);
		LL c1 = 0;
		bool flag = false;
		for(int j = 1;j <= 3; ++ j)
			if(g[x[i]][j] == mx && !flag) flag = true;
			else c1 = max(c1, g[x[i]][j]);
		ans -= mx;
		ans += c1;
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &T);
	while(T --)
	{
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		s1 = s2 = s3 = ans = 0;
		scanf("%d", &n);
		for(int i = 1;i <= n; ++ i)
			for(int j = 1;j <= 3; ++ j)
				scanf("%lld", &g[i][j]);
		for(int i = 1;i <= n; ++ i)
		{
			LL mx = max(g[i][1], max(g[i][2], g[i][3]));
			ans += mx;
			if(mx == g[i][1]) a[ ++ s1] = i;
			else if(mx == g[i][2]) b[ ++ s2] = i;
			else c[ ++ s3] = i;
		}
		if(s1 > n / 2) modify(a, s1);
		else if(s2 > n / 2) modify(b, s2);
		else if(s3 > n / 2) modify(c, s3);
		printf("%lld\n", ans);
	}
	return 0;
}
