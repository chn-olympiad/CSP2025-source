#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,fa[N<<1],tot;
long long c[N],sum;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct edge{
	int u,v;
	long long w;
	bool operator < (const edge &a) const{
		return w<a.w;
	}
};
edge e[M],g[M];
long long ans,a[15][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v);
			ans+=e[i].w;
		} 
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
		for(int i=0;i<1<<k;i++){
			for(int j=1;j<=m;j++) g[j]=e[j];
			for(int j=1;j<=n+k;j++) fa[j]=j;
			tot=0,sum=0;
			for(int j=0;j<k;j++){
				if(i&(1<<j)){
					sum+=c[j+1];
					for(int f=1;f<=n;f++) g[++tot]={n+j+1,f,a[j+1][f]};
				}
			}
			sort(g+1,g+tot+1);
			int pos=0,len=0;
			while(pos<m||len<tot){
				edge x;
				if(pos>=m) x=g[++len];
				else if(len>=tot) x=e[++pos];
				else if(e[pos+1].w<=g[len+1].w) x=e[++pos];
				else if(e[pos+1].w>g[len+1].w) x=g[++len];
				int fx=find(x.u),fy=find(x.v);
				if(fx!=fy){
					fa[fx]=fy;
					sum+=x.w;
				}
			}
			ans=min(ans,sum);
		} 
		cout<<ans;
	return 0;
}
