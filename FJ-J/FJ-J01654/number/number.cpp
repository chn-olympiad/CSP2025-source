#include<bits/stdc++.h>
#define ll long long
#define db double
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define mkp make_pair
#define il inline
#define endl "\n"
const ll mod=998244353;
const ll inf=1e18;
using namespace std;
string s;vec<ll> rp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(isdigit(s[i])) rp.pb(s[i]-'0');
	} 
	sort(rp.begin(),rp.end(),greater<ll>());
	for(auto rt:rp){
		cout<<rt;
	}
	return 0;
}

