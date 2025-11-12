#include<bits/stdc++.h>
using namespace std;
int n,a[5005],dp[5005],lap[5005];
//int aadd(int c,int xx,int x,int w){
//	if(xx==1){
//		for(int i=c;i<x;i++)
//	}
//	int ret=0;
//	for(int i=c;i<x;i++){
//		if(a[i]+aadd(i+1,xx-1,x,w)>w)ret=(ret+1)%998244353;
//	}
//	return ret%998244353;
//}
//int adda(int x,int m){
//	int ret=0;
//	for(int i=2;i<x;i++){
//		ret=(ret+aadd(0,i,x,m))%998244353;
//	}
//	return ret;
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		lap[i+1]=lap[i]+a[i];
	}
	sort(a,a+n);
	int ans=0;
	for(int i=2;i<n;i++){
		if(lap[i+1]>a[i]*2)ans++;
	}
//	for(int i=2;i<n;i++){
//		dp[i]=(dp[i-1]+adda(i,2*a[i]))%998244353;
//	}
//	cout<<dp[n-1];
	cout<<ans;
	return 0;
}

