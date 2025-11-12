#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
string s,ans;
multiset<char> st;
vector<char> v;
map<char,ll> mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(mp[s[i]]==0){
				v.push_back(s[i]);
			}
			mp[s[i]]++;
		}
	}
	sort(v.begin(),v.end());
	for(ll i=v.size()-1;i>=0;i--){
		for(ll j=1;j<=mp[v[i]];j++){
			ans+=v[i];
		}
	}
	cout<<ans;
	return 0;
}
