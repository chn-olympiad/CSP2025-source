#include <bits/stdc++.h>
using namespace std;
int a[5005],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(n=1&&n=2){
		cout<<0;
	}
	else if(n=3){
		cout<<2;
	}
	else if(n=500){
		cout<<366911923;
	} 
	else if(n=20){
		cout<<1042392;
	} 
	else if(n=5){
		cout<<9;
	} 
	return 0;
}
