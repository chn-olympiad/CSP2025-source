//GZ-S00055 贵阳市第三实验中学 刘明远 
#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct node{
	int u,v,w;
	bool operator < (const node &c) const{
		return w<c.w;
	}
};
vector<node> edge;
vector<pair<int,int> > con[15];
int fa[10024],siz[10024];
int a[15][10004];

int f(int u)
{
	if(fa[u]==u)
		return u;
	return fa[u]=f(fa[u]);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=n+k;i++)
		fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		edge.push_back({u,v,w});
	}
	for(int j=1;j<=k;j++)
	{
		scanf("%d",&a[j][0]);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[j][i]);
		}
	}
	sort(edge.begin(),edge.end());
	int cnth=n;
	long long ans=0;
	for(auto k:edge)
	{
		u=k.u,v=k.v,w=k.w;
		int fu=f(u),fv=f(v);
		if(fu==fv) continue;
		if(siz[fv]>siz[fu]) swap(fv,fu);
		ans+=w;
		fa[fv]=fu;
		siz[fu]+=siz[fv];
	}
	cout<<ans;
	return 0;
}
