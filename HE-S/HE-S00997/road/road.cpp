#include<bits/stdc++.h>;
#define N 10004
#define M 1000006
using namespace std;

int n,m,k,c[N];
int hd[N],cnt;
struct tree{
	int v,nxt,w;
}e[1<<M];
struct man{
	int c,a[N];
}tw[12];
void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=hd[u];
	hd[u]=cnt;
}
bool cmp(tree x,tree y){
	return x.w<y.w;
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&tw[i].a);
		for(int j=1;j<=n;j++)
			scanf("%d",&tw[i].a[j]);
	}
	
	sort(e+1,e+m+1,cmp);
	
	
	
	
	
	return 0;
}
















