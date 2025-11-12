#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,fa[N],cnt=0,cnt1=0,c[15][N],tot,sum=0;
long long kans=0;
bool vis[15],flag[N];
struct node{
	int u,v,w,id;
}e[M*15];
int get_root(int x){
	if(fa[x]!=x)return fa[x]=get_root(fa[x]);
	else return x;
}
void merge(int x,int y){
	fa[y]=get_root(x);
}
void kruskal(){
	for(int i=1;i<=tot;++i){
		int u=e[i].u,v=e[i].v;
		if(get_root(u)!=get_root(v)){
			merge(u,v);
			kans+=1ll*e[i].w;
			cnt++;
		}
		if(cnt==n-1)return;
	}
}
void kruskal1(){
	for(int i=1;i<=tot;++i){
		int u=e[i].u,v=e[i].v;
		if(get_root(u)!=get_root(v)){
//			if(!flag[u])flag[u]=1,cnt1++;
//			if(!flag[v])
			merge(u,v);
//			printf("Link %d %d use %d\n",u,v,e[i].w);
			kans+=1ll*e[i].w;
			if(e[i].id!=0&&vis[e[i].id]==0){
				vis[e[i].id]=1;
				for(int j=1;j<=n;++j){
//					if(c[i][j]==0){
						for(int l=j+1;l<=n;++l){
							if(j!=l){
								tot++;
								e[tot].u=j;
								e[tot].v=l;
								e[tot].w=c[e[i].id][l]+c[e[i].id][j];
							}
						}
//					}
				}
			}
			cnt++;
			
		}
		if(cnt==n)return;
	}
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i][0]);
		for(int j=1;j<=n;++j)scanf("%d",&c[i][j]);
	}
	tot=m;
	if(k==0){
		sort(e+1,e+1+tot,cmp);
		for(int i=1;i<=n;++i)fa[i]=i;
		kruskal();
		printf("%lld",kans);
		return 0;
	}else{
		sum=n;
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<=k;++i){
//			if(c[i][0]==0){
				int tmp=0;
				for(int j=1;j<=n;++j){
//					if(c[i][j]==0){
						for(int l=j+1;l<=n;++l){
							if(j!=l){
								tot++;
								e[tot].u=j;
								e[tot].v=l;
								e[tot].w=c[i][l]+c[i][j]+c[i][0];
								e[tot].id=i;
							}
						}
//					}
				}
		}
//		printf("Tot:%d\n",tot);
		sort(e+1,e+1+tot,cmp);
		kruskal1();
		printf("%lld",kans);
	}
	return 0;
}

