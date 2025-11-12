#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int ver[110001], head[10011], nextt[1100001];
long long edge[1100001];
long long a[6][10001];
long long c[6];
int tot = 0;
//edge
struct rec
{
	int id;
	long long val;
	rec()
	{
		id = 0;
		val = 0;
	}
	rec(int idd, long long vall)
	{
		id = idd;
		val = vall;
	}
};
bool operator <(const rec &r1, const rec &r2)
{
	return r1.val > r2.val;
}
priority_queue< rec > q;

int fa[10001];
long long ans = 0;
int num = 0;

int Get(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = Get(fa[x]);
}

void add(int x, int y, long long z)
{
	tot++;
	ver[tot] = y;
	edge[tot] = z;
	nextt[tot] = head[x];
	head[x] = tot;
}

void Kruskal()
{
	for(int i = head[1]; i; i = nextt[i])
	{
		q.push(rec(i, edge[i]));
	}
	while(!q.empty() && num < n-1)
	{
		rec r = q.top();
		q.pop();
		ans += r.val;
		num++;
		int v = ver[r.id];
		if(Get(v) == 1) continue;
		fa[v] = 1;
		for(int i = head[v]; i; i = nextt[i])
		{
			if(Get(ver[i]) != 1)
			{
				q.push(rec(i, edge[i]));
			}
		}
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n;i++)
	{
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++)
	{
		int u,v;
		long long w;
		cin >> u >> v >>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int j = 1; j <= k; j++)
	{
		cin >> c[j];
		for(int ii = 1; ii <= n; ii++)
		{
			cin >> a[j][ii];
		}
	}
	Kruskal();
	cout << ans << endl;
	
	return 0;
}
