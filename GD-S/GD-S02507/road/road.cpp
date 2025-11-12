#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct P
{
	int u,v,w;
} a[1100005];
struct K
{
	int cj,jian[10005];
} c[105];
bool cmp(P x,P y)
{
	return x.w < y.w;
}
int fa[20005];
int find(int x)
{
	return (fa[x] == x) ? x : fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)] = find(y);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
		cin >> a[i].u >> a[i].v >> a[i].w;
	for (int i = 1;i <= n + k;i++)
		fa[i] = i;
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i].cj;
		for (int j = 1;j <= n;j++)
		{
			cin >> c[i].jian[j];
			a[m + (k - 1) * n + j].u = n + i;
			a[m + (k - 1) * n + j].v = j;
			a[m + (k - 1) * n + j].w = c[i].jian[j];
		}
	}
	sort(a + 1,a + m + k * n + 1,cmp);
	long long sum = 0;
	for (int i = 1;i <= m + k * n;i++)
	{
		int uu = a[i].u,vv = a[i].v;
		//cout << find(uu) << " " << find(vv) << " " << a[i].w << endl;
		if (find(uu) != find(vv))
		{
			merge(uu,vv);
			sum += a[i].w;
			//cout << a[i].w << endl;
			//cout << a[i].w << endl;
		}
	}
	cout << sum;
}
