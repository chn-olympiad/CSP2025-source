#include<bits/stdc++.h>
using namespace std;

int tot=0,head[1000005<<1];

struct edge{
	int v,nex,w;
	int u;
}e[1000005<<1];

void add(int u,int v,int w){
	e[++tot]={v,head[u],w,u};
	head[u]=tot;
}

bool cmp(edge a,edge b){
	return a.w<b.w;
}

int n,m,k;
int u,v,w;
int ans=0;
int c[15],a[15][10005];

int pre[10005];

int find(int u){
	return pre[u]==u? u: pre[u]=find(pre[u]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++){
		pre[i]=i;
	}
	
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	sort(e+1,e+1+m,cmp);
	
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			if(pre[e[i].v]!=e[i].v){
				pre[e[i].u]=find(e[i].v);
			}else{
				pre[e[i].v]=find(e[i].u);
			} 
		}
	} 
	
	cout<<ans<<'\n';
	
	return 0;
}
