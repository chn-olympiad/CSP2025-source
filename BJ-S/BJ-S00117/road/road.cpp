#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
typedef long long LL;
const int N=10020,M=1000010,K=15;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &W)const{
		return w<W.w;
	}
}e[K][M],ve[K][N];
int idx[K];
int vc[K];
int n,m,k;
LL res[K],ans=1e18;
int fa[N];
int find(int x){
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(int p,LL vw){
	if(p>k)
		return;
	if(p!=0){
		res[p]=res[p-1];
		idx[p]=idx[p-1];
		for(int i=1;i<=idx[p];++i)
			e[p][i]=e[p-1][i];
		dfs(p+1,vw);
		idx[p]=0;
		int i=1,j=1;
		while(i<=idx[p-1]&&j<=n)
			if(e[p-1][i]<ve[p][j])
				e[p][++idx[p]]=e[p-1][i++];
			else
				e[p][++idx[p]]=ve[p][j++];
		while(i<=idx[p-1])
			e[p][++idx[p]]=e[p-1][i++];
		while(j<=n)
			e[p][++idx[p]]=ve[p][j++];
		vw+=vc[p];
	}
	res[p]=vw;
	for(int i=1;i<=n+k;++i)
		fa[i]=i;
	int nidx=0;
	for(int i=1;i<=idx[p];++i){
		int a=find(e[p][i].u),b=find(e[p][i].v);
		if(a==b)
			continue;
		fa[b]=a;
		res[p]+=e[p][i].w;
		e[p][++nidx]=e[p][i];
	}
	idx[p]=nidx;
	ans=min(ans,res[p]);
	dfs(p+1,vw);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	idx[0]=m;
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&e[0][i].u,&e[0][i].v,&e[0][i].w);
	sort(e[0]+1,e[0]+1+m);
	for(int i=1;i<=k;++i){
		scanf("%d",&vc[i]);
		for(int j=1;j<=n;++j){
			ve[i][j]={n+i,j};
			scanf("%d",&ve[i][j].w);
		}
		sort(ve[i]+1,ve[i]+1+n);
	}
	dfs(0,0);
	printf("%lld",ans);
	return 0;
}