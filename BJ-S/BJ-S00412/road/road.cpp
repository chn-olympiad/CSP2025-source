#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n , m , k;
struct node
{
	int u , v , w;
};
vector<node> e[N];
int h[20];
int ans = 1e9;
bool flag[N];
int d[N];
void dfs(int u , int fath , int cntw)
{
	if(d[u] < cntw)
	{
		return;
	}
	d[u] = min(d[u] , cntw);
	flag[u] = true;
	for(int i = 0;i < e[u].size();i++)
	{
		int v = e[u][i].v;
		dfs(v , u , cntw + e[u][i].w);
	}
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	memset(d , 0x3f , sizeof(d));
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		e[u].push_back({u , v , w});
		e[v].push_back({v , u , w});
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> h[i];
		for(int j = 1;j <= n;j++)
		{
			int w;
			cin >> w;
			e[n + i].push_back({n + i , j , w + h[i]});
			e[j].push_back({j , n + i , w + h[i]});
		}
	}
	dfs(1 , -1 , 0);
	int ans = 0;
	for(int i = 1;i <= n + k;i++)
	{
		ans += d[i];
	}
	cout << ans + h[1] << endl;
	return 0;
}
/*
 * 
 * #include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n , m , k;
struct node
{
	int u , v , w;
};
vector<node> e[N];
int h[20];
int ans = 1e9;
bool flag[N];
int d[N];
void dfs(int u , int fath , int cntw)
{
	if(d[u] < cntw)
	{
		return;
	}
	d[u] = min(d[u] , cntw);
	flag[u] = true;
	for(int i = 0;i < e[u].size();i++)
	{
		int v = e[u][i].v;
		dfs(v , u , cntw + e[u][i].w);
	}
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	memset(d , 0x3f , sizeof(d));
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		e[u].push_back({u , v , w});
		e[v].push_back({v , u , w});
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> h[i];
		for(int j = 1;j <= n;j++)
		{
			int w;
			cin >> w;
			e[n + i].push_back({n + i , j , w + h[i]});
			e[j].push_back({j , n + i , w + h[i]});
		}
	}
	dfs(1 , -1 , 0);
	int ans = 0;
	for(int i = 1;i <= n + k;i++)
	{
		ans += d[i];
	}
	cout << ans + h[1] << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n , m , k;
struct node
{
	int u , v , w;
};
vector<node> e[N];
int h[20];
int ans = 1e9;
bool flag[N];
int d[N];
void dfs(int u , int fath , int cntw)
{
	if(d[u] < cntw)
	{
		return;
	}
	d[u] = min(d[u] , cntw);
	flag[u] = true;
	for(int i = 0;i < e[u].size();i++)
	{
		int v = e[u][i].v;
		dfs(v , u , cntw + e[u][i].w);
	}
}
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	memset(d , 0x3f , sizeof(d));
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		e[u].push_back({u , v , w});
		e[v].push_back({v , u , w});
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> h[i];
		for(int j = 1;j <= n;j++)
		{
			int w;
			cin >> w;
			e[n + i].push_back({n + i , j , w + h[i]});
			e[j].push_back({j , n + i , w + h[i]});
		}
	}
	dfs(1 , -1 , 0);
	int ans = 0;
	for(int i = 1;i <= n + k;i++)
	{
		ans += d[i];
	}
	cout << ans + h[1] << endl;
	return 0;
}
*/