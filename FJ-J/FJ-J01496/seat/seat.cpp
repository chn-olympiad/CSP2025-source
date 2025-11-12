#include<bits/stdc++.h>
using namespace std;
long long a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,k=0,xb=0,r=0,c=0,zrs=0;
	cin>>n>>m;
	zrs=n*m;
	for(int i=1;i<=zrs;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+zrs,cmp);
	for(int i=1;i<=zrs;i++){
		if(a[i]==k){
			xb=i;
			break;
		}
	}
	if(xb%n==0){
		if((xb/n)%2==1){
			r=m;
			c=xb/n;
		}
		if((xb/n)%2==0){
			r=1;
			c=xb/n;
		}
	}else if(xb%n!=0){
		if((xb/n+1)%2==1){
			r=xb%n;
			c=xb/n+1;
		}
		if((xb/n+1)%2==0){
			r=m-(xb%n)+1;
			c=xb/n+1;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
