#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int ans,n,m,k,vis[20],c[20],fa[N],ch[20];
struct edge
{
	int u,v,w,pt;
} e[N];

int getfa(int x)
{
	return (fa[x] == x ? fa[x] : fa[x] = getfa(fa[x]));
}

int kruskal()
{
	int sum = 0;
	for(int i = 1;i <= m + k * n;i++)
	{
		int u = e[i].u,v = e[i].v,w = e[i].w;
		if(u > n)
			if(!ch[u - n])
				continue;
		if(v > n)
			if(!ch[v - n])
				continue;
		if(getfa(u) == getfa(v)) continue;
		fa[getfa(u)] = getfa(v);
		sum += w;
	}
	return sum;
}

bool cmp(edge x,edge y)
{
	return x.w < y.w;
}

void init()
{
	memset(vis,0,sizeof(vis));
	memset(ch,0,sizeof(ch));
	for(int i = 0;i < N;i++) fa[i] = i;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	
	int idx = m;
	for(int x = 1;x <= k;x++)
	{
		cin >> c[x];
		for(int i = 1;i <= n;i++)
		{
			int l;
			cin >> l;
			e[++idx].u = x + n,e[idx].v = i,e[idx].w = l;
		}
	}
	
	sort(e + 1,e + m + k * n + 1,cmp);
	init();
	ans = kruskal();
	if(k == 0)
	{
		cout << ans;
		return 0;
	}
	
	for(int st = 0;st < (1 << k);st++)
	{
		init();
		int sum = 0;
		for(int p = st;p;p &= (p - 1))
		{
			int u = __builtin_ctz(p);
			ch[u + 1] = 1;
			sum += c[u + 1];
		}
		ans = min(ans,kruskal() + sum);
	}
	cout << ans;
}
