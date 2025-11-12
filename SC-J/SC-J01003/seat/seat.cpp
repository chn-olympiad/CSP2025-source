#include<bits/stdc++.h>
using namespace std;
long long n,m,wz=1,xr,x;
long long c,r;
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>xr;
	for(int i=1;i<=(n*m)-1;i++){
		cin>>x;
		if(x>xr){
			wz++;
		}
	}
	c=wz/n;
	if(wz>c*n){
		c++;
	}
	if(c%2==1){
		if(wz%n==0){
			r=n;
		}else{
			r=(wz%n);
		}
	}else{
		if(wz%n==0){
			r=1;
		}else{
			r=n-(wz%n)+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 