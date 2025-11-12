#include<bits/stdc++.h>
#define ll long long
const int mod=998244353;
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,ans=0;cin>>n;
	vector<ll>A(n);
	for(ll &i:A)cin>>i;
	sort(A.begin(),A.end());
	for(ll i=0;i<(1<<n);i++){
		ll sum=0,max_=0,tim=0,p=i;
		for(ll j=0;j<n;j++){
			if(p%2==1)sum+=A[j],max_=A[j],tim++;
			p>>=1;
		}
		if(tim<3||max_*2>=sum)continue;
		ans++;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}