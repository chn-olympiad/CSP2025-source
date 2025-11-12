#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
long long t;
long long n;
long long sum = 0;
long long a1[maxn],a2[maxn],a3[maxn];
long long vis[maxn];
long long maxx = 0;
bool cmp(int x,int y)
{
	return x > y;
}
void dfs(int cnt,int c1,int c2,int c3)
{
	if(cnt > n)
	{
		long long sum = 0;
		for(int i = 1;i <= n;i++)
		{
			if(vis[i] == 1)
			{
				sum += a1[i];
			}
			if(vis[i] == 2)
			{
				sum += a2[i];
			}
			if(vis[i] == 3)
			{
				sum += a3[i];
			}		
		}
		maxx = max(maxx , sum);
		return ;
	}
	if(c1 + 1 <= n / 2)
	{
		vis[cnt] = 1;
		dfs(cnt + 1 , c1 + 1 , c2 , c3);
		vis[cnt] = 0;
	}
	if(c2 + 1 <= n / 2)
	{
		vis[cnt] = 2;
		dfs(cnt + 1 , c1 , c2 + 1 , c3);
		vis[cnt] = 0;
	}
	if(c3 + 1 <= n / 2)
	{
		vis[cnt] = 3;
		dfs(cnt + 1 , c1 , c2 , c3 + 1);
		vis[cnt] = 0;
	}
	return ;
}
void solve()
{
	cin >> n;
	maxx = 0;
	memset(vis , 0 , sizeof(vis));
	bool flag1 = true,flag2 = true;
	for(int i = 1;i <= n;i++)
	{
		cin >> a1[i] >> a2[i] >> a3[i];
		if(a3[i] != 0)
		{
			flag1 = false,flag2 = false;
		}
		if(a2[i] != 0)
		{
			flag1 = false;
		}
	}
	if(flag1 && flag2)
	{
		sort(a1 + 1 , a1 + 1 + n , cmp);
		int ans = 0;
		for(int i = 1;i <= n / 2;i++)
		{
			ans += a1[i];
		}
		cout << ans << "\n";
		return ;
	}
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	dfs(1 , 0 , 0 , 0);
	cout << maxx << "\n";
	return ;
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
