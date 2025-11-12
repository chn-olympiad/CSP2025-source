# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const long long INF = 1e18;
struct node { LL w; int x , y; } d[300010];
int n , t , cnt[5];
LL sum , maxn , h[300010] , a[300010][5];
bool f[300010];
void dfs(int step , LL sum , int x , int y , int z)
{
	if(sum + h[step] < maxn) return ;
	if(step > n)
	{
		maxn = max(maxn , sum);
		return ;
	}
	if(x < n / 2) dfs(step + 1 , sum + a[step][0] , x + 1 , y , z);
	if(y < n / 2) dfs(step + 1 , sum + a[step][1] , x , y + 1 , z);
	if(z < n / 2) dfs(step + 1 , sum + a[step][2] , x , y , z + 1);
	return ;
}
int maxx(int x , int y , int z)
{
	if(x > y && x > z) return 0;
	if(y > x && y > z) return 1;
	if(z > x && z > y) return 2;
	return 0;
}
void solve()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	if(n <= 10 && 0)
	{
		maxn = -1e9;
		for(int i = n ; i >= 1 ; i --) h[i] = h[i + 1] + max({a[i][0] , a[i][1] , a[i][2]});
		dfs(1 , 0 , 0 , 0 , 0);
		cout << maxn << "\n";
		return ;
	}
	for(int i = 1 ; i <= n ; i ++) cnt[maxx(a[i][0] , a[i][1] , a[i][2])] ++;
	for(int i = 1 ; i <= n ; i ++) sum += max({a[i][0] , a[i][1] , a[i][2]});
	if(cnt[0] > n / 2)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			if(maxx(a[i][0] , a[i][1] , a[i][2]) == 0)
			{
				d[i] = {min(a[i][0] - a[i][1] , a[i][0] - a[i][2]) , (a[i][0] - a[i][1] < a[i][0] - a[i][2] ? 1 : 2) , i};
			}
			else d[i] = {INF , 0 , 0};
		}
		sort(d + 1 , d + n + 1 , [](node x , node y)
		{
			return x.w < y.w;
		});
		for(int i = 1 ; i <= n ; i ++)
		{
			cnt[d[i].x] ++ , cnt[0] -- , sum -= d[i].w;
			if(cnt[0] <= n / 2) break;
			if(d[i].w >= INF) break;
		}
	}
	if(cnt[1] > n / 2)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			if(maxx(a[i][0] , a[i][1] , a[i][2]) == 1)
			{
				d[i] = {min(a[i][1] - a[i][0] , a[i][1] - a[i][2]) , (a[i][1] - a[i][0] < a[i][1] - a[i][2] ? 0 : 2) , i};
			}
			else d[i] = {INF , 0 , 0};
		}
		sort(d + 1 , d + n + 1 , [](node x , node y)
		{
			return x.w < y.w;
		});
		for(int i = 1 ; i <= n ; i ++)
		{
			cnt[d[i].x] ++ , cnt[1] -- , sum -= d[i].w;
			if(cnt[1] <= n / 2) break;
			if(d[i].w >= INF) break;
		}
	}
	if(cnt[2] > n / 2)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			if(maxx(a[i][0] , a[i][1] , a[i][2]) == 2)
			{
				d[i] = {min(a[i][2] - a[i][0] , a[i][2] - a[i][1]) , (a[i][2] - a[i][0] < a[i][2] - a[i][1] ? 0 : 1) , i};
			}
			else d[i] = {INF , 0 , 0};
		}
		sort(d + 1 , d + n + 1 , [](node x , node y)
		{
			return x.w < y.w;
		});
		for(int i = 1 ; i <= n ; i ++)
		{
			cnt[d[i].x] ++ , cnt[2] -- , sum -= d[i].w;
			if(cnt[2] <= n / 2) break;
			if(d[i].w >= INF) break;
		}
	}
	cout << sum << "\n" , sum = cnt[0] = cnt[1] = cnt[2] = 0;
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t --) solve();
	return 0;
}
