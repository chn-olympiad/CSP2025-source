#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1;i<n*m;i++){
		scanf("%d",&b);
		if(b>a)c++;
	}
	printf("%d ",c/n+1);
	if((c/n)%2==0)printf("%d",c%n+1);
	else printf("%d",n-(c%n));
	return 0;
}
