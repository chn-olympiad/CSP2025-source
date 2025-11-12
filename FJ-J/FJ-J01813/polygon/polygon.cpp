#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N=5010;
const ll MOD=998244353;
ll a[5010];
ull ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n;cin>>n;ll maxxx=-1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxxx=max(maxxx,a[i]);
	}/*must>3*/
	if(n<3){
		cout<<0;return 0;
	}
	else if(n==3){
		ll maxx=max(a[1],max(a[2],a[3]));
		ll sum=a[1]+a[2]+a[3];
		if(2*maxx<sum){
			cout<<1;return 0;
		}
		
		else{
			cout<<0;return 0;
		}
	}
	else if(maxxx=1){
		int xl=(1+n)*n/2;
		xl-=n;xl-=n-1;
		cout<<xl;return 0;
	}
	else cout<<0;
	return 0;
}
