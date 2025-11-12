#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace replace{
	const ll N=5e6+10,p=1e9+7;
	ll n,q,a1[N],ans,d[N];
	string s1,s2;
	map<ll,ll>mp;
	void myd(ll&x){x%=p;}
	ll ksm(ll x){
		ll y=p-2,res=1;
		while(y){
			if(y&1) myd(res*=x);
			myd(x*=x);
			y>>=1;
		}
		return res;
	}
	void work1(){
		for(ll i=1;i<=n;i++){
			cin>>s1>>s2;
			ll rs=0,t=1;
			for(ll j=0;j<s1.size();myd(t*=3),j++)
				myd(rs+=(s1[j]+s1[j]-s2[j]-s2[j]-s2[j]+131)*t);
			mp[rs]++;
		}
		while(q--){
			ans=0;
			cin>>s1>>s2;
			ll rs=0,t=1;
			for(ll j=0;j<s1.size();myd(t*=3),j++)
				myd(rs+=(s1[j]+s1[j]-s2[j]-s2[j]-s2[j]+131)*t);
			for(ll i=0;i<=n;myd(rs*=3),i++)
				if(mp.find(rs)) ans+=mp[rs];
			cout<<ans;
		}
	}
	void solve(){
		cin>>n>>q;
		bool type=0;
		for(int i=1;i<=n;i++){
			cin>>s1>>s2;
			for(int j=0;j<s1.size();j++){
				if(s1[j]>'b') type=1;
			}
		}
		if(type) work1(),exit(0);
		while(q--){
			
		}
	}
}
using namespace replace;
int main(){
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
}
