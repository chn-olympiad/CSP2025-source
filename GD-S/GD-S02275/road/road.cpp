#include <bits/stdc++.h>
#define O 10005
using namespace std;
long long n,m,k,ans = 0;
long long cost[O];
long long fa[O];
bool used[15];
struct edge
{
	long long f,t,w;
};
bool cmp(edge e1,edge e2)
{
	return e1.w < e2.w;
}
int find(int a) 
{
	while(a != fa[a])
		a = fa[a];
	return a;
}
vector <edge> v;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i = 1;i <= n;++i)
		fa[i] = i;
	for(int i = 1;i <= m;++i)
	{
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		v.push_back({a,b,c});
	}
	for(int i = 1;i <= k;++i)
	{
		for(int q = 1;q <= n + 1;++q)
			scanf("%lld",&cost[q]);
		for(int q = 2;q <= n + 1;++q)
		{
			for(int p = q + 1;p <= n + 1;++p)
				v.push_back({q - 1,p - 1,cost[p] + cost[q]});
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0;i < v.size();++i)
	{
		int n1 = v[i].f,n2 = v[i].t,w = v[i].w;
		if(find(n1) != find(n2))
			fa[find(n2)] = find(n1),ans += w;	//合并 
		else
			continue;
	}
	printf("%lld",ans);
	return 0;
}
/*
先用性质A
即改造乡村的花费为0
那么此时,我们相当于直接新建一条边
问题变为:在若干条边中取最小的边,使得所有点联通
显然,我们要取最小边的数量使得所有点联通,不就是最小生成树?
那不就是选择n - 1条边,使得n个点联通	想到基于贪心+并查集的Kruskal
但是n ^ 2的存边操作还是非常烦人的
尝试考虑将n ^ 2的存边操作减小时空复杂度 
暂时也想不到思路了(甚至都不知道Kruskal打的对不对……)

*/
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
