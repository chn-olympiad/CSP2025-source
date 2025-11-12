#include<stdio.h>
#include<algorithm>
int n,m,s,i,f,a[101],c;
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	s=n*m;
	for(i=0;i^s;++i)scanf("%d",a+i);
	f=*a;
	std::sort(a,a+s,cmp);
	for(i=0;a[i]^f;++i);
	c=i/n+1,i%=n;
	printf("%d %d",c,c&1?i+1:n-i);
	return 0;
}
