#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
struct nd{
	int u,v,w;
}road[M];
int fa[N];
bool cmp(nd x,nd y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x];
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&road[i].u,&road[i].v,&road[i].w);
	}
	int c;
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&c);
		}
	}
	sort(road+1,road+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int u=road[i].u,v=road[i].v,w=road[i].w;
		int uf=find(u),vf=find(v);
		if(uf==vf) continue;
		ans+=w;
		fa[u]=v;
	}
	cout<<ans;
	return 0;
}
