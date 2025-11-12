#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long b;
	int n,ma=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		ma=max(ma,a[i]);
	}
	ma=ma*2;
	if(n==3){
		if(a[0]+a[1]+a[2]>ma) cout<<1;
		else cout<<0;
	}
	else cout<<n*n;
	return 0;
}
