#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, n, a[100005][4], p, maxx;
struct node2
{
	int a, b, c;
}awa[100005];
struct node
{
	int data, num[4];
}dp[100005][4];
node qwq(int x, int i)
{
	int maxx = 0, pos = 0;
	if(dp[x][1].num[i] < p && dp[x][1].data > maxx)
	{
		maxx = dp[x][1].data;
		pos = 1;
	}
	if(dp[x][2].num[i] < p && dp[x][2].data > maxx)
	{
		maxx = dp[x][2].data;
		pos = 2;
	}
	if(dp[x][3].num[i] < p && dp[x][3].data > maxx)
	{
		maxx = dp[x][3].data;
		pos = 3;
	}
	return dp[x][pos];
}
bool cmp(node2 a, node2 b)
{
	return a.a > b.a;
}
void dfs(int now, int p1, int p2, int p3, int nowcnt)
{
	if(p1 > p || p2 > p || p3 > p) return ;
	maxx = max(maxx, nowcnt);
	if(now > n)
	{
		return ;
	}
	dfs(now + 1, p1 + 1, p2, p3, nowcnt + a[now][1]);
	dfs(now + 1, p1, p2 + 1, p3, nowcnt + a[now][2]);
	dfs(now + 1, p1, p2, p3 + 1, nowcnt + a[now][3]);
}
void solve()
{
	int flag = 1;
	cin >> n;
	p = n / 2;
	for(int i = 0; i <= n; i++)
	{
		dp[i][1].data = dp[i][1].num[1] = dp[i][1].num[2] = dp[i][1].num[3] = 0;
		dp[i][2].data = dp[i][2].num[1] = dp[i][2].num[2] = dp[i][2].num[3] = 0;
		dp[i][3].data = dp[i][3].num[1] = dp[i][3].num[2] = dp[i][3].num[3] = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		awa[i].a = a[i][1], awa[i].b = a[i][2], awa[i].c = a[i][3];
		if(a[i][2] != 0 || a[i][3] != 0)
		{
			flag = 0;
		}
		dp[i][1] = qwq(i - 1, 1);
		dp[i][1].data += a[i][1];
		dp[i][1].num[1] ++;
		
		dp[i][2] = qwq(i - 1, 2);
		dp[i][2].data += a[i][2];
		dp[i][2].num[2] ++;
		
		dp[i][3] = qwq(i - 1, 3);
		dp[i][3].data += a[i][3];
		dp[i][3].num[3] ++;
	}
	if(flag == 1)
	{
		int ans = 0;
		sort(awa + 1, awa + n + 1, cmp);
		for(int i = 1; i <= p; i ++)
		{
			ans += awa[i].a;
		}
		cout << ans << endl;
	}
	if(n <= 10)
	{
		maxx = 0;
		dfs(1, 0, 0, 0, 0);
		cout << maxx << endl;
	}
	else cout << max(dp[n][1].data, max(dp[n][2].data, dp[n][3].data)) << endl;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T; while(T --) solve();
//	solve();
}
