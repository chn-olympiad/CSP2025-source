#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int t;
int n;
int a[maxn][3], b[maxn][3], cj[maxn], belong[maxn];
int vis[3];
int del[maxn], tot;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
		tot = 0;
		memset(vis, 0, sizeof(vis));
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < 3; ++j) b[i][j] = a[i][j];
			stable_sort(b[i], b[i] + 3);
			for (int j = 0; j < 3; ++j)
			{
				if(a[i][j] == b[i][2])
				{
					vis[j]++;
					cj[i] = b[i][2] - b[i][1];
					ans += a[i][j];
					belong[i] = j;
					break;
				}
			}
		}
		int maxx = max(vis[0], max(vis[1], vis[2]));
		if(maxx <= n / 2) cout << ans << endl;
		else
		{
			int id = 0;
			for (int i = 0; i < 3; ++i) if(vis[i] == maxx) id = i;
			for (int i = 1; i <= n; ++i)
			{
				if(belong[i] != id) continue;
				del[++tot] = cj[i];
			}
			stable_sort(del + 1, del + tot + 1);
			int num = 0;
			for (int i = maxx; i > n / 2; --i) ans -= del[++num];
			cout << ans << endl;
		}
	}
	return 0;
}
