#include<bits/stdc++.h>
using namespace std;
const int M=1e7,N=1e4;
int u[M],v[M],w[M];
int head[N*4],tot,to[N*4],nxt[N*4];
int c[N];
int a[101010][10];
void add(int x,int y,int z){
	tot++;
	nxt[tot]=head[x];
	to[tot]=y;
	head[x]=tot;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		add(u[i],v[i],w[i]);
	}
	int cnt=0;
	bool flag=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0) flag=1;
			add(++cnt,j,a[i][j]);
		}
	}
	if(!flag){
		puts("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
