#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 10;
const int M = 2e6 + 10;
const int K = 13;

int n, m, k;
int C[N][K], cost[K];
int p[N], cnt = 0;
struct Edge
{
	int u, v, w;
}edge[M], edge1[M];
struct Node
{
	int val, id;
};
int ans = 1e18;
vector<Edge> tmp;
vector<Node> Tmp[N];

bool cmp1(Edge a, Edge b)
{
	return a.w < b.w;
}
bool cmp2(Edge a, Edge b)
{
	return a.w > b.w;
}
bool cmp3(Node a, Node b)
{
	return a.val < b.val;
}

int find(int u)
{
	if(p[u] != u) p[u] = find(p[u]);
	return p[u];
}

int kruscal()
{
	for(int i = 1 ; i <= n ; i ++ ) p[i] = i;
	sort(edge + 1, edge + 1 + m, cmp1);
	int res = 0;
	for(int i = 1 ; i <= m ; i ++ )
	{
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		int fu = find(u);
		int fv = find(v);
		if(fu == fv) continue;
		p[fu] = fv;
		res += w;
		tmp.push_back(edge[i]);
	}
	return res;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++ ) cin >> edge[i].u >> edge[i].v >> edge[i].w;
	for(int i = 1 ; i <= k ; i ++ )
	{
		cin >> cost[i];
		for(int j = 1 ; j <= n ; j ++ )
		{
			cin >> C[i][j];
			Tmp[i].push_back({C[i][j], j});
		} 
		sort(Tmp[i].begin(), Tmp[i].end(), cmp3);
	}
	ans = kruscal();
	sort(tmp.begin(), tmp.end(), cmp2);
	int idx = 0, Cost = 0;
	for(int i = 1 ; i <= k ; i ++ )
	{
		int tmp1 = C[i][tmp[idx].u];
		int tmp2 = C[i][tmp[idx].v];
		if(Tmp[i][0].id != tmp[idx].u) tmp1 += Tmp[i][0].val;
		else tmp1 += Tmp[i][1].val;
		if(Tmp[i][0].id != tmp[idx].v) tmp2 += Tmp[i][0].val;
		else tmp2 += Tmp[i][1].val;
		int newcost = ans + cost[i] - tmp[idx].w + min(tmp1, tmp2);
		if(newcost <= ans)
		{
//			cout << i << " ";
			idx ++ ;
			Cost += cost[i];
			for(int j = 1 ; j <= n ; j ++ )
			{
				edge[ ++ m] = {i + n, j, C[i][j]};
////				cout << edge[m].u << " " << edge[m].v << " " << edge[m].w << endl;
			}
			n += idx;
			ans = min(ans, Cost + kruscal());
			n -= idx;
		}
	}
	cout << ans;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
