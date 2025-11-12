#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int n, m, k, fa[N], cnt1, h[15], vis[N], cnt;

struct node
{
	int u, v, w;
}e[N], ee[N], ed[N];
int siz[1500][15][1500], s = 0, visb[1500][15][1500], q[15][1500];
int fau[N], fav[N];

bool cmp(node a, node b)
{
	return a.w < b.w;
}

inline int find(int x)
{
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n + k; i ++ )
		fa[i] = i;
	for(int i = 1; i <= m; i ++ )
	{
		int u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		e[++ cnt] = {u, v, w};	
	}  
	for(int i = 1; i <= k; i ++ )
	{
		scanf("%lld", &h[i]);
		for(int j = 1, c; j <= n; j ++ )
			scanf("%lld", &c), ee[++ cnt1] = {n + i, j, c}, siz[0][i][j] = c, visb[0][i][j] = j, q[i][j] = 1;
	}
	int ans = 0x3f3f3f3f;
	int S = cnt;
	if(k == 0)
	{
		sort(e + 1, e + cnt + 1, cmp);
		for(int i = 1; i <= cnt; i ++ )
		{
			int fu = find(e[i].u), fv = find(e[i].v);
			if(fu != fv)
			{
				fa[fu] = fv;
				cnt ++ ;
				ans += e[i].w;
				if(cnt == n - 1)
					break;
			}
		}	
		cout << ans << endl;
	}
	else if(k <= 5 && m <= 100000)
	{
		for(int nowst = 0; nowst < (1 << k); nowst ++ )
		{
			cnt = S;
			for(int i = 1; i <= n + k; i ++ )
				fa[i] = i;
			int nowans = 0, nowc = 0;
			for(int i = 0; i < k; i ++ )
			{
				if((nowst >> i & 1) == 1)
				{
					nowans += h[i + 1];
					for(int j = i * n + 1; j <= (i + 1) * n; j ++ )
						e[++ cnt] = ee[j];
					nowc ++ ;
				}
			}
			sort(e + 1, e + cnt + 1, cmp);
			for(int i = 1; i <= cnt; i ++ )
			{
				int fu = find(e[i].u), fv = find(e[i].v);
				if(fu != fv)
				{
					fa[fu] = fv;
					cnt ++ ;
					nowans += e[i].w;
					if(cnt == n - 1 + nowc)
						break;
				}
			}	
			ans = min(ans, nowans);
		}
		cout << ans << endl;
	}
	else if (n <= 1000)
	{
		for(int i = 1; i <= n; i ++ )	
			for(int j = 1; j <= k; j ++ )
				for(int k = 1; k <= n; k ++ )	
					siz[i][j][k] = siz[0][j][k], visb[i][j][k] = visb[0][j][k];
		int ans = 0;
		sort(e + 1, e + cnt + 1, cmp);
		for(int i = 1; i <= k; i ++ )
			vis[i] = 1;
		int qq = 0;
		for(int i = 1; i <= cnt; i ++ )
		{
			int fu = find(e[i].u), fv = find(e[i].v);
			if(fu != fv)
			{
				qq ++ ;
				for(int j = 1; j <= k; j ++ )
				{
					siz[qq][j][fu] = min(siz[qq - 1][j][fu], siz[qq - 1][j][fv]);
					if(siz[qq][j][fu] == siz[qq - 1][j][fu])
						visb[qq][j][fu] = visb[qq - 1][j][fu];
					else
						visb[qq][j][fu] = visb[qq - 1][j][fv];
				}
				fau[qq] = fu, fav[qq] = fv;
				fa[fv] = fu;
				ans += e[i].w;
				ed[qq] = e[i];
				if(cnt == n - 1)
					break;
			}
		}	
		for(int i = qq; i >= 1; i -- )
		{
			int noww = 0x3f3f3f3f, pos = 0;
			for(int j = 1; j <= k; j ++ )
				if(siz[i - 1][j][fau[i]] * q[j][visb[i - 1][j][fau[i]]] 
				+ siz[i - 1][j][fav[i]] * q[j][visb[i - 1][j][fav[i]]] + vis[j] * h[j] < noww)
					noww = siz[i - 1][j][fau[i]] + siz[i - 1][j][fav[i]] + vis[j] * h[j], pos = j;
			if(noww < ed[i].w)	
				ans = ans - ed[i].w + noww, vis[pos] = 0, q[pos][visb[i - 1][pos][fau[i]]] = 0, q[pos][visb[i - 1][pos][fav[i]]] = 0;
		}
		cout << ans << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}
