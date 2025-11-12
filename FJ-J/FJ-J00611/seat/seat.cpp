#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,s,t,a,b;
vector<ll> v;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		ll x;cin>>x;
		v.push_back(x);
	}
	s=v[0];
	sort(v.begin(),v.end(),greater<ll>());
	for(ll i=0;i<n*m;i++){
		if(v[i]==s) t=i;
	}
	cout<<t/n+1<<' ';
	if((t/n+1)%2==1) cout<<(t%n)+1;
	else cout<<n-(t%n);
	return 0;
}
