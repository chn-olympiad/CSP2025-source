#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,ans,x,a[2000008],b[2000008],ma[2000008],maxx,mod=998244353;
main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		ma[i]=max(ma[i-1],a[i]);
	}
	if(n<=3){
		for(int i=1;i<=n;i++) x+=a[i],maxx=max(maxx,a[i]);
		if(x>maxx*2) return cout<<1,0;
		else return cout<<0,0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(b[j]-b[i]>ma[i]*2) ans++;
		}
	}
	cout<<ans%mod;
	return 0;
} 
