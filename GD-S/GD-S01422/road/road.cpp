#include<bits/stdc++.h>
using namespace std;
int n,m,k,d[20005],b[15][20005],c[15],sum;
struct node{
	int u,v,c,bj;
}a[20005];
bool cmp(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].c),d[a[i].u]++,d[a[i].v]++,sum+=a[i].c;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&b[i][j]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++)
		if(d[a[i].u]>1&&d[a[i].v]>1) 
			d[a[i].u]--,d[a[i].v]--,a[i].bj=1,sum-=a[i].c;
	printf("%d",sum);
	return 0;
} 
