#include <iostream>
#include <algorithm>

typedef long long ll;

const int M = 1e6 + 5,N = 1e4 + 5;

struct edge
{
	int u,v,w;
}e[M + 20 * N];
bool cmp(edge x,edge y)
{
	return x.w < y.w;
}
int n = 0,m = 0,k = 0;
int c[20];
int a[20][N];
int f[N + 20],siz[N + 20];

int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int x,int y)
{
	int fx =find(x),fy = find(y);
	if(siz[fx] > siz[fy])
	{
		f[fy] = f[fx];
		siz[fx] += siz[fy];
	}
	else
	{
		f[fx] = fy;
		siz[fy] += siz[fx];
	}
}

int ty[20],tn;
ll sum;
ll fans = (ll)1e15;
void dfs(int pos)
{
	if(pos > k)
	{
		int tm = m;
		for(int i = 1;i <= k;i++)
			if(ty[i])
				for(int j = 1;j <= n;j++)
					e[++tm] = {j,i + k,a[i][j]};
		ll ans = sum;
		int cnt = 0;
		for(int i = 1; i <= n + k;i++)
			f[i] = i,siz[i] = 1;
		std::sort(e + 1,e + tm + 1,cmp);
		for(int i = 1; i <= tm;i++)
		{
			if(find(e[i].u) == find(e[i].v))
				continue;
			ans += (ll)e[i].w;
			merge(e[i].u,e[i].v);
			if(++cnt >= n + tn - 1)
				break;
		}
		fans = std::min(fans,ans);
		return;
	}
	dfs(pos + 1);
	ty[pos] = 1;
	sum += c[pos];
	dfs(pos + 1);
	sum -= c[pos];
	ty[pos] = 0;
}

int sm[20];
int main(void)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i = 1;i <= m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	
	for(int i = 1;i <= k;i++)
	{
		scanf("%d",&c[i]);
		for(int j = 1;j <= n;j++)
			scanf("%d",&a[i][j]);
	}
	
	if(k == 0)
	{
		ll ans = 0;
		int cnt = 0;
		for(int i = 1; i <= n;i++)
			f[i] = i,siz[i] = 1;
		std::sort(e + 1,e + m + 1,cmp);
		for(int i = 1; i <= m;i++)
		{
			if(find(e[i].u) == find(e[i].v))
				continue;
			merge(e[i].u,e[i].v);
			ans += (ll)e[i].w;
			if(++cnt >= n - 1)
				break;
		}
		printf("%lld\n",ans);
	}
	else
	{
		bool flag = true;
		for(int i = 1;i <= k;i++)
			if(c[i]) flag = false;
		if(flag)
		{
			for(int i = 1;i <= k;i++)
				for(int j = 1;j <= n;j++)
					if(a[i][j] == 0) sm[i] = j;
			for(int i = 1;i <= k;i++)
				for(int j = 1;j <= n;j++)
					e[++m] = {j,sm[i],a[i][j]};
			ll ans = 0;
			int cnt = 0;
			for(int i = 1; i <= n;i++)
				f[i] = i,siz[i] = 1;
			std::sort(e + 1,e + m + 1,cmp);
			for(int i = 1; i <= m;i++)
			{
				if(find(e[i].u) == find(e[i].v))
					continue;
				ans += (ll)e[i].w;
				merge(e[i].u,e[i].v);
				if(++cnt >= n - 1)
					break;
			}
			printf("%lld\n",ans);
		}
		else
		{
			dfs(1);
			printf("%lld\n",fans);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
