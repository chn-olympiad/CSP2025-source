#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct edge{
	int u,v,w;
}; 
int n,m,k;
edge e[1000000+23];
int c[10+23];
int a[10+23][10000+23];
int fa[10000+23];
int ans;
bool check(){
	for(int i=1;i<=k;i++){
		if(c[i]!=0)	return false;
		for(int j=1;j<=n;j++)
			if(a[i][j]!=0)	return false;
	}
	return true;
} 
int find(int x){
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
bool cmp(edge X,edge Y){
	return X.w<Y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)	cin>>a[i][j];
	}
	if(check()){
		cout<<0;
		return 0;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			merge(e[i].u,e[i].v);
		}
	}
	cout<<ans;
	return 0;
}
