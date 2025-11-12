#include<bits/stdc++.h>
using namespace std;
int n,a[5001],mx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>n*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
}
