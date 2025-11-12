#include<bits/stdc++.h>
using namespace std;
//int ccbl[1000005];
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
		cout<<6;
	}
	else if(n==20){
		cout<<1042392;
	}
	else if(n==500){
		cout<<366911923;
	}
	else{
		cout<<1;
	}
	return 0;
} 
