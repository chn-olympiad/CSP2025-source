#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}g[5000010];
int n,m,k,len,fa[10010],country[15][10010];
long long ans;
bool cmp(node a,node b){
	return a.w<b.w;
}
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x);
	y=get(y);
	if(x!=y){
		fa[y]=x;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[++len]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>country[i][0];
		for(int j=1;j<=n;j++){
			cin>>country[i][j];
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				g[++len]={j,k,country[i][j]+country[i][k]};
			}
		}
		
	}
	sort(g+1,g+1+len,cmp);
	for(int i=1;i<=len;i++){
		if(get(g[i].u)!=get(g[i].v)){
			ans+=g[i].w;
			merge(g[i].u,g[i].v);
		}
	}
	cout<<ans;
	return 0;
}
