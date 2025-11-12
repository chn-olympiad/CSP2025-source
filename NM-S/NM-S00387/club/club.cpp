#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
#define ls cur << 1
#define rs cur << 1 | 1
typedef long long ll;
const int N = 1e5 + 10;
using namespace std;
int a[N][4];
int f[205][105][105];
struct node
{
	int id, val, op;
	bool operator<(const node & b) const
	{
		return val < b.val;
	}
};
int vis[N];
int main()
{
	ios ::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while(T -- )
	{
		int n; cin >> n;
		rep(i, 1, n) rep(j, 1, 3) cin >> a[i][j];
		if(n >= 100000)
		{
			memset(vis, 0, sizeof vis);
			priority_queue<node> q;
			rep(i, 1, n) rep(j, 1, 3) q.push({i, a[i][j], j});
			int s1 = 0, s2 = 0, s3 = 0; int m = n / 2;
			ll ans = 0;
			while(!q.empty())
			{
				node T = q.top(); q.pop();
				if(vis[T.id]) continue;
				if(T.op == 1 && s1 < m) ans += T.val, s1 ++, vis[T.id] = 1;
				if(T.op == 2 && s2 < m) ans += T.val, s2 ++, vis[T.id] = 1;
				if(T.op == 3 && s3 < m) ans += T.val, s3 ++, vis[T.id] = 1;
			}
			cout << ans << '\n';
//			vector<int> v;
//			rep(i, 1, n) v.push_back(a[i][1]);
//			sort(v.begin(), v.end()); reverse(v.begin(), v.end());
//			int tot = 0, ans = 0;
//			int m = n / 2;
//			for(auto x : v) 
//			{
//				if(tot >= m) break;
//				tot ++; ans += x;
//			}
//			cout << ans << '\n';
		}
		else
		{
			int m = n / 2;
			int ans = 0;
			memset(f, 0, sizeof f);
			rep(i, 1, n) rep(x, 0, min(m, i)) rep(y, 0, min(m, i))
			{
				int z = i - x - y;
				if(z < 0 || z > m) continue;
				if(i != x + y + z) continue;
				if(x > 0) f[i][x][y] = max(f[i - 1][x - 1][y] + a[i][1], f[i][x][y]);
				if(y > 0) f[i][x][y] = max(f[i - 1][x][y - 1] + a[i][2], f[i][x][y]);
				if(z > 0) f[i][x][y] = max(f[i - 1][x][y] + a[i][3], f[i][x][y]);
				ans = max(ans, f[i][x][y]);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
