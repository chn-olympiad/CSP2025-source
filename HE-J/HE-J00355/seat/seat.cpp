#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,x,sum=0,y,z,h,f=1;
	cin>>n>>m;
	a=n*m;
	int c[a];
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	x=c[0];
	for(int i=a;i>=0;i--){
		if(c[i]<c[i-1]){
			h=c[i];
			c[i]=c[i-1];
			c[i-1]=h;
		}
	}
	for(int i=0;i<=a;i++){
		if(x==c[i]){
			sum=i;
		}
	}
	for(int i=0;i<y;i++){
		f=f+1;
	}
	int r=n;
	if(sum>n){
		y=sum/n;
		z=sum%n;
		if(y%2==0){
			r=r-z;
			cout<<f<<" "<<r;
		}else{
			cout<<f<<" "<<z;
		}
	}
	else{
		cout<<f<<" "<<sum;
	}
	return 0;
}
