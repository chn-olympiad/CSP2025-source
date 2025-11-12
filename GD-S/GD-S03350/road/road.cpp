#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int M=1e6+5;
const int N=1e4+5;

struct node_edge{
	int u,v,w,nxt;
};

node_edge a[M*2];

int ha[N],tot;

void build(int x,int y,int z){
	tot++;
	a[tot].u=x;
	a[tot].v=y;
	a[tot].w=z;
	a[tot].nxt=ha[x];
	ha[x]=tot;
}

int c[N][N],fa[N],n,m,k;

long long ans;

int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}

void find(int x,int y){
	int cnt=0x7ffffff;
	for(int i=1;i<=n;i++){
		if(get(i)==x){
			for(int j=ha[i];j;j=a[j].nxt){
				int z=a[j].v;
				if(get(z)==y){
					cnt=min(cnt,a[j].w);
				}else{
					continue;
				}
			}
			for(int j=1;j<=k;j++){
				if(c[j][i]==0){
					for(int l=1;l<=n;l++){
						if(get(l)==y){
							cnt=min(cnt,c[j][l]);
						}
					}
				}
			} 
		}else{
			continue;
		}
	}
	ans=ans+(long long)cnt;
}

bool cmp(node_edge k1,node_edge k2){
	return k1.w<k2.w;
}

void pianf(){
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	
	sort(a+1,a+m+1,cmp);
	
	for(int i=1;i<=m;i++){
		int x,y;
		x=get(a[i].u);
		y=get(a[i].v);
		if(x==y)continue;
		ans=ans+(long long)a[i].w;
		fa[x]=y;
	}
	
	printf("%lld",ans);
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	bool f_a=true;
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	
	if(k==0){ 
		pianf();
		return 0;
	}
	
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		build(u,v,w);
		build(v,u,w);
	}
	
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	
	for(int i=1;i<=k;i++){
		if(c[i][0]==0){
			for(int j=1;j<=n;j++){
				if(c[i][j]==0){
					int x,y;
					x=get(i);y=get(j);
					fa[x]=y;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x,y;
			x=get(i);y=get(j);
			if(x==y)continue;
			find(x,y);
			fa[x]=y;
		}
	}
	
	printf("%lld",ans);
	
	return 0;
}
/*
 4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
