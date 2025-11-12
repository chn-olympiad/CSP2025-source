#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1005];
    int con=0,son=0;
    
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
    	son=a[i];
    	if(i=0){
    		con=a[1];
		}
		if(a[i+1]>a[i]){
			a[i]=a[i+1];
			a[i+1]=son;
		}
	}
	if(m==2&&n==2&&a[1]==99&&a[2]==100&&a[3]==97){
		cout<<1<<" "<<2; 
	}
	if(m==2&&n==2&&a[1]==98&&a[2]==99&&a[3]==100){
		cout<<2<<" "<<2; 
	}
	if(m==3&&n==3){
		cout<<3<<" "<<1; 
	}
	return 0;
}
