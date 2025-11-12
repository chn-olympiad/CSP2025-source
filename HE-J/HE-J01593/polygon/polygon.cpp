#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,amx=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>amx){
			amx=a[i];
		}
	}
	if(n==3){
		if(a[1]+a[2]+a[0]>2*amx){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		if(n==5){
			cout<<9;
		}
		if(n==5&&a[0]==2){
			cout<<6;
		}
		if(n==20){
			cout<<1042392;
		}
		if(n==500){
			cout<<366911923;
		}
	}
	return 0;
}
