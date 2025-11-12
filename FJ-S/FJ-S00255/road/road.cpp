#include<bits/stdc++.h>
using ll=long long;
using namespace std;
/*
想不到如何最小生成树了，先打个k=0的16'吧 
*/

struct Day{
	int u, v, w;
	bool operator <(const Day &x)const 
	{
		return w > x.w;
	} 
};

int fa[10004], r[15][10004];
priority_queue<Day> q;

int find(int x)
{
	if(fa[x] == x)return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//q.push((Day){1,1,1});q.push((Day){1,1,2});printf("%d\n",q.top().w);
	int n, m, k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i =1;i <= n;i++)fa[i]=i;
	for(int i = 1;i <= m;i++)
	{
		int u, v, w;
		scanf("%d %d %d",&u,&v,&w);
		q.push((Day){u,v,w});
	}
	for(int i =1;i <= k;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			scanf("%d",&r[i][j]);
		}
	}
	ll ans = 0;
	while(!q.empty())
	{
		Day p = q.top();q.pop();
		int fu = find(p.u), fv = find(p.v);
		if(fu == fv)continue;
		fa[fu] = fv;
		ans += (ll)p.w;
	}
	printf("%lld\n",ans);
	return 0;
} 
