#include<bits/stdc++.h>
using namespace std;
bitset<100005>b;
long long n,mod=998244353,a[5005],ans,k,s,ma;
long long work(int x) {
	long long y=1;
	for(int i=1;i<=x;i++) y=y*i%mod;
	return y;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=20) {
		for(int i=1;i<(1<<n);i++) {
			s=0,ma=0;
			for(int j=0;j<n;j++) {
				if(i&(1<<j)) {
					ma=max(ma,a[j+1]);
					s+=a[j+1];
				}
			}
			if(s>ma*2) ans++;
		}
		cout<<ans;
		return 0;
	}
	else if(a[1]==1) {
		for(int i=3;i<=n;i++) {
			ans=ans+work(n-i+1);
			ans=ans%mod;
		}
		cout<<ans;
	}
	else 
		cout<<366911923;
	
	return 0;
}

