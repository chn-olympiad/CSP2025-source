#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,k;
typedef struct{
	int to;
	int cost;
}Edge;
//int top[10005],next1[2000005],cnt=0;
//Edge edge[2000005];
/*void add(int u,int v,int w){
	next1[++cnt]=top[u];
	edge[cnt].to=v;
	edge[cnt].cost=w;
	top[u]=cnt;
}*/
struct node{
	int u,v,w;
	friend bool operator<(node n1,node n2){
		return n1.w<n2.w;
	}
}e[2000005];
int nk[12][10005],f[10005];
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	int u,v,w,cnte=0;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
//		add(u,v,w);
//		add(v,u,w);
		e[++cnte].u=u;
		e[cnte].v=v;
		e[cnte].w=w;
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=k;i++){
		scanf("%d",&nk[i][0]);
		int o[10005]={0};
		for(int j=1;j<=n;j++){
			scanf("%d",&nk[i][j]);
			if(nk[i][j]==0)o[++o[0]]=j;
		}
		for(int j=1;j<=o[0];j++){
			for(int y=1;y<=n;y++){
				if(o[j]==y)continue;
				e[++cnte].u=o[j];
				e[cnte].v=y;
				e[cnte].w=nk[i][y];
			}
		}
	}
	sort(e+1,e+1+cnte);
	long long ans=0;
	for(int i=1;i<=cnte;i++){
		int u1=find(e[i].u),v1=find(e[i].v);
		if(u1!=v1){
			ans+=e[i].w;
			f[u1]=v1;
		}
	}
	printf("%lld",ans);
	return 0;
}