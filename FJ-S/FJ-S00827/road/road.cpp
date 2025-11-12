#include<bits/stdc++.h>
using namespace std;
using lld = long long;
const lld siz = 1e5+5;
const lld mod = 1e9+7;
using pll = pair<lld,lld>;

struct edge
{
	lld u,v,w;
}es[siz];
lld f[siz],a[siz];
lld n,m,k,ans;
lld anc(lld now)
{
	if(f[now] == now)
		return now;
	f[now] = anc(now);
	return f[now];
}
void cob(lld x,lld y)
{ f[anc(y)] = anc(x); }
bool same(lld x,lld y)
{ return anc(x) == anc(y); }
bool cmp(edge x,edge y)
{ return x.w<y.w; }
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		f[i] = i;
	for(int i=1;i<=m;i++)
		scanf("%lld %lld %lld",&es[i].u,&es[i].v,&es[i].w);
	sort(es+1,es+n+1,cmp);
	lld cho = 0,now = 1;
	while(cho<n-1)
	{
		lld u = es[now].u,v = es[now].v,w = es[now].w;
		if(!same(u,v))
		{
			cob(u,v); ans+=w; cho++;
		}
		now++;
	}
	printf("%lld",ans);
	return 0;
}
/*
6 8 0
1 6 3
1 2 4
2 6 3
2 5 5
1 4 2
2 3 2
3 5 1
4 5 4
*/
