#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

int fa[10005];
bool flag[10005];
struct line
{
	int f, t, v;
}l[7500005];
int add[100005][15];

inline bool cmp(line x, line y){return x.v <y.v;}

inline int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x] = find(fa[x]);
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	scanf("%lld %lld %lld",&n, &m, &k);
	for(register int i = 1; i <= n; i++)fa[i]=i;
	for(register int i = 1; i <= m; i++) scanf("%lld %lld %lld",&l[i].f, &l[i].t, &l[i].v);
	for(register int i = 1; i <= k; i++) for(register int j(0); j <= n; j++) scanf("%lld", &add[j][i]);
	for(register int t = 1; t <= k; t++) for(register int i(1); i <= n; i++) for(register int j = i + 1; j <= n; j++) m++, l[m]={i, j, add[0][t] + add[i][t] + add[j][t]};
	sort(l + 1, l + m + 1, cmp);
	int ans(0), cnt(0);
	for(register int i = 1; i <= m; i++)
	{
		int x = find(l[i].f);
		if(!flag[x])flag[x] = 1, cnt++;
		int y = find(l[i].t);
		if(!flag[y])flag[y] = 1, cnt++;
		if(x != y)
		{
			ans += l[i].v;
			fa[x] = fa[y];
			find(x), find(y);
		}
		if(cnt == n)break;
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
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
