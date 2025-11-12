#include<bits/stdc++.h>
using namespace std;
long long n,a[5001];
long long c=0,l,r;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[3]>=a[1]+a[2]){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else{
		for(int i=1;i<=n-2;i++){
			c+=i*(n-i-1);
		}
		cout<<c*n%998244353;
	}
	
	
	
	return 0;
} 
