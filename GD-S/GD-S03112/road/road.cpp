#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1.5e7;
int n,m,k,a[N],f[N];
ll ans;
struct node{
	int u,v;
	ll w;
}e[M];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void kruskal()
{
	for(int i=1; i<=n; i++)f[i]=i;
	sort(e+1,e+m+1,[](node a,node b){return a.w<b.w;});
	for(int i=1; i<=m; i++)
	{
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y)ans+=e[i].w,f[x]=y;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1; i<=k; i++)
	{
		int x;
		cin>>x;
		for(int j=1; j<=n; j++)cin>>a[j];
		for(int j=1; j<=n; j++)
			for(int l=1; l<=n; l++)
				if(j!=l)e[++m]={j,l,0ll+a[j]+a[l]+x};
	}
	kruskal();
	cout<<ans;
	return 0;
}
