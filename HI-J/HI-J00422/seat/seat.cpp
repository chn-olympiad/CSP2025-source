#include<bits/stdc++.h> 
using namespace std;
int a[10000017];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
	}if(n==1&&m==2){
		if(a[0]>a[1]){
			cout<<1<<" "<<1;
		}else{
			cout<<1<<" "<<2;
		}
	}if(n==1&&m==3){
		if(a[0]>a[1]&&a[0]>a[2]){
			cout<<1<<" "<<1;
		}if(a[0]<a[1]&&a[0]>a[2]){
			cout<<1<<" "<<2;
		}if(a[0]<a[1]&&a[0]<a[2]){
			cout<<1<<" "<<3;
		}
	}if(n==1&&m==4){
		if(a[0]>a[1]&&a[0]>a[2]&&a[0]>a[3]){
			cout<<1<<" "<<1;
		}if(a[0]<a[1]&&a[0]>a[2]&&a[0]>a[3]){
			cout<<1<<" "<<2;
		}if(a[0]<a[1]&&a[0]<a[2]&&a[0]>a[3]){
			cout<<1<<" "<<3;
		}if(a[0]<a[1]&&a[0]<a[2]&&a[0]<a[3]){
			cout<<1<<" "<<4;
		}
	}
	
	return 0;
}
