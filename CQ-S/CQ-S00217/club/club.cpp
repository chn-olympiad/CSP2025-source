#include <bits/stdc++.h>
//#define int long long
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 1e5 + 10;
int n, a[N][4], cnt[4], sum;
pii p[4][2 * N];
int cur[4];
bool vis[N];
void change(int id)
{
	for (int i = 1; i <= cur[id]; i++) vis[i] = false;
	sort (p[id] + 1, p[id] + cur[id] + 1);
	for (int i = 1; cnt[id] > n / 2; i++)
	{
		if (vis[p[id][i].y]) continue;
		vis[p[id][i].y] = true;
		sum -= p[id][i].x;
		cnt[id]--;
	}
}

signed main()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int t;
	scanf ("%d", &t);
	while (t--)
	{
//		puts ("dfdfd");
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				scanf ("%d", &a[i][j]);
		cnt[1] = cnt[2] = cnt[3] = sum = 0;
		memset (cur, 0, sizeof cur);
		for (int i = 1; i <= n; i++)
		{
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) sum += a[i][1], cnt[1]++, p[1][++cur[1]] = {a[i][1] - a[i][2], i}, p[1][++cur[1]] = {a[i][1] - a[i][3], i};
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) sum += a[i][2], cnt[2]++, p[2][++cur[2]] = {a[i][2] - a[i][1], i}, p[2][++cur[2]] = {a[i][2] - a[i][3], i};
			else sum += a[i][3], cnt[3]++, p[3][++cur[3]] = {a[i][3] - a[i][1], i}, p[3][++cur[3]] = {a[i][3] - a[i][2], i};
		}
//		puts ("fdfdf");
		if (cnt[1] > n / 2) change (1);
		else if (cnt[2] > n / 2) change (2);
		else if (cnt[3] > n / 2) change (3);
//		puts ("dfsdfs");
		printf ("%d\n", sum);
	}
	return 0;
}

