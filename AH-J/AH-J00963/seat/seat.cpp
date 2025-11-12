#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,cnt=1,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i>1&&a[i]>a[1]) cnt++;
	}
	y=cnt/n+(cnt%n>0);
	if(y%2){
		x=cnt%n;
		if(x==0) x=n;
	}else{
		x=n-cnt%n+1;
		if(x==n+1) x=1;
	}
	printf("%d %d",y,x);
	return 0;
}
