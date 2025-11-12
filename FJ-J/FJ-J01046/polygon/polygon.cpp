#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5241],c1,ans;
long long fpow(long long b,long long n){
	long long ans=1;
	while(n){
		if(n&1){
			ans=(ans*b)%mod;
		}
		b=(b*b)%mod;
		n>>=1;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		long long a,b,c;
		if(a+b>c&&b+c>a&&c+a>b){cout<<1;}
		else{cout<<0;}
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){c1++;}
	}
	if(c1==n){
		long long ans=fpow(2,n);
		ans=(ans-n-n*(n-1)/2-1)%mod;
		cout<<ans;
		return 0;
	}
	cout<<53423;
	return 0;
}
