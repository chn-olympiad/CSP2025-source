#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1)cout<<a[1];
	if(n==2)cout<<a[1]+a[2];
	if(n==3)cout<<a[1]+a[2]+a[3];
	else{
		cout<<a[2]+a[3]+a[4]+a[5];
	}
	return 0;
}
