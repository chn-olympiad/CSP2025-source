#include <bits/stdc++.h>
using namespace std;
int n,m;
struct c1{
	int cj,id;
}a[105];
bool cmp(c1 a1,c1 a2){
	return a1.cj>a2.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i){
		scanf("%d",&a[i].cj);
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int i=0;
	while(a[++i].id!=1);
	printf("%d ",(i+n-1)/n);
	if(((i+n-1)/n)&1){
		printf("%d\n",(i-1)%n+1);
	}else printf("%d\n",n-(i-1)%n);
	return 0;
}
