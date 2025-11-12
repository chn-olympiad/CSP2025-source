#include<bits/stdc++.h>
using namespace std;
int n,a[5001],m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]>a[2]&&a[1]>a[3]){
		m=a[1];
	}
	else if(a[2]>a[1]&&a[2]>a[3]){
		m=a[2];
	}
	else m=a[3];
	if(a[1]+a[2]+a[3]>m*2){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
