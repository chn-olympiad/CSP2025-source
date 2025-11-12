#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100005
using namespace std;

const int inf = 0x3f3f3f3f;

int T, n, ans, a[N][3];

vector <int> now, p[3];

int main ()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &T);
	while (T --)
	{
		for (int i = 0; i < 3; i ++)
		{
			p[i].clear ();
		}
		scanf ("%d", &n);
		for (int i = 1; i <= n; i ++)
		{
			scanf ("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		}
		ans = 0;
		for (int i = 1; i <= n; i ++)
		{
			int mx = max (max (a[i][0], a[i][1]), a[i][2]); ans += mx;
			if (a[i][0] == mx) p[0].push_back (i);
			else if (a[i][1] == mx) p[1].push_back (i);
			else p[2].push_back (i);
		}
		int id = -1;
		for (int i = 0; i < 3; i ++)
		{
			int s = p[i].size ();
			if (s > n / 2) {id = i; break;}
		}
		if (~id)
		{
			int ex = p[id].size () - n / 2;
			now.clear ();
			for (auto i : p[id])
			{
				int mn = inf;
				for (int j = 0; j < 3; j ++)
				{
					if (j != id) mn = min (mn, a[i][id] - a[i][j]);
				}
				now.push_back (mn);
			}
			sort (now.begin (), now.end ());
			for (int i = 0; i < ex; i ++)
			{
				ans -= now[i];
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
