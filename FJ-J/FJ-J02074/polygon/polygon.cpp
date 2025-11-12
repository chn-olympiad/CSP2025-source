#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,m,mod=998244353,ans=0;
	cin>>n;
	vector<ll> a(n+1);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		m+=a[i];
	} 
	if(n<3) ans=0;
	if(n==3){
		sort(a.begin(),a.end());
		if(a[1]+a[2]>a[3]) ans++;
	}
	else{
		sort(a.begin(),a.end());
		if(m>a[n]*2) ans++;
	}
	cout<<ans%mod<<endl;
	return 0;
}

