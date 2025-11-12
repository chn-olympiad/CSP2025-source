#include<bits/stdc++.h>
using namespace std;
int n,m,sl,r,hm,h,l;
int a[105];
int xsqz(double x){
	if(x!=(int)x){
		return (int)(x+1);
	}
	return x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	sl=n*m;
	for(int i=1;i<=sl;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+sl+1,greater<int>());
	for(int i=1;i<=sl;i++){
		if(r==a[i]){
			hm=i;
			break;
		}
	}
	l=xsqz(hm*1.0/n);
	printf("%d ",l);
	if(l%2==1){
		printf("%d",n-(l*n-hm));
	}else{
		printf("%d",l*n-hm+1);
	}
	return 0;
}
