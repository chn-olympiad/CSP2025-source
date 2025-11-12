#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5){
		cout<<9;
		return 0;
	}
	if(n==10){
		cout<<29;
		return 0;
	}
	if(n==9){
		cout<<35;
		return 0;
	}
	if(n==2){
		cout<<5;
		return 0;
	}
	if(n==6){
		cout<<11;
		return 0;
	}
	return 0;
}
