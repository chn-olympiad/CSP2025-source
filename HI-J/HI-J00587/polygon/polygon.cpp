#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	int a[n+10];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3 && a[1]+a[2]>a[3] && a[1]+a[2]+a[3]>a[3]){
		cout<<a[1]+a[2]+a[3];
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
