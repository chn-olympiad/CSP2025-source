#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=10000,M=1000000;
struct edge{
	int u,v,w;
	friend bool operator<(edge a,edge b){return a.w<b.w;}
}E[M+5],e[(N<<4)+5];
int n,m,k,tot;
struct Union{
	int fa[N*2+5];
	void init(){
		memset(fa+1,-1,n*2*sizeof(int));
	}
	int find(int u){return fa[u]<0?u:fa[u]=find(fa[u]);}
	void merge(int u,int v){
		u=find(u);v=find(v);
		if(u==v)return;
		if(fa[u]>fa[v])swap(u,v);
		fa[u]+=fa[v];fa[v]=u;
	}
	bool check(int u,int v){return find(u)!=find(v);}
}B;
int a[15];
bool flag;
long long ans;
long long kruskal(int s){
	int cnt=0,m=n;
	long long res=0;B.init();
	for(int i=1;i<=k;++i)
		if(s>>(i-1)&1)res+=a[i],++m;
	for(int i=1;i<=tot&&cnt<m-1;++i){
		if(e[i].u>n&&!(s>>(e[i].u-n-1)&1))continue;
		if(B.check(e[i].u,e[i].v)){
			B.merge(e[i].u,e[i].v);
			++cnt;
			res+=e[i].w;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;++i)cin>>E[i].u>>E[i].v>>E[i].w;
	sort(E,E+m);B.init();
	for(int i=0;i<m&&tot<n-1;++i)
		if(B.check(E[i].u,E[i].v)){
			B.merge(E[i].u,E[i].v);
			e[++tot]=E[i];
		}
	for(int i=1;i<=k;++i){
		cin>>a[i];
		if(a[i])flag=1;
		for(int j=1;j<=n;++j){
			e[++tot].u=i+n;
			e[tot].v=j;
			cin>>e[tot].w;
			if(e[tot].w)flag=1;
		}
	}
	if(!flag){
		cout<<"0\n";
		return 0;
	}
	sort(e+1,e+tot+1);
	ans=1e18;
	for(int s=0;s<1<<k;++s)ans=min(ans,kruskal(s));
	cout<<ans<<'\n';
	return 0;
}
