#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e4+15,M=1e6+15,K=15;

struct edge{
	int u,v,w;
	bool operator <(const edge& x)const{
		return w<x.w;
	}
}e[M*2];

int n,m,k,c[N],f[N],res,cn,ans=1e18;

int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}

void merge(int x,int y){
	int a=find(x),b=find(y);
	if(a!=b)f[a]=b;
}

void kruskal(int x){
	int num=1;
	for(int i=1;i<=m;++i){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(u>n&&!(x&(1<<u-n-1)))continue;
		//cout<<u<<" "<<v<<" "<<w<<"\n";
		if(find(u)!=find(v)){
			res+=w;
			merge(u,v);
			++num;
		}
		if(num==cn)break;
	}
}

signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;++i){
		cin>>c[i+n];
		for(int j=1;j<=n;++j){
			int x;
			cin>>x;
			e[++m]={i+n,j,x};
		}
	}
	sort(e+1,e+m+1);
	for(int i=0;i<(1<<k);++i){
		res=0;
		cn=n;
		for(int j=1;j<=k;++j)
			if(i&(1<<j-1))res+=c[j+n],++cn;
		iota(f+1,f+n+k+1,1);
		//cout<<i<<" "<<res<<"\n";
		kruskal(i);
		ans=min(ans,res);
	}
	cout<<ans; 
}
