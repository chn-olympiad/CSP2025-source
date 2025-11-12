#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,c[505],s[505],ans=0,t=0;
string sr;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>sr;
	ll fa=1;
	for(ll i=0;i<(ll)sr.length();i++){
		s[i+1]=sr[i]-'0';
		if(sr[i]!='1')fa=0;
	}
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)t++;
	}
	if(m==1){
		ans=1;
		for(ll i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	if(fa==1){
		ans=1;
		for(ll i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
