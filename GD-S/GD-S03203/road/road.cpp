#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
	ll ret = 0 ,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -f : f) ,ch = getchar();
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0' ,ch = getchar();
	return ret * f;
}

int n ,m ,k;
const int N = 2e4 + 10 ,M = 2e6 + 10 ,K = 12;
struct Edge{
	int u ,v ,w;
} e[M] ,e2[M]; int tot;
bool cmp(Edge a ,Edge b) { return a.w < b.w; }
ll a[K][N] ,c[K];
int id[N][K];

int vis[M];

struct Union{
	int fa[N];
	
	void init(int n) { for (int i = 1;i <= n;i++) fa[i] = i; }
	int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
	void merge(int x ,int y) { fa[find(x)] = find(y); }
} U;

ll kruskal(int m)
{
	sort(e + 1 ,e + 1 + m ,cmp);
	U.init(n + k);
	for (int i = 1;i <= m;i++) vis[i] = 0;
	
	ll ret = 0;
	for (int i = 1;i <= m;i++)
		if (U.find(e[i].u) != U.find(e[i].v))
		{
			vis[i] = 1;
			ret += e[i].w;
			U.merge(e[i].u ,e[i].v);
		}
	
	return ret;
}

int main()
{
	freopen("road.in" ,"r" ,stdin);
	freopen("road.out" ,"w" ,stdout); 
	n = read() ,m = read() ,k = read();
	
	for (int i = 1;i <= m;i++) e[i] = e2[i] = {read() ,read() ,read()};
	for (int i = 1;i <= k;i++)
	{
		c[i] = read();
		for (int j = 1;j <= n;j++) a[i][j] = read();
	}
	
	ll ans = kruskal(m);
	
	for (int i = 1;i <= m;i++) if (vis[i]) e2[++tot] = e[i];
	for (int i = 1;i <= tot;i++) e[i] = e2[i];
	
	for (int i = 1;i < (1 << k);i++)
	{
		ll sum = 0; int idx = tot;
		for (int j = 1;j <= tot;j++) e[j] = e2[j];
		for (int j = 1;j <= k;j++)
			if ((i >> (j - 1)) & 1)
			{
				sum += c[j];
				for (int l = 1;l <= n;l++) e[++idx] = {l ,n + j ,a[j][l]} ,id[l][j] = idx;
			}
		sum += kruskal(idx);
		ans = min(ans ,sum);
	}
	
	printf("%lld\n",ans);
	
	return 0;
}
