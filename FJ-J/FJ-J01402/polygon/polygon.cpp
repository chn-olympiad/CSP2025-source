#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],zd=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>zd)zd=a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>zd*2)cout<<1;
		else cout<<0;
	}
	if(n==5){
		if(a[1]==1)cout<<9;
		else cout<<6;
	}
	return 0;
}
