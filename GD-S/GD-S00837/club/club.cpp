#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL maxn = 1e5 + 5;
LL n, a[maxn][4], T, ans, sum[4], idx;
struct node
{
	LL p, num, pos;
}p[maxn * 3];
bool vis[maxn];
bool cmp(node a, node b)
{
	return a.num > b.num;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%lld", &T);
	while(T--)
	{
		memset(vis, 0, sizeof vis);
		memset(sum, 0, sizeof sum);
		ans = idx = 0;
		
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			p[++idx] = {i, a[i][1], 1};
			p[++idx] = {i, a[i][2], 2};
			p[++idx] = {i, a[i][3], 3};
		}
		sort(p + 1, p + 1 + idx, cmp);
		for(int i = 1; i <= idx; i++)
		{
			if(vis[p[i].p]) continue;
			if(sum[p[i].pos] == n / 2) continue;
			sum[p[i].pos]++;
			ans += p[i].num;
			vis[p[i].p] = 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
 } 
