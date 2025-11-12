#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,q;
string s,s1;
map<string,string> m; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s>>s1;
		m[s]=s1;
	}
	while(q--){
		s.clear();
		s1.clear();
		cin>>s>>s1;
		if(s.size()!=s1.size()){
			cout<<0<<endl;
			continue;
		}
		ll len=s.size();
		s=' '+s;
		s1=' '+s1;
		ll l=len+1,r=0;
		for(ll i=1;i<=len;i++){
			if(s[i]!=s1[i]){
				l=min(l,i);
				r=max(r,i);
			}
		}
		if(r==0){
			cout<<0<<endl;
			continue;
		}
		ll ans=0;
		while(1){
			if(m[s.substr(l,r-l+1)]==s1.substr(l,r-l+1)){ 
				ans++;
			}
			if(l>1){
				if(m[s.substr(l-1,r-l+1)]==s1.substr(l-1,r-l+1)) ans++;
			}
			if(r<len){
				if(m[s.substr(l,r+2-l)]==s1.substr(l,r-l+2)) ans++;
			}
			if(l==1 && r==len) break;
			if(l>1) l--;
			if(r<len) r++;
		}
		cout<<ans<<endl;
	}
	return 0;
}