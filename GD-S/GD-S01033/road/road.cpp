#include <bits/stdc++.h>
using namespace std;
int n , m , k;
long long res = 1e18;
int f[10001];
bool flag[21];
int find(int x)
{
	return x == f[x]? x : f[x] = find(f[x]);
}
struct node
{
	int u , v , w , id;
	bool operator<(const node &b)
	const{
		return w < b.w;
	}
}a[2100001];
int c[21];
int w[20][10001];
void solve1(long long sum , int num)
{
	for(int i = 1 ; i <= n ;i++)
	{
		f[i] = i;
	}
	for(int i = 1 ; i <= k; i++)
	{
		if(flag[i])f[i + n] = i + n;
	}
	long long ans = 0;
	int cnt = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		if(!flag[a[i].id])continue;
		if(find(a[i].u) != find(a[i].v))
		{
			ans += a[i].w;
			f[find(a[i].u)] = find(a[i].v);
			cnt++;
		}
		if(ans >= res)return;
		if(cnt >= num)break;
	}
	res = min(res , ans + sum);
}
void dfs(int step , long long sum , int num)
{
	if(step > k)
	{
		solve1(sum , num);
		return;
	}
	flag[step] = true;
	dfs(step + 1 , c[step] + sum , num + 1);
	flag[step] = false;
	dfs(step + 1 , sum , num);
}
signed main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1 ; i <= m ; i++)
	{
		scanf("%d%d%d" , &a[i].u , &a[i].v , &a[i].w);
		a[i].id = 0;
	}
	for(int i = 1 ; i <= k ; i++)
	{
		scanf("%d" , &c[i]);
		for(int j = 1 ; j <= n ; j++)
		{
			scanf("%d" , &w[i][j]);
			a[++m].u = i + n;
			a[m].v = j;
			a[m].w = w[i][j];
			a[m].id = i;
		}
	}
	flag[0] = true;
	sort(a + 1 , a + m + 1);
	dfs(1 , 0 , n);
	cout << res << endl;
	return 0;
}
