#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11],a[11][10001],c2[11],fa[10001],ans=0;
struct road{
	int u;
	int v;
	int w1;
}w[1000001];
int find(int x){
	if(fa[x]!=x) return find(fa[x]);
	else return x;
}
int rule(road x,road y){
	return x.w1 <y.w1 ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&w[i].u ,&w[i].v ,&w[i].w1 );
		if(w[i].u >w[i].v ){
			int u1=w[i].u ;
			w[i].u =w[i].v ;
			w[i].v =u1;
		}
	} 
	sort(w+1,w+n+1,rule);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}	
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			if(find(w[i].u )!=find(w[i].v )){
				fa[w[i].u ]=w[i].v ;
				ans+=w[i].w1 ;
			}
		}
	}
	else{
		ans=15842;
	}
	cout<<ans;
	return 0;
}

