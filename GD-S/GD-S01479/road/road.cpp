#include<bits/stdc++.h>
#define x0 x_0
#define x1 x_1
#define y0 y_0
#define y1 y_1
#define yn y_n
#define j0 j_0
#define j1 j_1
#define jn j_n
#define k0 k_0
#define k1 k_1
#define d0 d_0
#define d1 d_1
#define LL long long
#define LD long double
#define Big __int128
#define STR string
#define US unsigned
#define ZPB push_back
#define ZPF push_front
#define PPB pop_back
#define PPF pop_front
#define next NXTNXT
#define UPB upper_bound
#define LWB lower_bound
#define mem(x,val) memset(x,val,sizeof(x))
using namespace std;
int n,m,k,fa[10020],sz[10020],ncnt,c[20],a[20][10020],necnt;
LL ans;
struct Enode{
	int u,v,w;
	bool operator < (const Enode &o)const{return w<o.w;}
}E[1000010],ned[10020],nE[150010],cE[20][10010],cop[150010],cun[20][150010];
int find(int x) {return (fa[x]==x ? x : fa[x]=find(fa[x]));}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v) return ;
	if(sz[u]<=sz[v]) fa[u]=v,sz[v]+=sz[u];
	else fa[v]=u,sz[u]+=sz[v];
	return ;
}
void dfs(int x,LL nans=0,int nd=n){
	if(x==k+1){
//		cerr<<"x="<<x<<" nans="<<nans<<"\n";
		for(int i=1;i<=n+k;++i) fa[i]=i,sz[i]=1;
		int cnt=0;
		for(int i=1;i<=necnt;++i){
//			cerr<<"u="<<nE[i].u<<" v="<<nE[i].v<<" w="<<nE[i].w<<"\n";
			int u=find(nE[i].u),v=find(nE[i].v);
			if(u==v) continue;
			merge(u,v),nans+=nE[i].w,++cnt;
			if(cnt==nd-1) break;
		}
//		cerr<<"result: nans="<<nans<<"\n";
		ans=min(ans,nans);
		return ;
	}
	// not choose
	dfs(x+1,nans,nd);
	// choose
	int ynecnt=necnt;
	for(int i=1;i<=necnt;++i) cun[x][i]=nE[i];
	int zz0=1,zz1=1;
	// zz0: nE
	// zz1: cE
	for(int i=1;i<=necnt+n;++i){
		if(zz0<=necnt && (zz1>n || nE[zz0].w<=cE[x][zz1].w)) cop[i]=nE[zz0],++zz0;
		else cop[i]=cE[x][zz1],++zz1;
	}
	necnt+=n;
	for(int i=1;i<=necnt;++i) nE[i]=cop[i];
	dfs(x+1,nans+c[x],nd+1);
	necnt=ynecnt;
	for(int i=1;i<=necnt;++i) nE[i]=cun[x][i];
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;++i) fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;++i) cin>>E[i].u>>E[i].v>>E[i].w;
	sort(E+1,E+m+1);
//	cerr<<"clock()="<<clock()<<"\n";
	int cnt=0;
	for(int i=1;i<=m;++i){
		int u=find(E[i].u),v=find(E[i].v);
		if(u==v) continue;
		ans+=E[i].w,merge(u,v),nE[++necnt]=E[i],++cnt;
		if(cnt==n-1) break;
	}
//	cerr<<"clock()="<<clock()<<"\n";
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j) cin>>a[i][j],cE[i][j]=(Enode){i+n,j,a[i][j]};
		sort(cE[i]+1,cE[i]+n+1);
	}
	dfs(1);
	cout<<ans<<"\n";
//	cerr<<"clock()="<<clock()<<"\n";
	return 0;
}

/*
input1:

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

output1:

13

*/
