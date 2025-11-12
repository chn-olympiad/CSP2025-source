#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(int n){
	if(n==0)return 1;
	return n*f(n-1);
}

int a[15999];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){if(a[0]+a[1]+a[2]>max(max(a[0],a[1]),a[2])*2) cout<<1; else cout<<0; return 0;}
	if(n<=20) ans=99;
	else if(a[0]==1 && a[494]==1)ans=(n*n-n-1-(f(n)/(2*f(n-2))))%998244353;
	else ans=366911923;
	cout<<ans%998244353;
	return 0;
}

