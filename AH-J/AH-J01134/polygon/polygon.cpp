#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[5005],dp[5005][5005],sum[5005],maxc[5005][5005],ans;
bool isdbx(ll l,ll r){
	int z=0;
	for(ll i=l;i<=r;i++){
		z=max(z,a[i]);
	}
	if(sum[r]-sum[l-1]-z>z){
		return 1;
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if(n<=3){
		cout<<1;
	}
	for(ll len=3;len<=n;len++){
		for(ll r=len;r<=n;r++){  
			ll l=r-len+1;
			if(isdbx(l,r)){
				ans++;
				if(ans>=998244353){
					ans%=998244353;
				}
			}	
		}
	}
	cout<<ans;	
	return 0;
}
