
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int N = 10050, M = 1000005, K = 15;
int c[K], a[K][N], ufs[N], idx;
ull res, mres;
struct edge {
	int u, v, w;
} re[M], e[M + N * K];

int findsz(int nd)
{
	if (ufs[nd] < 0) return nd;
	return findsz(ufs[nd]);
}

bool merge(int a, int b)
{
	int sza = findsz(a), szb = findsz(b);
	if (sza == szb) return false;
	if (ufs[sza] > ufs[szb]) swap(sza, szb);
	ufs[sza] += ufs[szb], ufs[szb] = sza;
	return true;
}

void init(int nm)
{
	for (int i = 1; i <= nm; ++i) ufs[i] = -1;
}

bool cmp(edge e1, edge e2)
{
	return e1.w < e2.w;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, blk;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) scanf("%d%d%d", &re[i].u, &re[i].v, &re[i].w);
	for (int j = 0; j < k; ++j)
	{
		scanf("%d", c + j);
		for (int i = 1; i <= n; ++i) scanf("%d", a[j] + i);
	}
	sort(re, re + m, cmp);
	for (int s = 0; s < (1 << k); ++s)
	{
		res = 0, blk = n, idx = 0;
		bool flag = true;
		for (int j = 0; j < k; ++j)
			if ((s >> j) & 1)
			{
				res += c[j], ++blk;
				if (s && res > mres)
				{
					flag = false;
					break;
				}
				for (int i = 1; i <= n; ++i, ++idx)
					e[idx].u = i, e[idx].v = blk, e[idx].w = a[j][i];
			}
		if (!flag) continue;
		init(blk);
		sort(e, e + idx, cmp);
		edge cu;
		for (int i = 0, j = 0; blk > 1;)
		{
			if (j >= idx || re[i].w < e[j].w) cu = re[i], ++i;
			else cu = e[j], ++j;
			if (merge(cu.u, cu.v)) res += cu.w, --blk;
			if (s && res > mres) break;
		}
		mres = s ? min(mres, res) : res;
	}
	cout << mres << endl;
	return 0;
}

