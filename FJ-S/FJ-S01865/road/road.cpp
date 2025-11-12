#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int n,m,k;
int fa[1000010];
int wc[20],wa[11][20000];

void init(){
	for(int i=0;i<=n*(k+1);i++)fa[i]=i;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int a,int b){
	fa[find(a)]=find(b);
}

struct Ed{
	int u,v,w;
	bool operator<(const Ed &x){
		return w<x.w;
	}
}e[10000010];
int ptr=0;
int kruskal(){
	sort(e,e+ptr);
	init();
	int cnt=0,res=0;
	for(int i=0;i<ptr;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			merge(u,v);cnt++;res+=w;
		}
		//if(cnt>=n-1)break;
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[ptr++]={u,v,w};
//		for(int j=1;j<=k;j++){
//			e[ptr++]={j*n+u,j*n+v,w};//k+1-multilayer graph
//		}
	}
	for(int i=1;i<=k;i++){
		cin>>wc[i];
		for(int j=1;j<=n;j++){
			cin>>wa[i][j];
		}
	}
	long long mi=(long long)1e17;
	int minit=ptr;
	for(unsigned long long st=0;st<(1ull<<k);st++){
		ptr=minit;
		
		for(int i=1;i<=k;i++){
			if(st&(1<<(i-1))){
				for(int j=1;j<=n;j++){
					e[ptr++]={0,j,wa[i][j]};
				}
			}
		}
		int csum=0;
		for(int i=0;i<k;i++)if(st&(1<<i))csum+=wc[i+1];
		
		mi=min(mi,kruskal()+csum);
	}
	cout<<mi;
	return 0;
}
