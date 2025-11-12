#include<bits/stdc++.h>
using namespace std;
struct vip{
	int a1,a2,a3;
}a[15][100005];
int n,x,k,t,b;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		b=0;
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",&a[i][j].a1,&a[i][j].a2,&a[i][j].a3);
			b+=max(a[i][j].a1,max(a[i][j].a2,a[i][j].a3));
		}
		printf("%d\n",b);
	}
	return 0;
}
