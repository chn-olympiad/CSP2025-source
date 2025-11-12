#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int N=5005,mod=998244353;
int n,ans=0,
	a[N];
int f(int x,int p,int sp){
	if(x>=p)	return 0;
	int s=0;
	for(int i=x;i<p;++i){
		if(sp<a[i])	s=(s+(p-i-1)%mod*(p-i)%mod/2+1)%mod;
		else	s=(s+f(i+1,p,sp-a[i]))%mod;
	}
	return s%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;++i)
		ans=(ans+f(1,i,a[i]))%mod;
	cout<<ans;
	return 0;
}
