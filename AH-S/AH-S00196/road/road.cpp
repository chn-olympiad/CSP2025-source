#include<bits/stdc++.h>
using namespace std;
typedef long long ll1;
const int N=1e4+5;
const int M=1e6+5;
const ll1 inf=1e16+7;
int n,m,K;
struct edge{int u,v,w;bool operator <(const edge&o)const{return w<o.w;}}E[M];
int W[N];
vector<edge>E1;
vector<edge>EK[15];
ll1 Ans=inf;
namespace dsu{
	int fa[N],sz[N];
	void init(){for(int i=1;i<=n+K;i++)fa[i]=i,sz[i]=1;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	bool mer(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return 0;
		if(sz[x]<sz[y])swap(x,y);
		fa[y]=x,sz[x]+=sz[y];
		return 1;
	}
}
ll1 tres=0;
vector<edge> merge(const vector<edge>&a,const vector<edge>&b){
	dsu::init();
	vector<edge>e;tres=0;
	for(int u,v,w,i=0,j=0;i<a.size()||j<b.size();){
		if(j==b.size()){
			u=a[i].u,v=a[i].v,w=a[i].w;
			if(dsu::mer(u,v))e.emplace_back(a[i]),tres+=w;
			++i;
			continue;
		}
		if(i==a.size()){
			u=b[j].u,v=b[j].v,w=b[j].w;
			if(dsu::mer(u,v))e.emplace_back(b[j]),tres+=w;
			++j;
			continue;
		}
		if(a[i].w<b[j].w){
			u=a[i].u,v=a[i].v,w=a[i].w;
			if(dsu::mer(u,v))e.emplace_back(a[i]),tres+=w;
			++i;
		}else{
			u=b[j].u,v=b[j].v,w=b[j].w;
			if(dsu::mer(u,v))e.emplace_back(b[j]),tres+=w;
			++j;
		}
	}
	return e;
}
void dfs(int nw,vector<edge>e,ll1 res,ll1 Val){
	Ans=min(Ans,res+Val);
	if(nw>K)return;
	dfs(nw+1,e,res,Val);
	e=merge(e,EK[nw]);
	dfs(nw+1,e,tres,Val+W[nw]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		E[i]=(edge){u,v,w};
	}
	sort(E+1,E+1+m);
	int tot=0;
	Ans=0;dsu::init();
	for(int i=1,u,v,w;i<=m;i++){
		u=E[i].u,v=E[i].v,w=E[i].w;
		if(dsu::mer(u,v))E1.emplace_back(E[i]),Ans+=w;
	}
	for(int u=1;u<=K;u++){
		scanf("%d",&W[u]);
		for(int v=1,w;v<=n;v++){
			scanf("%d",&w);
			EK[u].emplace_back((edge){u+n,v,w});
		}
		sort(EK[u].begin(),EK[u].end());
	}
	dfs(1,E1,Ans,0);
	printf("%lld\n",Ans);
	return 0;
}
//MST
/*
引理 1：原来不出现在 MST 中的边，加入后依然不会出现在 MST 中、
证明：连通性不变
通过归并排序+dsu 即可
O(n(2^k)\alpha(n))
*/