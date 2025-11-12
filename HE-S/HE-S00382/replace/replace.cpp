#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for (int i=1;i<=n;++i){
		string s1,s2;cin>>s1>>s2;
		mp[s1]=s2;
	}
	while (q--){
		string s,t;cin>>s>>t;
		int ll=0,rr=s.length()-1;
		bool okl=1,okr=1;
		while (okl||okr){
			if (s[ll]==t[ll])ll++;
			else okl=0;
			if (s[rr]==t[rr])rr--;
			else okr=0;
		}
		if (rr<ll)swap(ll,rr);
		int ans=0;
		for (int l=ll;l>=0;--l){
			for (int r=rr;r<s.length();++r){
				string i=s.substr(l,r-l+1),j=t.substr(l,r-l+1);
				if (i==j||mp[i]==j)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
