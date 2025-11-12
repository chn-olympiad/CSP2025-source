#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long n,m,k,a[20000],b[300005],cnt,f[10035][1205],ans;
long long dp[100005];
struct node
{
	long long x,y,w;
}eg2[1100005],eg[1100005];
bool cmp(node e,node f)
{
	return e.w < f.w;
}
long long find(long long x,long long z)
{
	if(f[x][z] == x)return x;
	return f[x][z] = find(f[x][z],z);
}
string s;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(long long i = 1,u,v;i <= m;i ++)
		cin >> eg2[i].x >> eg2[i].y >> eg2[i].w;
	for(long long i = 1;i <= n + k;i ++)
		for(long long j = 0;j < (1 << k);j ++)f[i][j] = i;
	sort(eg2 + 1,eg2 + m + 1,cmp);
	for(long long i = 1;i <= m;i ++)
	{
		long long u = find(eg2[i].x,0),v = find(eg2[i].y,0);
		if(u == v)continue ;
		f[u][0] = v,dp[0] += eg2[i].w;
		eg[++cnt] = {eg2[i].x,eg2[i].y,eg2[i].w};
	}
	m = cnt;
	for(long long i = 1;i <= k;i ++)
	{
		cin >> a[i];
		for(long long j = 1;j <= n;j ++)cin >> b[j],eg[++m] = {i + n,j,b[j]};
	}
	sort(eg + 1,eg + m + 1,cmp);
	for(long long i = 1;i <= m;i ++)
	{
		//long long u = find(eg2[i].x),v = find(eg2[i].v);
		for(long long j = 1;j < (1 << k);j ++)
		{
			if(eg[i].x > n && !((j >> (eg[i].x - n - 1)) & 1))continue ;
			long long u = find(eg[i].x,j),v = find(eg[i].y,j);
			if(u == v)continue ;
			dp[j] += eg[i].w,f[u][j] = v;
		}
	}
	long long ans = 1e18,num = 0;
	for(long long i = 0;i < (1 << k);i ++)
	{
		num = dp[i];
		for(long long j = 0;j < k;j ++)
			if((i >> j) & 1)num += a[j + 1];
		ans = min(ans,num);
	}
	cout << ans;
	return 0;
} 
