#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
const int mod=998244353;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	ll x=0;
	for(int j=n;j>=m;j--){
		ll ans=1;
		for(int i=n;i>=n-j+1;i--){
			ans=(ans%mod*ll(i))%mod;
		}
		x=(x%mod+ans%mod)%mod;
	}
	cout<<x%mod;
	return 0;
}
