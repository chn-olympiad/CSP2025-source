#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
#define min(a,b) (a>b?a:b)
struct node{
	int u,v;
	long long w;
};vector<node> e;
int n,m,k,fa[N],vis[11],c[11];long long ans;
int find(int x){
	if(x==fa[x]){return x;}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){fa[x]=y;}
bool cmp(node a,node b){return a.w<b.w;}
void kruskal(){
	int fx=0,fy=0,u,v,w;
	for(int i=0;i<e.size();i++){
		u=e[i].u;v=e[i].v;w=e[i].w;
		fx=find(u);fy=find(v);
//		printf("u:%d v:%d w:%d fx:%d fy:%d -->",u,v,w,fx,fy);
		if(fx!=fy){
//			puts("Accept");
			merge(fx,fy);
			ans=ans+w;
			if(u>n && vis[u-n]==1){ans=ans-c[u-n];vis[u-n]=1;}
			if(v>n && vis[v-n]==1){ans=ans-c[v-n];vis[v-n]=1;}
			if(u>n && vis[u-n]==0){vis[u-n]=1;}
			if(v>n && vis[v-n]==0){vis[v-n]=1;}
		}
//		else{puts("Refuse");}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){fa[i]=i;}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		bool f=true;
		for(int j=0;j<e.size();j++){
			if((u==e[j].u && v==e[j].v) || (v==e[j].u && u==e[j].v)){
				e[j].w=min(e[j].w,w);f=false;
				break;
			}
		}
		if(f){e.push_back({u,v,w});}
	}
	bool flagA=true;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)flagA=false;
		for(int j=1;j<=n;j++){
			int a;scanf("%d",&a);
			if(a!=0)flagA=false;
			e.push_back({i+n,j,a+c[i]});//a+c=AC
		}
	}
	if(flagA){putchar('0');return 0;}
	sort(e.begin(),e.end(),cmp);
	kruskal();
	printf("%lld",ans);
	//system("pause");
	return 0;
}
