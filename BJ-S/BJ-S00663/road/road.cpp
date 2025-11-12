#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[10005];
struct node{
	int x,y,w;
}edge[1000005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(x);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>edge[i].x>>edge[i].y>>edge[i].w;
	}
	for(int i=1;i<=k;i++){
		int v;
		cin>>v;
		for(int j=1;j<=n-1;j++){
			if(j!=i){
				edge[++m].x=i;edge[m].y=j;cin>>edge[m].w;
			}
		}
	}
	sort(edge+1,edge+1+m,cmp);
	long long ans=0;
	for(int i=1;i<=n-1;i++){
		if(find(edge[i].x)!=find(edge[i].y)){
			merge(edge[i].x,edge[i].y);
			ans+=edge[i].w;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
