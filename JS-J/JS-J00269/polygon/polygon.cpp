#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int mod=998244353;
int n,a[5005];
bool spec=1;
ll mypow(ll res,int b,int exp){
	if(b==0)return res;
	return mypow((res*exp)%mod,b-1,exp);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)spec=0;
	}
	if(spec){
		ll a=mypow(1,n,2);
		ll b=(n*(n-1)/2+n+1)%mod;
		ll ans=(a-b)%mod;
		if(ans<0)ans=mod-ans;
		cout<<ans; 
	}
	else cout<<mod-1;
	return 0;
}
