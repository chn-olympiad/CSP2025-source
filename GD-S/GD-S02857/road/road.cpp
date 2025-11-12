#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n[15],m[15],k,c[15][10005],fa[10015],sz[10015],ans,sum;
struct edge{
	int u,v,w;
	bool use;
}e[15][1000005];
bool cmp(edge x,edge y)
{
	return x.w < y.w;
}
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
	int fx = find(x),fy = find(y);
	if(fx == fy) return;
	if(sz[fx] < sz[fy]) swap(fx,fy);
	fa[fy] = fx;
	sz[fx] += sz[fy];
}
void init()
{
	for(int i = 1; i <= n[0]+k; i++)
	{
		fa[i] = i;
		sz[i] = 1;
	}
}
int kruskal(int id)
{
	sort(e[id] + 1,e[id] + m[id] + 1,cmp);
	init();
	int cnt = 0,sum = 0;
	for(int i = 1; i <= m[id]; i++)
	{
		int u = e[id][i].u,v = e[id][i].v,w = e[id][i].w;
		e[id][i].use = true;
		if(find(u) == find(v)) continue;
		merge(u,v);
		sum += w;
		cnt++;
		if(cnt >= n[id]-1) return sum;
	}
	return -1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n[0] >> m[0] >> k;
	for(int i = 1; i <= m[0]; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[0][i] = {u,v,w,false};
	}
	for(int i = 1; i <= k; i++)
	{
		for(int j = 0; j <= n[0]; j++)
		{
			cin >> c[i][j];
		}
	}
	ans = kruskal(0);
//	cout << ans << endl;
	for(int i = 1; i <= m[0]; i++)
	{
		if(e[0][i].use)
		{
			e[1][++m[1]] = e[0][i];
			e[1][m[1]].use = false;
		}
	}
	for(int i = 1; i <= k; i++)
	{
//		int cnt = 0;
//		for(int j = 1; j <= m[i-1]; j++)
//		{
//			if(e[i-1][j].use)
//			e[i][++m[i]] = e[i-1][j];
//			e[i][++m[i]].use = false;
//		}
		n[i] = n[i-1]+1;
		fa[n[i]] = 0;
		sz[n[i]] = 1;
		for(int j = 1; j <= n[0]; j++)
		{
			e[i][++m[i]] = {n[i],j,c[i][j],false};
		}
		int t = kruskal(i);
		if(t + sum + c[i][0] > ans)
		{
			n[i]--;
			for(int j = 1; j <= m[i-1]; j++)
			{
				if(e[i-1][j].use)
				{
					e[i+1][++m[i+1]] = e[i-1][j];
					e[i+1][m[i+1]].use = false; 
				}
			}
		}
		else
		{
			ans = t;
			sum += c[i][0];
			for(int j = 1; j <= m[i]; j++)
			{
				if(e[i][j].use)
				{
					e[i+1][++m[i+1]] = e[i][j];
					e[i+1][m[i+1]].use = false; 
				}
			}
		}
	}
	cout << ans+sum << endl;
	return 0;
}
