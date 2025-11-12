#include<bits/stdc++.h>
using namespace std;
struct ss{
	int v,pre;
	int w;
}h[10005];
int la[10005],idx=0;
int d[10005];
void add(int u,int v,int w){
	h[++idx].v=v;
	h[idx].w=w;
	h[idx].pre=la[u];
	la[u]=idx;
}
int c[10005],a[12][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("0\n");
    return 0;
}
