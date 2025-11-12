#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

const int N = 1e6 + 30, M = 1e4 + 30, T = 1e8 + 5;
int /*head[N], nxt[N], w[N], ver[N], c[N], a[11][M],*/ fa[N], tot;
int n, m, k;
vector<int> e[N];
struct node{
	int x, y, z;
	bool operator <(const node &p) const{
		return z < p.z;
	}
}stk[T];
/*
void add(int x, int y, int z)
{
	nxt[++tot] = y;
	w[tot] = z;
	ver[tot] = head[x];
	head[x] = tot;
}*/

int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

ll kru()
{
	sort(stk + 1, stk + tot + 1);
	ll ans = 0;
	for(int i = 1; i <= tot; i++)
	{
		if(stk[i].x > stk[i].y) swap(stk[i].x, stk[i].y);
		int x = stk[i].x, y = stk[i].y;
		if(x <= n && find(x) != find(y))
		{
			ans += stk[i].z;
			fa[x] = y;
		}
	}
	return ans;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		//add(x, y, z);
		//add(y, x, z);
		stk[++tot] = {x, y, z};
		//e[x].push_back({y, z});
		//e[y].push_back({x, z});
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	//bool flag = true;
	for(int i = 1; i <= k; i++)
	{
		int c;
		scanf("%d", &c);
		//if(c[i] != 0) flag = false;
		for(int j = 1; j <= n; j++)
		{
			int w;
			scanf("%d", &w);
			stk[++tot] = {n + i, j, w};
		}
	}
	printf("%lld\n", kru());
	return 0;
}
