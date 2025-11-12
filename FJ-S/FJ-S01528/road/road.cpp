#include<bits/stdc++.h>
using namespace std;
const int N=1e5+15,M=1e7+5;
struct node {int pre,to;}e[M];
int n,m,k,head[N],t,u[M],v[M],w[M],cw[20],ans=INT_MAX;
bool b[N];
void add(int u,int v) {
	e[++t].pre=head[u];
	e[t].to=v;
	head[u]=t;
}
bool pd() {
	for(int i=1;i<=n;i++) 
		if(!b[i]) return 0;
	return 1;
}
bool ok(int now) {
	if(pd()) 
		return 1;
	bool f=1;
	for(int i=head[now];i;i=e[i].pre) {
		int to=e[i].to;
		if(!b[to]) f=f&&ok(to);
	}
	return f;
}
void dfs(int c) {
	if(ok(1)) {
		ans=min(ans,c);
		return;
	}
	for(int i=1;i<=m;i++) {
		add(u[i],v[i]);
		dfs(c+w[i]);
		for(int j=1;j<=k;j++) {
			dfs(c+w[i]+cw[i]);
		}
		t--;
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) 
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	for(int i=1;i<=k;i++) {
		scanf("%d",&cw[i]);
		for(int j=1;j<=n;j++)
			u[m+i]=n+i,scanf("%d",&v[m+i]);
	}
	dfs(0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
