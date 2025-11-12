#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,V=N*12,M=1e6+5;
#define pb push_back
#define ll long long
struct edge{int u,v,id;ll w;}e[M],q[V],E[V];
int f[N];ll c[N],v[15][N],tot;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout);
	int n,m,k;ll ans=0,s=0;cin>>n>>m>>k; 
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w,e[i].id=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>v[i][j];
	}
	sort(e+1,e+1+m,[](edge x,edge y){return x.w<y.w;});
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
		if(find(e[i].u)^find(e[i].v))
			f[find(e[i].u)]=find(e[i].v),s+=e[i].w,q[++tot]=e[i];
	ans=s;
	for(int i=1;i<(1<<k);i++){
		s=0;int t=tot;
		for(int j=1;j<=tot;j++)E[j]=q[j];
		for(int j=1;j<=k;j++)
			if(i&(1<<j-1)){
				s+=c[j];
				for(int p=1;p<=n;p++)
					E[++t]=edge{j+n,p,0,v[j][p]};
			}
		for(int j=1;j<=n+k;j++)f[j]=j;
		sort(E+1,E+1+t,[](edge x,edge y){return x.w<y.w;});
		for(int j=1;j<=t;j++)
			if(find(E[j].u)^find(E[j].v))
				f[find(E[j].u)]=find(E[j].v),s+=E[j].w;
		ans=min(ans,s);
	}
	cout<<ans;
	return 0;
} 
