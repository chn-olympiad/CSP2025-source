#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
struct  node{
	ll a, b, c, waste;
	ll sum[3];
	map<int, int> mp;
}s[N];
bool cmp(ll a, ll b){return a>b;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    cin >> t;
    while(t--){
		vector<ll> v[3];
		ll n, ans=0;cin >> n;
		for(int i=1; i<=n; ++i){
			node o;
			cin>> o.sum[0] >> o.sum[1] >> o.sum[2];
			o.mp[o.sum[0]]=0; o.mp[o.sum[1]]=1; o.mp[o.sum[2]]=2;
			sort(o.sum, o.sum+3);
			o.a=o.sum[0];
			o.b=o.sum[1];
			o.c=o.sum[2];
			ans+=o.c;
			o.waste=o.c-o.b;
			v[o.mp[o.c]].push_back(o.waste);
			s[i]=o;
		}
		int flag; bool y=true;
		for(flag=0; flag<=2; ++flag) if(ll(v[flag].size())>ll(n/2)) {y=false; break;}
		if(!y){
			sort(v[flag].begin(), v[flag].end());
			ll c=v[flag].size()-n/2;
			for(int i=1; i<=c; ++i){ans-=v[flag][i-1];}
		}
		cout << ans <<'\n';
	}
    return 0;
}
