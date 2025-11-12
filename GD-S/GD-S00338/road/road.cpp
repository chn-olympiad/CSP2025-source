#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans=1e18;
int fa[10101];
int c[100101];
bool p[100101];
struct node{
	int u,v,w;
	int is;
};
vector<node> b;
int find(int x)
{
	if(fa[x]!=x)
	fa[x]=find(fa[x]);
	return fa[x];
}
void chang(int u,int v)
{
	if(find(u)!=find(v))
	fa[find(u)]=v;
}
void tree()
{
	int nod=1,cnt=0;
	sort(b.begin(),b.end(),[](node x,node y){
		return c[x.is]+x.w<c[y.is]+y.w;
	});
	
	for(int i=1;i<=n;i++)
	fa[i]=i;
	
	for(int i=0;i<(int)b.size();i++)
	{
		if(find(b[i].u)!=find(b[i].v))
		{
			chang(b[i].u,b[i].v);
			cnt+=b[i].w;
			if(!p[b[i].is])
			cnt+=c[b[i].is],p[b[i].is]=1;
		}
	}
	ans=cnt;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		b.push_back({u,v,w,0});
	}
	for(int i=n+1;i<=n+k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%lld",&x);
			b.push_back({j,i,x,i});
		}
	}
	tree();
	printf("%lld",ans);
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
