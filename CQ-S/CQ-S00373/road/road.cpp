#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 5; 
const ll M = 10 + 2;
const ll P = 1e4 + 5; 
const ll INF = 1e16;

struct Edge{
	ll from;
	ll to;
	ll w;
}graph[N],use[N << 1];
bool cmp(const Edge& A,const Edge& B)
{
	return A.w < B.w;
}
ll fa[N];
ll find(ll x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
ll n,m,k;
ll build[M];
Edge cost[M][P];
Edge store[N << 1];
void merge(Edge a[],ll s1,Edge b[],ll s2,Edge dst[],ll& len)
{
	ll cnt = 0;
	ll p = 1,q = 1;
	while(p <= s1 && q <= s2)
	{
		if(a[p].w < b[q].w)
			store[++cnt] = a[p++];
		else
			store[++cnt] = b[q++];
	}
	while(p <= s1)
		store[++cnt] = a[p++];
	while(q <= s2)
		store[++cnt] = b[q++];
	for(ll i = 1;i <= cnt;i++)
		dst[i] = store[i];
	len = cnt;
	return;
}
ll calc(ll s)
{
	ll ans = 0,t = 0;
	for(ll i = 1;i <= m;i++)
		use[i] = graph[i];
	t = m;
	for(ll i = 1;i <= k;i++)
	{
		if(s >> (i - 1) & 1)
		{
			ans += build[i];
			merge(use,t,cost[i],n,use,t);
		}
	}
	for(ll i = 1;i <= n + k;i++)
		fa[i] = i;
	for(ll i = 1;i <= t;i++)
	{
		ll fx = find(use[i].from),fy = find(use[i].to);
		if(fx != fy)
		{
			fa[fx] = fy;
			ans += use[i].w;
		}
	}
	return ans;
}
int main(void)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool flag = true;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i = 1;i <= m;i++)
		scanf("%lld%lld%lld",&graph[i].from,&graph[i].to,&graph[i].w);
	sort(graph + 1,graph + m + 1,cmp);
//	fprintf(stderr,"#!313\n");
//	clock_t st = clock();
	for(ll i = 1;i <= k;i++)
	{
		scanf("%lld",build + i);
		if(build[i] != 0)
		{
			flag = false;
		}
		for(ll j = 1;j <= n;j++)
		{
			cost[i][j].from = n + i,cost[i][j].to = j;
			scanf("%lld",&cost[i][j].w);
		}
		sort(cost[i] + 1,cost[i] + n + 1,cmp);
	}
	ll ans = INF;
	for(ll s = (flag ? ((1 << k) - 1) : 0);s < (1 << k);s++)
	{
		ll res = calc(s);
//		printf("%lld : %lld\n",s,res);
		ans = min(ans,res);
	}
	printf("%lld\n",ans);
//	fprintf(stderr,"%.2lf\n",(double)(clock() - st) / CLOCKS_PER_SEC);
	return 0;
}
