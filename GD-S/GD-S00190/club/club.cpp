#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n;
int pos , a[N][3];
int cnt[3];
vector <int> S[3];
int lmax (int id)
{
	int mx = 0;
	for (int j = 0;j < 3;j ++) if (j != pos) mx = max (mx , a[id][j]);
	return mx;
}
bool cmp (int x , int y)
{
	int wx = lmax (x) , wy = lmax (y);
	return wx - a[x][pos] > wy - a[y][pos];
}
signed main ()
{
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	int T;
	cin >> T;
	while (T --)
	{
		cin >> n;
		int m = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		S[0].clear ();
		S[1].clear ();
		S[2].clear ();
		for (int i = 1;i <= n;i ++)
		{
			int mx = 0 , p = 0;
			for (int j = 0;j < 3;j ++)
			{
				cin >> a[i][j];
				if (mx <= a[i][j]) mx = a[i][j] , p = j;
			}
			S[p].push_back (i);
		}
		int ans = 0;
		for (int j = 0;j < 3;j ++) if (S[j].size () > (n >> 1))
		{
			pos = j;
			sort (S[j].begin () , S[j].end () , cmp);
			int tp = S[j].size () - (n >> 1);
			for (int i = 0;i < tp;i ++) ans += lmax (S[j][i]) , S[j][i] = 0;
		}
		for (int j = 0;j < 3;j ++)
		{
			int tp = S[j].size ();
			for (int i = 0;i < tp;i ++)
				ans += a[S[j][i]][j];
		}
		cout << ans << '\n';
	}
	return 0;
}
