#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
typedef long long ll;
const ll maxn=100007;
ll n,a[maxn][3],ans;
vector<pair<ll,ll> > vec;
vector<ll> v2[3];
int main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	ll T=1; cin>>T;
	for(;T--;){
		cin>>n,ans=0;
		for(ll i=0;i<=2;i++) v2[i].clear();
		for(ll i=1;i<=n;i++){
			vec.clear();
			for(ll j=0;j<=2;j++) cin>>a[i][j],vec.pb(a[i][j],j);
			sort(vec.begin(),vec.end());
			ans+=vec[2].first;
			v2[vec[2].second].pb(vec[2].first-vec[1].first);
		}
		for(ll i=0;i<=2;i++)if((ll)v2[i].size()>n/2){
			sort(v2[i].begin(),v2[i].end());
			for(ll j=0;j<(ll)v2[i].size()-n/2;j++) ans-=v2[i][j];
		}
		cout<<ans<<"\n";
	}
	return 0;
}