#include<bits/stdc++.h>
using namespace std;
int l,r,xi,n,m;
int a[105];
bool cup(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&l,&r);
	for(int i=1;i<=l*r;i++){
		scanf("%d",&a[i]);
	}
	xi=a[1];
	sort(a+1,a+l*r+1);
	int pos=lower_bound(a+1,a+l*r+1,xi)-a;
	pos=l*r-pos+1;
	n=pos/l;
	m=pos%l;
	//cout<<pos<<endl;
	if(m==0){
		if(n&1){
			printf("%d %d",n,l);
		}	
		else{
			printf("%d 1",n);
		}
		return 0;
	}
	else{
		if(n&1){
			printf("%d %d",n+1,l-m+1);
		}
		else{
			printf("%d %d",n+1,m);
		}
		return 0;
	}
	return 0;
}