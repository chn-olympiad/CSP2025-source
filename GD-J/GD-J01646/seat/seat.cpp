#include<bits/stdc++.h>
using namespace std;
int n,m,x,mark,dnum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&mark);
	for(int i=2;i<=n*m;++i){
		scanf("%d",&x);
		if(x>mark)dnum++;
	}
	if((dnum/n)%2==0){
		printf("%d %d",dnum/n+1,dnum+1-(dnum/n)*n);
	}
	else {
		printf("%d %d",dnum/n+1,(dnum/n+1)*n-dnum);
	}
	return 0;
}
