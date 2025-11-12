#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 100005;
ll t, n, bm_max, mem[N][5], bm[5];
ll ans = -1;
int fx[4] = {0, 1, 0, -1}, fy[4] = {1, 0, -1, 0};
bool p[N][5], m[N];
void dfs(int x, int y, ll z)
{
	ans = max(ans, z);
	for (int i = 0;i < 4;i++)
	{
		bm[x]++;
		m[y] = true;
		int xx = x + fx[i];
		int yy = y + fy[i];
		bool fl = false;
		bool fl1 = false;
		bool fl2 = false;
		if (xx > 0 && xx <= 3 && yy > 0 && yy <= n && !p[yy][xx])
		{
			if (bm[xx] <= bm_max && !m[yy]){
				z += mem[xx][yy];
				fl = true;
			}
			
			p[yy][xx] = true;
			dfs(xx, yy, z);
			p[yy][xx] = false;
			if (fl) z -= mem[xx][yy];
			
		}
		bm[x]--;
		m[y] = false;
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		ans = -1;
		cin >> n;
		bm_max = n / 2;
		for (int i = 1;i <= n;i++)
		{
			cin >> mem[i][1] >> mem[i][2] >> mem[i][3];
		}
		dfs(1, 1, 0);
		cout << ans << endl;
	}
	return 0;
} 
