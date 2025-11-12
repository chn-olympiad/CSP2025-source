#include<iostream>
using namespace std;
int n,m,k,tot;
int head[10015];
int dis[10015];
bool flag[10015];
int c[15];
struct edge{
	int v,w,next;
}e[100005];
void addedge(u,v,w){
	tot++;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		head[i]=-1;
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for (int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for (int j=1;j<=n;j++){
			int a;
			scanf("%d",&a);
//			addedge(i,n+i,a);
//			addedge(n+i,i,a);
		}
	}
//	for (int i=1;i<=n;i++){
//		int v=e[i].v,w=e[i].w;
//		for (int j=1;j<=n;j++)
//			dis[j]=1e9;
//		dis[i]=0,flag[i]=1;
//		for (int j=head[i];j!=-1;j=e[i].next){
//				if (dis[i]+x<dis[j])
//					dis[j]=dis[i]+w;
//		}
//		int mini=1e9,minid=0;
//		for (int j=1;j<=n;j++){
//			if (flag[j]==0&&dis[j]<mini){
//				flag[j]=1;
//				minid=j;
//			}
//		}
//	}
	
	return 0;
}
