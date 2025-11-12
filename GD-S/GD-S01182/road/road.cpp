#include <bits/stdc++.h>
using namespace std; 
int n, m, k; 
struct edge
{
	int u, v, w; 
	edge(int _u, int _v, int _w)
	{
		u = _u; 
		v = _v; 
		w = _w; 
	}
}; 
struct cmp2
{
	operator ()(edge x, edge y)
	{
		return x.w > y.w; 
	}
}; 
bool cmp(edge x, edge y)
{
	return x.w < y.w; 
}
int fa[10005]; 
int get_father(int fath)
{
	if(fa[fath] == fath) return fath; 
	else return fa[fath] = get_father(fa[fath]); 
}
void link(int x, int y)
{
	x = get_father(x); 
	y = get_father(y); 
	fa[x] = y; 
}
vector<edge> e[10005]; 
priority_queue<edge, vector<edge>, cmp2> q; 
int main()
{
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k; 
	int ans = 0; 
	for(int i = 1; i <= n; i++)
		fa[i] = i; 
	while(m--)
	{
		int u, v, w; 
		cin >> u >> v >> w; 
		e[u].push_back(edge(u, v, w)); 
		e[v].push_back(edge(v, u, w)); 
		q.push(edge(u, v, w)); 
		q.push(edge(v, u, w)); 
	}
	if(k == 0)
	{
		while(!q.empty())
		{
			int u = q.top().u, v = q.top().v, w = q.top().w; 
			q.pop(); 
			if(get_father(u) == get_father(v)) continue; 
			link(u, v); 
			ans += w; 
		}
		cout << ans; 
	}
	else
	{
		
	}
	return 0;
}

