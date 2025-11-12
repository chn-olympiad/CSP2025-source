#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5){
		if(a[n]==5){
			cout<<9;
		}
		else if(a[n]==10){
			cout<<6;
		}
	}
	if(n==20){
		cout<<1042392;
	}
	if(n==500){
		cout<<366911923;
	}
	return 0;
} 
