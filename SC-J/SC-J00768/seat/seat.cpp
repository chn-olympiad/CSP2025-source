#include<bits/stdc++.h>
using namespace std;
int read(){
	int ret=0,op=1;char in=getchar();
	while(!isdigit(in)){if(in=='-'){op=-1;}in=getchar();}
	while(isdigit(in)){ret=(ret<<3)+(ret<<1)+(in^48);in=getchar();}
	return ret*op;
}
int rk=1,n,m,now;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();now=read();
	for(int i=2;i<=n*m;i+=1){
		int p=read();
		if(p>now)rk+=1;
	}
	int px=(rk-1)/n+1;
	printf("%d ",px);
	if(px%2==1)printf("%d",(rk-1)%n+1);
	else printf("%d",n-(rk-1)%n);
	return 0;
}