#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10,M=1e6+10;
int val[15],sum,fa[N],n,m,k,tot,c[15][N];
bool in[15];
struct edge1{
	int to,val;
};
vector<edge1> a[N];
struct edge2{
	int u,v,w;
} e[M];

bool cmp(edge2 x,edge2 y){
	return x.w<y.w;
}

int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}

void kruskal(){
	int i=1;
	while(i<=n){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(fa[u])==find(fa[v])){
			i++;
			continue;
		}
		int p=0;
		for(int j=1;j<=k;j++){
			if(w>=c[j][u]+c[j][v]+(in[j]?0:val[j])){
				w=c[j][u]+c[j][v]+(in[j]?0:val[j]);
				p=j;
			}
		}
		in[p]=1;
		sum+=w;
		fa[fa[u]]=fa[v];
		i++;
	}
} 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			c[i][j]=w;
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	kruskal();
	cout<<sum;
	return 0;
}
//FJ-S00097
