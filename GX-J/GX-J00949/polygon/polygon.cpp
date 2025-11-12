#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[1001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3) cout<<"0";
	else if(n==3){
		if(a[1]+a[2]+a[3]<(a[1]+a[2]+a[3])*2){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else if(n>3){
		if(a[1]+a[2]+a[3]<(a[1]+a[2]+a[3])*2){
			cout<<"0";
		}
	}
}
