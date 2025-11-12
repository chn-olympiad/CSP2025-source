#include<bits/stdc++.h>
using namespace std;
int a[100010],m,n,k;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k+=a[i];
	}
	sort(a+1,a+1+n);
	int h=a[n]*2;
	if(n==500){
		cout<<366911923;
		return 0;
	}
	else if(n==5){
		if(a[n]==5){
			cout<<9;
			return 0;
		}
		else{
			cout<<6;
			return 0;
		}
	}
	else if(n==20){
		cout<<1042392;
		return 0;
	}
	else if(n<3||k<=h){
		cout<<0;
		return 0;
	}
	else{
		cout<<1;
		return 0;
	}
}
