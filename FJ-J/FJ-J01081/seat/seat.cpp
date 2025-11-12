#include<bits/stdc++.h>
using namespace std;
int n,m,z,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	int a[z]={0};
	for(int i=0;i<z;i++){
		cin>>a[i];
	}
	y=a[0];
	sort(a,a+z);
	for(int i=z-1;i>=0;i--){
		if(a[i]==y){
			y=z-i;
			break;
		}
	}
	int i=0;
	if(y%n==0){
		if((y/n)%2==0){
			i=1;
		}else{
			i=n;
		}
	}else{
		if((y/n+1)%2==0){
			i=n-y%n+1;
		}else{
			i=y%n;
		}
	}
	if(y%n==0){
		z=y/n;
	}else{
		z=y/n+1;
	}
	cout<<z<<" "<<i;
	return 0;
} 
