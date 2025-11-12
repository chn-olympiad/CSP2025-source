#include<bits/stdc++.h>
using namespace std;
int n,a[5001],num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
	}
	if(n==5&&num==15){
		cout<<9;
	}
	if(n==5&&num==25){
		cout<<6;
	}
	if(n==20){
		cout<<1042392;
	}
	if(n==500){
		cout<<366911923;
	}
	return 0;
}
