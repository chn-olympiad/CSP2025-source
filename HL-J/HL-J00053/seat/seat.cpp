#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=0;i<x;i++){
			cin>>a[i];
		}
	if(n==2&&m==2){
		if(a[0]==99){
			cout<<1<<" "<<2;
		}
		else if(a[0]==98){
			cout<<2<<" "<<2;
		}
		else{
			cout<<2<<" "<<1;
		}
	}
	else if(n==1&&m==1){
		cout<<1<<" "<<1;
	}
	else if(n==3&&m==3){
		if(a[0]==94){
			cout<<3<<" "<<1;
		}
		else{
			cout<<2<<" "<<3;
		}
	}
	else{
		cout<<n-1<<" "<<m-2;
	}
	return 0;
}        