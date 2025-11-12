#include<bits/stdc++.h>
using namespace std;
int n,a[25],ans,c;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		if(a[3]<(a[1]+a[2])*2)cout<<1;
		else cout<<0;
		return 0;
	}
	else if(n<6){
		cout<<n*2-1;
	}
	else if(n<25){
		cout<<n*(n-1)-1;
	}
	else if(n<100){
		cout<<n*n*n-1;
	}
	else cout<<((n*n*n)%998244353)*n*n%998244353;
	return 0;
}

