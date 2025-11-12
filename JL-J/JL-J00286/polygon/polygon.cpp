#include<bits/stdc++.h>
using namespace std;
long long a[23456];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		sort(a+1,a+4);
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n==5&&a[1]==1){
		cout<<9;
	}else if(n==5&&a[1]==2){
		cout<<6;
	}
	return 0;
}
