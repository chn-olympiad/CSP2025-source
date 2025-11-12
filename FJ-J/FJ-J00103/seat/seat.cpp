#include<bits/stdc++.h>
using namespace std;

const int N=15;

struct node{
	int id,w;
}a[N];

int n,m,c,r;

bool cmp(node x,node y){
	return x.w>y.w;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].w);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id!=1)continue;
		c=(i%n==0?i/n:i/n+1);
		
		r=i-((c-1)*n);
		r=(c%2==0?n-r+1:r);
		
		printf("%d %d",c,r);
		break;
	}
	return 0;
}
