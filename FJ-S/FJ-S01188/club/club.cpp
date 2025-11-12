# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 1e5 + 10;
int n;
struct node{
	int x, y, z;
} a[N];
vector < int > vec[3];
int ans;
void c(int p)
{
	for (int i = vec[p].size() - 1; i > n / 2 - 1; i --)
	{
		int pos = vec[p][i];
		if (p == 0)
		{
			if (a[pos].y > a[pos].z)
			{
				vec[1].push_back(pos);
			}
			else
			{
				vec[2].push_back(pos);
			}
		}
		else if (p == 1)
		{
			if (a[pos].x > a[pos].z)
			{
				vec[0].push_back(pos);
			}
			else
			{
				vec[2].push_back(pos);
			}
		}
		else
		{
			if (a[pos].x > a[pos].y)
			{
				vec[0].push_back(pos);
			}
			else
			{
				vec[1].push_back(pos);
			}
		}
	}
	while (vec[p].size() > n / 2) vec[p].pop_back();
}
void solve()
{
	ans = 0;
	for (int i = 0; i < 3; i ++) vec[i].clear();
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i].x >> a[i].y >> a[i].z;
		if (a[i].x >= a[i].y && a[i].x >= a[i].z) vec[0].push_back(i);
		else if (a[i].y >= a[i].x && a[i].y >= a[i].z) vec[1].push_back(i);
		else vec[2].push_back(i);
	}
	sort(vec[0].begin(), vec[0].end(), [](int x, int y){
		return min(a[x].x - a[x].y, a[x].x - a[x].z) > min(a[y].x - a[y].z, a[y].x - a[y].y);
	});
	sort(vec[1].begin(), vec[1].end(), [](int x, int y){
		return min(a[x].y - a[x].x, a[x].y - a[x].z) > min(a[y].y - a[y].z, a[y].y - a[y].x);
	});
	sort(vec[2].begin(), vec[2].end(), [](int x, int y){
		return min(a[x].z - a[x].x, a[x].z - a[x].y) > min(a[y].z - a[y].x, a[y].z - a[y].y);
	});
//	for (int i = 0; i < 3; i ++)
//	{
//		for (int x : vec[i])
//		{
//			cout << x << ' ';
//		}
//		cout << '\n';
//	}
	for (int i = 0; i < 3; i ++)
	{
		if (vec[i].size() > (n / 2))
		{
			c(i);
			break;
		}
	}
	for (int i = 0; i < 3; i ++)
	{
		for (int x : vec[i])
		{
			if (i == 0) ans += a[x].x;
			if (i == 1) ans += a[x].y;
			if (i == 2) ans += a[x].z;
		}
	}
	cout << ans << '\n';
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T --) solve();
	return 0;
}
