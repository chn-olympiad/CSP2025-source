#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1;i<n*m;++i){
		scanf("%d",&b);
		if(b>a)
			++cnt;
	}
	if((int)ceil(1.0*cnt/n)%2==1){
		if(cnt%n==0)
			printf("%d %d",cnt/n,n);
		else printf("%d %d",(int)ceil(1.0*cnt/n),cnt%n);
	}
	else{
		if(cnt%n==0)
			printf("%d 1",(int)ceil(1.0*cnt/n));
		else printf("%d %d",(int)ceil(1.0*cnt/n),-~n-cnt%n);
	}
	return 0;
}
