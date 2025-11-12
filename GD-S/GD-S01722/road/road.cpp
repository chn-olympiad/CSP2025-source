#include<bits/stdc++.h>
using namespace std;
int fa[10005],w[10005];
struct node{
	int u,v,w;
};
node q[1000005];
bool cmp(node a,node b)
{
	return a.w < b.w;
}
int find(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = find(fa[a]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum = 0,ans = 0;
	cin >> n >> m >> k;
	if(k)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].w);
	}
	for(int i = 1; i <= k; i++)
	{
		int c;
		scanf("%d",&c);
		for(int j = 1; j <= n; j++)
		{
			scanf("%d",&w[j]);
		}
	}
	sort(q + 1,q + m + 1,cmp);
	for(int i = 1; i <= m; i++)
	{
		int a = find(q[i].u),b = find(q[i].v);
		if(a != b)
		{
			ans += q[i].w;
			fa[a] = b;
			sum++;
		}
		if(sum >= n - 1) break;
	}
	cout << ans;
	return 0;
}
/*
5 6
1 2 1
2 3 1
3 4 4
1 3 3
2 5 2
4 5 3

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
