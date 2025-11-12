#include<bits/stdc++.h>
using namespace std;
typedef long long ljl;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k,fa[N+K],cnt_e;
ljl a[K][N],c[K],ans;
struct E{
	int u,v;
	ljl w;
	bool operator < (const E &x)const{
		return w<x.w;
	}
}e[M*5];
int findfa(int x)
{
	if(fa[x]==x)return x;
	fa[x]=findfa(fa[x]);
	return fa[x];
}
void Union(int x,int y)
{
	int fx=findfa(x),fy=findfa(y);
	if(fx==fy)return;
	fa[fx]=fy;
	return;
}
void kruskal()
{
	sort(e+1,e+cnt_e+1);int cnt=0;
	for(int i=1;i<=cnt_e;++i)
	{
		int u=e[i].u,v=e[i].v;ljl w=e[i].w;
		if(findfa(u)==findfa(v))continue;
		ans+=w;
		Union(u,v);++cnt;
		if(cnt>=n+k-1)break;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
		cin>>e[i].u>>e[i].v>>e[i].w;
	cnt_e=m;
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
		for(int j=1;j<=n;++j)
		{
			e[++cnt_e].u=n+i;
			e[cnt_e].v=j;
			e[cnt_e].w=a[i][j];
		}
	}
	kruskal();
	return 0;
}

