#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
struct node {
	int a,id;
} nod[144];
int n,m;
bool cmp(node a,node b) {
	return a.a>b.a;
}
void dfs(int i,int x,int y,int dn,bool isb) {
	if(nod[i].id==1) {
		printf("%d %d",y,x);
		return;
	}
	if((x==n||x==1)&&!isb)dfs(i+1,x,y+1,-dn,1);
	else dfs(i+1,x+dn,y,dn,0);
}
int main() {
	freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++)
		scanf("%d",&nod[i].a),nod[i].id=i;
	std::sort(nod+1,nod+n*m+1,cmp);
	dfs(1,1,1,1,1);
	return 0;
}
