#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e4+5,M=2e6+5,inf=1e16;
int n,m,k,res=inf,nres,tot;
int cost[20],fa[N],used;
bool zext[20],zff,f;

struct Edge{
	int u,v,w,bel;
	
	bool operator <(const Edge x)const{
		return w<x.w;
	}
}e[M];

int find(int u){
	return u==fa[u]?u:find(fa[u]);
}

void kruskal(int now){
	int ncnt=0;
	for(int i=1;i<=n+used;i++)fa[i]=i;
	for(int i=1,fu,fv;i<=tot;i++){
		if(e[i].bel&&(now&(1<<(e[i].bel-1)))==0)continue;
		fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			fa[fu]=fv;
			nres+=e[i].w;
			ncnt++;
			if(ncnt>=n+used)break;
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	tot=m;
	
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		if(cost[i]!=0)zff=1; 
		for(int j=1;j<=n;j++){
			e[++tot].u=n+i;
			e[tot].v=j;
			cin>>e[tot].w;
			e[tot].bel=i;
			if(e[tot].w==0)zext[i]=1;
		}
	}
	sort(e+1,e+tot+1);
	f=!zff;
	for(int i=1;i<=k&&f;i++){
		if(!zext[i])f=0;
	}
	if(f){
		used=k;
		kruskal((1<<k)-1);
		cout<<nres<<'\n';
		return 0;
	}
	for(int i=0;i<1<<k;i++){
		nres=used=0;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				nres+=cost[j+1];
				used++;
			}
		}
		kruskal(i); 
		res=min(res,nres); 
	}
	
	cout<<nres<<'\n';
	return 0;
} 
