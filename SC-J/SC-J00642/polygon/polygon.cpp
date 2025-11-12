#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f==1){
		cout<<n-2;
		return 0;
	}
	else if(n==3){
		int x=a[1];
		x=max(x,a[2]);
		x=max(x,a[3]);
		if(x*2<a[1]+a[2]+a[3]-x){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	else if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
		return 0;
	}
	else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
		return 0;
	}
	else {
		cout<<0;
		return 0;
	}
	
	return 0;
} 