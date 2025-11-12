#include<bits/stdc++.h>
using namespace std;
int N,M,K,ans;
int acrs[10010][10010];
int fa[10010],c[15],a[10010];
bool vis[15];
struct node{
	int v,u,w,id=0;
	bool flag=0;
}side[1000010];
void init(){
	for(int i=1;i<=10000;i++)
		fa[i]=i;
	return ;
}
int find_root(int x){
	if(fa[x]==x) return x;
	return find_root(fa[x]);
}
int join(int x,int y){
	int rx=find_root(x);
	int ry=find_root(y);
	if(rx!=ry){
		fa[ry]=rx;
		return 1;
	}
	return 0;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void Kruskal1(){
	sort(side+1,side+1+M,cmp);
	for(int i=1;i<=M;i++)
		if(join(side[i].v,side[i].u))
			ans+=side[i].w;
}
void Kruskal(){
	sort(side+1,side+1+M,cmp);
	for(int i=1;i<=M;i++){
		if(side[i].id==0){
			if(join(side[i].v,side[i].u))
				ans+=side[i].w;
			}
		else{
			if(join(side[i].v,side[i].u)){
				ans+=side[i].w;
				if(vis[side[i].id]) 
					ans-=c[side[i].id];
				for(int j=i+1;j<=M;j++)
					if(side[j].id==side[i].id)
						side[j].w-=c[side[i].id];
				sort(side+1,side+1+M,cmp);
				vis[side[i].id]=true;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(acrs,0x3f3f3f3f,sizeof(acrs));
	init();
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=M;i++)
		scanf("%d%d%d",&side[i].v,&side[i].u,&side[i].w);
	bool flag=true;
	for(int i=1;i<=K;i++){
		scanf("%d",&c[i]);
		if(c[i]) flag=false;
		for(int j=1;j<=N;j++)
			scanf("%d",&a[j]);
		for(int j=1;j<=N;j++)
			for(int d=1;d<=N;d++)
				if(j!=d){
					side[++M].v=j,side[M].u=d;
					side[M].w=a[j]+a[d]+c[i];
					side[M].flag=true;
					side[M].id=i;
				}
	}
	if(flag)
		Kruskal1();
	else Kruskal();
	printf("%d",ans);
	return 0;
}
