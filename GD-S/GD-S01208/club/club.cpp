#include <bits/stdc++.h> 
#define ll long long
using namespace std;

const int N = 1e6 + 5;

int t;
int n;
int a[3][N];
int node[N];

int main()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &t);
	while (t --)
	{
		int ans = 0, sum = 0;
		memset (a, 0, sizeof (a));
		scanf ("%d", &n);
		
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= 3; j ++)
			{
				scanf ("%d", &a[j][i]);
			}
		}
		int anl = n / 2;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++)
		{
			int maxn = max(a[1][i], max(a[2][i], a[3][i]));
			if (maxn == a[1][i] && cnt1 < anl)
			{
				cnt1 ++;
				node[i] = maxn;
			}
			if (maxn == a[2][i] && cnt2 < anl)
			{
				cnt2 ++;
				node[i] = maxn; 
			}
			if (maxn == a[3][i] && cnt3 < anl)
			{
				cnt3 ++;
				node[i] = maxn;
			}
			if (a[1][i] == a[2][i] && cnt2 < anl)
			{
				cnt1 --;
			}
			if (a[1][i] == a[3][i] && cnt3 < anl)
			{
				cnt1 --;
			}
			if (a[2][i] == a[3][i] && cnt3 < anl)
			{
				cnt2 --;
			}
			if (a[1][i] == a[2][i] == a[3][i] && cnt3 < anl)
			{
				cnt1 --;
				cnt2 --;
			}
			ans += node[i];
		}
		printf ("%d\n", ans);
	}
	return 0;
}

