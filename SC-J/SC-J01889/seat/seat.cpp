#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],R,xus,x,y,lie;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	R=a[1];
	sort(a+1,a+n*m+1,greater());
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			xus=i;
			break;
		}
	}
	x=int(ceil(xus*1.00/n));
	lie=int(ceil(xus*1.00/n));
	if(lie&1){
		if(xus%n==0) y=n;
		else y=xus%n;
	}
	else{
		if(xus%n==0) y=1;
		else y=n-(xus%n)+1;
	}
	printf("%d %d",x,y);
	return 0;
}