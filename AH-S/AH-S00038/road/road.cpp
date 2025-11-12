#include<queue>
#include<cstdio>
#include<string.h>
#include<algorithm>
//#define long long long long
using namespace std;
struct node
{
	long long next;
	long long u;
	long long v;
	long long w;
};
node edge[4001000];
long long head[100100];
long long cnt;
void add(long long u,long long v,long long w)
{
	cnt++;
	edge[cnt].next = head[u];
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].w = w;
	head[u] = cnt;
}
node e[4001000];
long long c[20];
long long fa[100100];
long long ww[1010][20];
struct cmp
{
	bool operator() (node x,node y)
	{
		return x.w > y.w;
	}
};
priority_queue<node,vector<node>,cmp> q;
long long find(long long u)
{
	if(fa[u] == u)	return u;
	//fa[u] = find
	return fa[u] = find(fa[u]);
}
long long prim(long long n)
{
	long long ans = 0;
	long long flag = 0;
	while(!q.empty() && flag < n)
	{
		node x = q.top();
		q.pop();
		long long fu = find(x.u);
		long long fv = find(x.v);
		if(fu == fv)
		{
			continue;
		}
		fa[fu] = fv;
		flag++;
		//printf("a%lld %lld %lld\n",x.u,x.v,x.w);
		fa[x.u] = x.v;
		ans += x.w;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	long long i;
	for(i = 1;i <= m;i++)
	{
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(i = 1;i <= n;i++)
	{
		fa[i] = i;
	}
	long long j;
	//for(i = 1;i <= k;i++)
	//{
		//scanf("%lld",&c[i]);
		//for(j = 1;j <= n;j++)
		//{
			//scanf("%lld",)
		//}
	//}
	for(i = 1;i <= k;i++)
	{
		scanf("%lld",&c[i]);
		for(j = 1;j <= n;j++)
		{
			long long w;
			scanf("%lld",&w);
			ww[j][i] = w;
			e[j].v = j;
			e[j].w = w;
			//add(i + n,j,w);
			//add(j,i + n,w);
		}
		long long id = -1;
		for(j = 1;j <= n;j++)
		{
			if(e[j].w == 0)
			{
				id = j;
			}
		}
		for(j = 1;j <= n;j++)
		{
			add(j,id,e[j].w);
			add(id,j,e[j].w);
		}
	}
	for(i = 1;i <= cnt;i++)
	{
		q.push(edge[i]);
	}
	printf("%lld",prim(n));
	return 0;
}
/*
5 6 0
1 2 1
1 5 2
2 4 7
2 5 4
2 3 3
3 5 6
*/
