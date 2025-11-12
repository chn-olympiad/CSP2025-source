#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long yzh,n,a[5005],h; 
long long ksm(int x,int y){
	if(y==0) return 1;
	int t=ksm(x,y/2);
	if(y&1) return t*t%mod*x%mod;
	return t*t%mod;
}
long long C(int x,int y){
	int cnt=1,cnt1=1;
	for(int i=x;i>x-y;i--) cnt*=i,cnt%=mod;
	for(int i=1;i<=y;i++) cnt1*=i,cnt1%=mod;
	return cnt/cnt1;
}
void dfs(int i,long long s,long long l,long long mx){
	if(i==n+1){
		if(s<3||l<=2*mx) return;
		yzh++;yzh%=mod;
	}else{
		dfs(i+1,s+1,l+a[i],max(mx,a[i]));
		dfs(i+1,s,l,mx);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],h=max(h,a[i]);
	if(h<=1) cout<<C(n,3)*ksm(2,n-3)%mod,exit(0);
	dfs(1,0,0,0);
	cout<<yzh%mod;
	return 0;
} 
