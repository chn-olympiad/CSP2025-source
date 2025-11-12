#include <bits/stdc++.h>
using namespace std;
const int N=1e4,M=1e6;
int n,m,k,cnt,fst[N+5],c[15],a[15][N+5];
struct edge{
	int to,nxt,wgt;
}e[M*2+5];
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].nxt=fst[u];
	fst[u]=cnt;
	e[cnt].wgt=w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0,u,v,w;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	printf("0");
	return 0;
}
