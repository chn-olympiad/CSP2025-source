#include<bits/stdc++.h>
using namespace std;
//MST
int read()
{
	int x = 0;
	char ch = getchar();
	while(ch >= '0' && ch <= '9')
	{
		x *= 10;
		x += ch - '0';
		ch = getchar();
	}
	return x;
}
const int N = 1e4 + 20;
const int M = 2e6 + 1e5 + 1;
const int mod = 998244353, inf = 0x3f3f3f3f;
int n, m, k;
int f[M];
int a[N][N];
struct edge{
	int u, v, w;
};
bool cmp(edge x, edge y)
{
	return x.w < y.w;
}
edge e[M];
int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
void uniset(int x, int y)
{
	x = find(x), y = find(y);
	if(x != y)
	{
		f[x] = y;
	}
}
long long ans = 0;
int c[N];
int d[N];

void spe()
{
	for(int i = 1; i < N; i++)
	{
		f[i] = i;
	}
	
	for(int i = 1; i <= m; i++)
	{
		cin >> e[i].u >> e[i].v >> e[i].w; 
	}
	sort(e+1, e+1+m, cmp);
	for(int i = 1; i <= m; i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(find(u) != find(v))
		{
			uniset(u, v);
			ans += w;
		}
	}
	cout << ans << endl;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(a, 0x3f, sizeof a);
	cin >> n >> m >> k;
	char ch = getchar();
	//cout << n << m << k;
	if(k == 0)
	{
		spe();
	}
	else
	{
		
		for(int i = 1; i < N; i++) f[i] = i;
		
		for(int i = 1; i <= m; i++)
		{
			int u = read(), v = read(), w = read();
			//cout << u << " " << v << " " << w << endl;
			a[u][v] = w;
			a[v][u] = w;
		}
		
		for(int i = 1; i <= k; i++)
		{
			cin >> c[i];
			for(int j = 1; j <= n; j++)
			{
				d[j] = read();
			}
			for(int j = 1; j <= n; j++)
			{
				for(int k = 1; k <= n; k++)
				{
					a[j][k] = min(d[i] + d[j], a[j][k]);
				}
			}
		}
		int len = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[i][j] != inf) e[++len] = (edge){i, j, a[i][j]};
			}
		}
		sort(e+1,e+1+len,cmp);
		for(int i = 1; i <= len; i++)
		{
			int u = e[i].u, v = e[i].v, w = e[i].w;
			if(find(u) != find(v))
			{
				f[u] = v;
				ans += w;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
