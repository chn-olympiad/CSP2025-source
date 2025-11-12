#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e7 + 10;
int n, m, k, c[15], fa[N];
struct node{
	int from;
	int to;
	int num;
	int sp;
} e[N];
bool cmp(node a1, node a2)
{
	return a1.num < a2.num;
}
int ff(int x)
{
	if(fa[x] != x) return fa[x] = ff(fa[x]);
	else return fa[x];
}
void uni(int x, int y)
{
	int fx = ff(x);
	int fy = ff(y);
	fa[fy] = fx;
}
int ans = INF;
void bzd(int con)
{
	int sum = 0;
	for(int i = 1;i <= n + k;i ++) fa[i] = i;
	for(int i = 1;i <= m;i ++)
	{
		if(e[i].sp && ((e[i].sp & con) == 0)) continue;
		int fx = ff(e[i].from);
		int fy = ff(e[i].to);
		if(fx == fy) continue;
		uni(fx, fy);
		sum += e[i].num;
	}
	for(int i = 0;i < k;i ++)
	{
		if(con & (1 << i))
		{
			sum += c[i + 1];
		}
	}
	ans = min(ans, sum);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++)
	{
		int u, v, w;
		cin >> e[i].from >> e[i].to >> e[i].num;
	} 
	for(int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j ++)
		{
			e[++m].from = n + i;
			e[m].to = j;
			e[m].sp = i;
			cin >> e[m].num;
		}
	}
	sort(e + 1, e + m + 1, cmp);
	int pu = (1 << k);
	for(int i = 0;i < pu;i ++)
	{
		bzd(i);
	}
	cout << ans;
	return 0;
}

