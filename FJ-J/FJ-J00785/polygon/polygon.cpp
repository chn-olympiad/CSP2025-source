#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ma=-1;
int jie(int n){
	int he=1;
	while(n--){
		he*=n;
	}
	return he;
}
int shu(int n){
	return (jie(n)/jie(n-3))/6;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(n==3&&a[1]+a[2]+a[3]>ma*2) cout<<1;
	else if(n==3&&a[1]+a[2]+a[3]<=ma*2) cout<<0;
	else if(ma==1){
		cout<<shu(n);
	}
	return 0;
}
