#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	scanf("%d %d",&n,&m);
	int b=n*m;
	scanf("%d",&a[1]);
	for(int i=2;i<=b;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1]) c+=1;
	}
	int x=c/n,y=c%n;
	if(y==0){
		if(x%2==0) y=1;
		else y=n;
	}
	else{
		x+=1; 
		if(x%2==0) y=n-y+1;
	}
	printf("%d %d",x,y);
	return 0;
}
