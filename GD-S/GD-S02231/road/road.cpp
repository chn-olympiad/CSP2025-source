#include<bits/stdc++.h>
using namespace std;
#define fio(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define tio() freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define cio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using ll=long long;
using pii=pair<int,int>;
const int N=1e4+10,M=1e6+10; 
int n,m,k;
struct edge{
	int u,v,w;
}e[M*6];
struct dsu{
	int fa[N];
	int siz[N];
	void init(int n){
		for(int i=1;i<=n;++i)fa[i]=i;
	}
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	bool mer(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return 0;
		if(siz[x]>siz[y])swap(x,y);
		fa[x]=y;
		return 1;
	}
}s;
int c[11],a[11][N];
int main(){
	fio("road");
	cio();
	cin>>n>>m>>k;
	if(k==0){
		ll ans=0;
		for(int i=1;i<=m;++i){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		s.init(n);
		sort(e+1,e+1+m,[](edge a,edge b)->bool{return a.w<b.w;});
		for(int i=1;i<=m;++i){
			if(s.mer(e[i].u,e[i].v))ans+=e[i].w;
		}
		cout<<ans;
		return 0;
	}
	if(n<=1e3&&k<=5){
		ll ans=0;
		int cnt=m;
		for(int i=1;i<=m;++i){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		for(int i=1;i<=k;++i){
			cin>>c[i];
			for(int j=1;j<=n;++j){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int p=1;p<=k;++p){
					e[++cnt]={i,j,a[p][i]+a[p][j]+c[p]};
				}
			}
		}
		s.init(n);
		sort(e+1,e+1+cnt,[](edge a,edge b)->bool{return a.w<b.w;});
		for(int i=1;i<=cnt;++i){
			if(s.mer(e[i].u,e[i].v))ans+=e[i].w;
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
