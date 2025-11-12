#include <bits/stdc++.h>
using namespace std;
int n;
int a[50005];
int sum;
int main(){
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxa=-1;
	for(int i=0;i<n;i++){
		if(a[i]>maxa) maxa=a[i];
	}
	if(a[0]+a[1]+a[2]>2*maxa) cout<<1;
	else cout<<0;
	return 0;
} 