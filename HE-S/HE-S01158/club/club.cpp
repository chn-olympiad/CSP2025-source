#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5+10;
int T;
struct node
{
	int a1,a2,a3;
}a[N];
int vis[N];
ll ans = 0;
int n;
void dfs(int x,int zu1,int zu2,int zu3)
{
	if (x == n+1)
	{
		return ;
	}
	if (zu1 <= n/2)
	{
		vis[x] = 1;
		ans += a[x].a1;
		dfs(x+1,zu1+1,zu2,zu3);
		vis[x] = 0;
		ans -= a[x].a1;
	}
	if (zu2 <= n/2)
	{
		vis[x] = 1;
		ans += a[x].a2;
		dfs(x+1,zu1,zu2+1,zu3);
		vis[x] = 0;
		ans -= a[x].a2;
	}
	if (zu3 <= n/2)
	{
		vis[x] = 1;
		ans += a[x].a3;
		dfs(x+1,zu1,zu2,zu3+1);
		vis[x] = 0;
		ans -= a[x].a3;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		memset(a,0,sizeof(a));
		ans = 0;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		}
		dfs(1,0,0,0);
		cout << ans << "\n";
	}
	return 0;
}
