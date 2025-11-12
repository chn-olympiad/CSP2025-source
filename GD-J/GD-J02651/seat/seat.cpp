#include <iostream>
#include <cstdio>
const int N=1e2+10; 
using namespace std;

int n,m,num,nu,pos,a,b;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&num);
	pos=1;
	for(int i=2;i<=n*m;i++){
		scanf("%d",&nu);
		if(nu>num)pos++;
	}
	a=pos%n==0?pos/n:pos/n+1,b=(pos-1)%n+1;
	if(a&1)printf("%d %d\n",a,b);
	else printf("%d %d\n",a,n-b+1);
	return 0;
}
