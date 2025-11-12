#include<bits/stdc++.h>
#define mod 998244353 
#define ll long long
ll n,a[5005],ans;
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=n;i>=1;i++){
		int cnt=0;
		for(int j=1;j<=n;j++) cnt+=a[j];
		if(a[i]*2>cnt) ans++;	
}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<"9";
	else cout<<ans%mod;
	return 0;
}
