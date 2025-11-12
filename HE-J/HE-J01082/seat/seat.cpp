#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m,x,R,C;
	int a[10000];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	for(int j=1;j<=n*m;j++){
		for(int i=1;i<=n*m;i++){
			if(a[i]<a[i+1]){
				x=a[i];
				a[i]=a[i+1];
				a[i+1]=x;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(R==a[i]){
			C=i;
		}
	} 
	if(C>n){
		if(C%n==0){
			cout<<C/n;
		} 
		else{
			cout<<C/n+1;
		}
	}
	else{
		cout<<1;
	}
	cout<<' ';
	if(C%2==0){
		if(C%m==0){
			cout<<1;
		}
		else{
			
			cout<<m+1-C/m;
		}
	}
	else{
		if(C%m==0){
			cout<<3;
		}
		else{
			cout<<0+C%m;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
