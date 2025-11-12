#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt,ans,U,V,fu,fv;
int n,m,k;
int f[10100],sz[10100];
struct Edge{
	int u,v,w;
} e[1100010];
bool cmp(Edge x,Edge y)
{
	return x.w < y.w;
}
int c[11];
int find(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	return f[x] = find(f[x]);
}

signed main()
{
	freopen("road4.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int fl = 1;
	for (int i = 1 ; i <= m ; i++)
	{
		scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for (int i = 1 ; i <= k ; i++)
	{
		cin >> c[i];
		if (c[i] != 0)
		{
			fl = 0;
		}
		for (int j = 1 ; j <= n ; j++)
		{
			cin >> e[m + n * (i - 1) + j].w;
			e[m + n * (i - 1) + j].u = n + i;
			e[m + n * (i - 1) + j].v = j;
		}
	}
	m = m + k * n;
	sort(e + 1,e + m + 1,cmp);
	if (fl == 1)
	{
		for (int i = 1 ; i <= n + k ; i++)
		{
			f[i] = i;
			sz[i] = 1;
		}
		cnt = 0;
		ans = 0;
		for (int i = 1 ; i <= m ; i++)
		{
			if (cnt >= n + k - 1)
			{
				break;
			}
			U = e[i].u;
			V = e[i].v;
			fu = find(U);
			fv = find(V);
			if (fu == fv)
			{
				continue;
			}
			ans += e[i].w;
			cnt++;
			if (sz[fu] > sz[fv])
			{
				swap(fu,fv);
			}
			f[fu] = fv;
			sz[fv] += sz[fu];
		}
		cout << ans;
	}
	else
	{
		int mn;
		for (int ct = n ; ct <= n + k ; ct++)
		{
			for (int i = 1 ; i <= ct ; i++)
			{
				f[i] = i;
				sz[i] = 1;
			}
			cnt = 0;
			ans = c[ct - n];
			for (int i = 1 ; i <= m ; i++)
			{
				if (cnt >= n - (ct == n))
				{
					break;
				}
				if (e[i].u > n && e[i].u != ct)
				{
					continue;
				}
				U = e[i].u;
				V = e[i].v;
				fu = find(U);
				fv = find(V);
				if (fu == fv)
				{
					continue;
				}
				ans += e[i].w;
				cnt++;
				if (sz[fu] > sz[fv])
				{
					swap(fu,fv);
				}
				f[fu] = fv;
				sz[fv] += sz[fu];
			}
			if (ct == n)
			{
				mn = ans;
			} 
			mn = min(ans,mn);
		}
		cout << mn;
	}
	return 0;
} 
