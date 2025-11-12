#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
const ll base=65535,mod=1e9+7,mod_=998244353;
int n,q,m,l,r;
string s,s_,k,k_;
ll ans;
map<pair<pair<ll,ll>,pair<ll,ll> >,int > mp,mp_;
pair<pair<ll,ll>,pair<ll,ll> > p;
pair<ll,ll> d,d_;
ll cnt,cnt_,_cnt,_cnt_;
inline ll f(bool op){
	ll cnt=1;
	for(int i=l;i<=r;i++) cnt=(base*cnt+(op?s[i]:s_[i])-'a')%mod+1ll;
	return cnt;
}
inline ll f_(bool op){
	ll cnt=1;
	for(int i=l;i<=r;i++) cnt=(base*cnt+(op?s[i]:s_[i])-'a')%mod_+1ll;
	return cnt;
}
inline ll _f(string s){
	ll cnt=1;
	for(int i=0;i<s.size();i++) cnt=(base*cnt+s[i]-'a')%mod+1ll;
	return cnt;
}
inline ll _f_(string s){
	ll cnt=1;
	for(int i=0;i<s.size();i++) cnt=(base*cnt+s[i]-'a')%mod_+1ll;
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>s_;
		if(s==s_) continue;
		l=0,r=s.size()-1,k.clear(),k_.clear();
		while(s[l]==s_[l]) l++,k.push_back(s[l]);
		while(s[r]==s_[r]) r--,k_.push_back(s[r]);
		reverse(k.begin(),k.end()),reverse(k_.begin(),k_.end());
		p={{_f(k),_f(k_)},{f(0),f(1)}};
		if(!mp.count(p)) mp[p]=1;
		mp[p]++;
		p={{_f_(k),_f_(k_)},{f_(0),f_(1)}};
		if(!mp_.count(p)) mp_[p]=1;
		mp_[p]++;
	}
	while(q--){
		cin>>s>>s_;
		if(s.size()!=s_.size()){
			cout<<0<<'\n';
			continue;
		}
		l=0,r=s.size()-1,k.clear(),k_.clear();
		while(s[l]==s_[l]) l++;
		while(s[r]==s_[r]) r--;
		d={f(0),f(1)},d_={f_(0),f_(1)};
		ans=0,cnt=1,cnt_=1;
		_cnt=1,_cnt_=1,ans+=min(mp[{{cnt,_cnt},d}],mp_[{{_cnt,_cnt_},d_}]);
		for(int j=r+1;j<s.size();j++){
			_cnt=(base*_cnt+s[j]-'a')%mod+1;
			_cnt_=(base*_cnt_+s[j]-'a')%mod_+1;
			ans+=min(mp[{{cnt,_cnt},d}],mp_[{{_cnt,_cnt_},d_}]);
		}
		for(int i=l-1;i>=0;i--){
			cnt=(base*cnt+s[i]-'a')%mod+1;
			cnt_=(base*cnt_+s[i]-'a')%mod_+1;
			_cnt=1,_cnt_=1,ans+=min(mp[{{cnt,_cnt},d}],mp_[{{_cnt,_cnt_},d_}]);
			for(int j=r+1;j<s.size();j++){
				_cnt=(base*_cnt+s[j]-'a')%mod+1;
				_cnt_=(base*_cnt_+s[j]-'a')%mod_+1;
				ans+=min(mp[{{cnt,_cnt},d}],mp_[{{_cnt,_cnt_},d_}]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
