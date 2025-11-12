#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int main(){
	int n,m,k,p,o;
	double l,mn;
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	p=a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p>a[i][j]){
				l--;
			}
		}
	}
	
	k=l;
	mn=ceil(l/n);
	o=mn;
	if(k%n==0){
		if(o%2==0){
			cout<<o<<" "<<1;
		}else{
			cout<<o<<" "<<n;
		}
	}else{
		if(o%2==0){
			if(k%n==1){
				cout<<o<<" "<<n;
			}else if(k%n==2){
				cout<<o<<" "<<n-1;
			}else if(k%n==3){
				cout<<o<<" "<<n-2;
			}else if(k%n==4){
				cout<<o<<" "<<n-3;
			}else if(k%n==5){
				cout<<o<<" "<<n-4;
			}else if(k%n==6){
				cout<<o<<" "<<n-5;
			}else if(k%n==7){
				cout<<o<<" "<<n-6;
			}else if(k%n==8){
				cout<<o<<" "<<n-7;
			}else if(k%n==9){
				cout<<o<<" "<<n-8;
		}
		}else{
			cout<<o<<" "<<k%n;
		} 
		 
	}
	
	return 0;
}