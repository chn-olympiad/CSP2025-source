#include<bits/stdc++.h>
#define int long long
using namespace std;const int N=1e7+5,inf=1e18;
int n,m,k,ya[520],ck[520],cuse[520],cy[520],ans=inf,f[N];
struct Edge{int u,v,w;}e[N];
int find(int x){return x==f[x]?f[x]:f[x]=find(f[x]);}
void Kruskal(int yc){
	int sum=0;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=k;i++)ya[i]=cy[i]=0,sum+=ck[i];
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v))continue;
		if(e[i].u>n and e[i].u!=yc and !cuse[e[i].u-n])continue;
		f[find(e[i].u)]=find(e[i].v),sum+=e[i].w;
		if(e[i].u>n)ya[e[i].u-n]++,cy[e[i].u-n]+=e[i].w;
	}
	for(int i=1;i<=k;i++)if(ya[i]<2)sum-=ck[i]+cy[i];
	if(ans>=sum)cuse[yc-n]=1,ans=sum;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>k;for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){cin>>ck[i];for(int j=1,w;j<=n;j++){cin>>w;e[++m]={n+i,j,w};}}
	sort(e+1,e+1+m,[](Edge e1,Edge e2){return e1.w<e2.w;});
	for(int i=0;i<=k;i++)Kruskal(n+i);
	cout<<ans;
	return 0;
}