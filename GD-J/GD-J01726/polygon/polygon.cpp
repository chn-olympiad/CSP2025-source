#include<bits/stdc++.h>
using namespace std;
long long pow2(long long n){
	if(n==0)return 1;
	return n%2?2*pow2(n/2)%998244353*pow2(n/2)%998244353:pow2(n/2)%998244353*pow2(n/2)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a1,a2,a3;
	cin>>n>>a1>>a2>>a3;
	long long t;
	for(long long i=3;i<n;i++)cin>>t;
	if(n==3){
		cout<<(a1+a2+a3>2*max(a1,max(a2,a3)));
	}
	else cout<<(pow2(n)-1-n-n*(n-1)/2)%998244353;
	return 0;
}
