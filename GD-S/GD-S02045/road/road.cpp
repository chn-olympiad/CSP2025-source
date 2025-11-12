#include <bits/stdc++.h>
using namespace std;
struct node{
	int cheng1;
	int cheng2;
	int money;
}a[10005];
int cmp(node x,node y){ return x.money<y.money; }
int n,m,k;
double z;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].cheng1,&a[i].cheng2,&a[i].money);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=5;j++){
			scanf("%d",&z);
		}
	}
	z=0;
//	printf("\n");
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++){
//		printf("%d %d %d\n",a[i].cheng1,a[i].cheng2,a[i].money);
//	}
	for(int i=1;i<n;i++){
		z+=a[i].money;
	}
	printf("%.0lf",z);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
