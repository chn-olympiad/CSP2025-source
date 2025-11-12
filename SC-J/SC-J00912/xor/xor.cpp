#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
typedef long long ll;
using namespace std;
ll n,k,ans;
vector<ll> ks,qz;
vector<pair<ll,ll>> qj;
map<ll,ll> vs;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
	return x.second<y.second;
}
void putin()
{
	cin>>n>>k;
	ks.resize(n);
	qz.push_back(0);
	for(ll&t:ks) cin>>t,qz.push_back(qz.back()^t);
}
void chuli()
{
	for(ll i=n;i>=0;i--){
		ll v=qz[i]^k;
		if(vs.find(v)!=vs.end()) qj.push_back({i+1,vs[v]});
		vs[qz[i]]=i;
	}
//	for(auto v:qj) cout<<v.first<<" "<<v.second<<endl;
	sort(qj.begin(),qj.end(),cmp);
	ll rit=-1;
	for(auto v:qj)
		if(v.first>rit)
			ans++,rit=v.second;
}
void putout(){
	cout<<ans<<endl;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	putin();
	chuli();
	putout();
	return 0;
}