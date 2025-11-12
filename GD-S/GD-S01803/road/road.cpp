#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e4+5,M=1e7+5;
int n,m,k,fa[N],c[15][N];
ll w,sum,l[N][N];
struct node{int u,v;ll w;}t[M];
int find(int x){return fa[x]!=x?fa[x]=find(fa[x]):x;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	memset(l,0x3f,sizeof l);
	cin>>n>>m>>k;
	iota(fa+1,fa+1+n,1);
	for(int i=1;i<=m;++i) cin>>t[i].u>>t[i].v>>t[i].w,l[t[i].u][t[i].v]=t[i].w,l[t[i].v][t[i].u]=t[i].w;
	for(int i=1;i<=k;++i) for(int j=0;j<=n;++j) cin>>c[i][j];
	
	for(int i=1;i<=k;++i) 
		for(int j=1;j<=n;++j)
			for(int z=i+1;z<=n;++z){
				ll ss=c[i][j]*1ll+c[i][z]+c[i][0];
				if(l[j][z]>ss&&l[z][j]>ss) m++,t[m]={j,z,ss},l[j][z]=l[z][j]=ss;
			}
	sort(t+1,t+1+m,[](node q,node ww){return q.w<ww.w;});
	for(int i=1;i<=m;++i){
		int x=find(t[i].u),y=find(t[i].v); 
		if(x!=y) fa[y]=x,sum+=t[i].w;
	}
	cout<<sum<<'\n';
}
