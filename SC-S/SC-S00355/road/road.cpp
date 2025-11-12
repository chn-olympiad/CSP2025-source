#include <bits/stdc++.h>
using namespace std;
const int M = 5e6+3,N = 1e5+2,K = 12;
int n,m,k,cnt;
long long ans;
struct edge{
	int u,v,w;
}e[M];
int c[N][12];
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[M];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
long long kru(){
	long long res=0;
	for(int i=1;i<=n;++i) fa[i]=i;
	stable_sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			fa[fu]=fv;
			res+=e[i].w;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	cnt=m;
	ans=kru();
	int cc=n;
	for(int i=1;i<=k;++i){
		++cc;
		int id=0;
		for(int j=0;j<=n;++j) {
			cin>>c[i][j];
			if(!c[i][j]) id=j;
		}
		for(int j=1;j<=n;++j){
			e[++cnt]={id,j,c[i][j]};
		}
	}
	ans=min(ans,kru());
	cout<<ans<<"\n";                                                      
	return 0;
}
/*
	 
*/