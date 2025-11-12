#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}road[6000001];
int vil,xui,mid[10001];
int n,m,k,fa[6000001],ans,tot;
int find(int x){
	if(x!=fa[x])return fa[x]=find(fa[x]);
	return x;
} 
bool cmp(node a,node b){
	return a.w<b.w;
}
void kl(int t){
	for(int i=1;i<=tot;i++){
		fa[i]=i;
	}
	sort(road+1,road+t+1,cmp);
	for(int i=1;i<=t;i++){
		int u=find(road[i].u);
		int v=find(road[i].v);
		if(u==v)continue;
		ans+=road[i].w;
		fa[v]=road[i].u;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&road[i].u,&road[i].v,&road[i].w);
	}
	tot=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&xui);
		for(int j=1;j<=n;j++){
			scanf("%d",&mid[j]);
		}
		for(int x=1;x<=n;x++){
			for(int y=x+1;y<=n;y++){
				tot++;
				road[tot].u=x;
				road[tot].v=y;
				road[tot].w=mid[x]+mid[y]+xui;	
			}
		}
	}
	kl(tot);
	printf("%d",ans);
}
