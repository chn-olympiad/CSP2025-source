#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int N = 1e5 + 5;
struct str
{
	int x,y,z;
} a[N];
int n, dp[35][35][35][35], dp1[205][205][205];
int dfs1(int i, int c1, int c2)
{
	if(dp1[i][c1][c2] != -1)
		return dp1[i][c1][c2];
	if(i == n) return 0;
	int t1 = 0, t2 = 0, t3 = 0;
	if(c1 < n / 2)
		t1 = dfs1(i + 1, c1 + 1, c2) + a[i].x;
	if(c2 < n / 2)
		t2 = dfs1(i + 1, c1, c2 + 1) + a[i].y;
	return dp1[i][c1][c2] = max(t1, t2);
}
int dfs(int i, int c1, int c2, int c3)
{
	if(dp[i][c1][c2][c3] != -1)
		return dp[i][c1][c2][c3];
	if(i == n) return 0;
	int t1 = 0, t2 = 0, t3 = 0;
	if(c1 < n / 2)
		t1 = dfs(i + 1, c1 + 1, c2, c3) + a[i].x;
	if(c2 < n / 2)
		t2 = dfs(i + 1, c1, c2 + 1, c3) + a[i].y;
	if(c3 < n / 2)
		t3 = dfs(i + 1, c1, c2, c3 + 1) + a[i].z;
	return dp[i][c1][c2][c3] = max(t1, max(t2, t3));
}
bool cmp(str l, str r)
{
	return l.x > r.x;
}
void solve()
{
	cin >> n;
	bool flag = true;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].z;
		if(a[i].z || a[i].y) flag=false;
	}
	if(n <= 30)
	{
		memset(dp, -1, sizeof(dp));
		cout << dfs(0, 0, 0, 0) << endl;
	}
	else if(flag)
	{
		int ans = 0;
		sort(a, a + n, cmp);
		for(int i = 0; i < n / 2; i++)
			ans += a[i].x;
		cout << ans << endl;
	}
	else
	{
		memset(dp1, -1, sizeof(dp1));
		cout << dfs1(0, 0, 0) << endl;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
		solve();	
	return 0;
} 
