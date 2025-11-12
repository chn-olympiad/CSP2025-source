#include <iostream>
#include <vector>
#include <algorithm>

namespace preFile
{
	void init()
	{
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
		std::cout.tie(0);
	}
}

const int maxn = 1e4 + 3;
const int maxm = 1e6 + 3;
struct edge{ int p1, p2, w; };
std::vector<edge> e;
int n, m, k, fa[maxn], c[13], a[maxn][13];
std::vector<int> g[maxn];
bool cmp(edge a, edge b){ return a.w < b.w; }
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(int x, int y) { fa[find(x)] = find(y); }
bool check(int x, int y) { return find(x) == find(y); }
long long ans;

void kru()
{
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	std::sort(e.begin(), e.end(), cmp);
	for (auto t : e)
	{
		int a = t.p1, b = t.p2;
		if (check(a, b))
			continue;
		ans += t.w;
		merge(a, b);
	}
}

int main()
{
	preFile::init();
	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		edge t; std::cin >> t.p1 >> t.p2 >> t.w;
		e.push_back(t);
	}
	for (int i = 1; i <= k; i++)
	{
		std::cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			std::cin >> a[i][j];
			e.push_back({n + i, j, a[i][j]});
		}	
	}
	kru();
	std::cout << ans;
	return 0;
}