#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
const int M = 1e6;
struct node{
	int u,v,w;
}road[M];
int n,m,k;
int a[15][N],c[N];
bool cmp(node x,node y)
{
	return x.w < y.w;
}
int fa[N];
int find(int x)
{
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
int ans = 0;
void kru()
{
	for(int i = 1;i <= n;i++)fa[i] = i;
	sort(road + 1,road + m + 1,cmp);
	int cnt = 0;
	for(int i = 1;i <= m;i++)
	{
		int u = road[i].u,v = road[i].v;
		int x = find(u),y = find(v);
		if(x == y)continue;
		fa[x] = y;
		cnt++;
		ans += road[i].w;
		if(cnt == n-1)
		{
			return;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].w);
	}
	bool flag = true;
	for(int i = 1;i <= k;i++)
	{
		scanf("%d",&c[i]);
		if(c[i])flag = false;
		for(int j = 1;j <= n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j])flag = false;
		}
	}
	if(k && flag)
	{
		printf("0\n");
		return 0;
	}
	kru();
	printf("%d\n",ans);
	return 0;
}
