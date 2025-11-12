/* expect : 100 pts */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
using namespace std;

const int N = 10050, M = 1000010, K = 15;
int n, m, k; long long c[K], a[K][N];
struct Edge {int x, y; long long val;} e[M];
inline bool cmp(Edge u, Edge v) {return u.val < v.val;}

vector < Edge > tmp[1024], extra[K], sve;
inline void work(vector < Edge > &A, vector < Edge > &B)
{
	sve.clear();
	int ptA = 0, ptB = 0;
	while(ptA < (int)A.size() || ptB < (int)B.size())
	{
		if(ptA >= (int)A.size()) sve.push_back(B[ptB]), ++ptB;
		else if(ptB >= (int)B.size()) sve.push_back(A[ptA]), ++ptA;
		else if(A[ptA].val <= B[ptB].val) sve.push_back(A[ptA]), ++ptA;
		else sve.push_back(B[ptB]), ++ptB;
	}
}

struct DSU
{
	int prt[N], siz[N];
	inline void init(int n) {for(int i = 1; i <= n; ++i) prt[i] = i, siz[i] = 1;}
	inline int find(int x) {return ((prt[x] == x) ? x : (prt[x] = find(prt[x])));}
	inline void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if(x != y)
		{
			x = find(x), y = find(y);
			if(x != y)
			{
				if(siz[x] > siz[y]) swap(x, y);
				prt[x] = y, siz[y] += siz[x];
			}
		}
	}
}; DSU dsu;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) cin >> e[i].x >> e[i].y >> e[i].val;
	for(int i = 1; i <= k; ++i)
	{
		cin >> c[i];
		for(int j = 1; j <= n; ++j) cin >> a[i][j];
	}

	sort(e + 1, e + m + 1, cmp);
	dsu.init(n + k);
	for(int i = 1; i <= m; ++i)
		if(dsu.find(e[i].x) != dsu.find(e[i].y))
			dsu.merge(e[i].x, e[i].y), tmp[0].push_back(e[i]);
	
	for(int i = 1; i <= k; ++i)
	{
		for(int j = 1; j <= n; ++j)
			extra[i].push_back({n + i, j, a[i][j]});
		sort(extra[i].begin(), extra[i].end(), cmp);
	}

	for(int mask = 1; mask < (1 << k); ++mask)
	{
		int id = __lg(lowbit(mask)) + 1;
		work(tmp[mask - lowbit(mask)], extra[id]);
		dsu.init(n + k);
		for(Edge li : sve)
			if(dsu.find(li.x) != dsu.find(li.y))
				dsu.merge(li.x, li.y), tmp[mask].push_back(li);
	}

	long long res = 1e18;
	for(int mask = 0; mask < (1 << k); ++mask)
	{
		long long cost = 0;
		for(int i = 1; i <= k; ++i)
			if(mask & (1 << (i - 1)))
				cost += c[i];
		for(Edge li : tmp[mask]) cost += li.val;
		if(cost < res) res = cost;
	}
	cout << res << '\n';
	return 0;
}
/*
g++ road.cpp -o road -O2 -std=c++14 -static -Wall -DLOCAL -Wno-unused-result
./road
*/
