#include<bits/stdc++.h>
using namespace std;

struct c1{
	int u,v,w;
};
struct c2{
	int c,a1,a2,a3,a4;
};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	scanf("%d %d %d",&n,&m,&k);
	c1 a[n];
	c2 b[k];
	for(int i=0;i<=n-1;i++){
		scanf("%d %d %d",a[i].u,a[i].v,a[i].w);
	}
	for(int i=0;i<=k-1;i++){
		scanf("%d %d %d %d %d",b[i].c,b[i].a1,b[i].a2,b[i].a3,b[i].a4);
	}
	
	printf("%d",sum);
	
	return 0;
} 
