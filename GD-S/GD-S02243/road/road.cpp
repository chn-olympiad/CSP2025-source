#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,c[15],f[11000],tmp[15];
struct edge{
	int u,v,w;
	bool operator <(edge &x) const{
		return w<x.w;
	}
}e[1000005],ed[15][10005];
int find(int x){
	return f[x]^x?f[x]=find(f[x]):x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,x;j<=n;j++) cin>>x,ed[i][j]={n+i,j,x};
		sort(ed[i]+1,ed[i]+n+1);
	}
	ll ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)^find(v)) ans+=w,f[find(u)]=find(v),ed[0][++cnt]=e[i];
	}
	for(int i=2;i<(1<<k+1);i+=2){
		vector<int> vc={0};
		for(int j=1;j<=k;j++)
			if(i>>j&1)
				vc.push_back(j);
		for(int j=0;j<=k;j++) tmp[j]=0;
		int nn=n-1+vc.size();
		for(int j=1;j<=n+k;j++) f[j]=j;
		ll now=0;
		for(int j:vc) now+=c[j];
		for(int ne=0;now<ans&&ne<nn-1;){
			edge nw={1,1,INT_MAX};
			int bl=-1; 
			for(int j:vc)
				if(tmp[j]<n&&ed[j][tmp[j]+1].w<nw.w)
					nw=ed[j][tmp[j]+1],bl=j;
			int u=nw.u,v=nw.v,w=nw.w;
			tmp[bl]++;
			if(find(u)^find(v)) f[find(u)]=find(v),ne++,now+=w;
		} 
		ans=min(ans,now);
	}
	cout<<ans<<'\n';
	return 0;
}
