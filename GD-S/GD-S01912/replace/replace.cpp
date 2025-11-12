#include<bits/stdc++.h>
using namespace std;
string mp1[200010],mp2[200010];
unordered_map<string,pair<string,int> > mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q,len;
	string s,t,l,r;
	cin>>n>>q;
	for(int i=1; i<=n; ++i) {
		cin>>mp1[i]>>mp2[i];
//		cerr<<mp1[i]<<' '<<mp2[i]<<endl;
		mp[mp1[i]]= {mp2[i],1};
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			if(i==j) continue;
			if(mp1[i].size()<mp1[j].size()) continue;
			if(mp1[i].find(mp1[j])!=-1&&mp2[i].find(mp2[j])!=-1) {
				mp[mp1[j]].second++;
//				cerr<<mp1[i]<<' '<<mp2[i]<<endl<<mp1[j]<<' '<<mp2[j]<<endl;
			}
		}
	}
	while(q--) {
		int ans=0;
		cin>>s>>t;
		int i=0;
		while(s[i]==t[i]&&i<s.size()) i++;
		int j=0;
		while(s[i+j]!=t[i+j]&&i+j<s.size()) j++;
		l=s.substr(i,j);
		r=t.substr(i,j);
//		cerr<<s<<' '<<t<<endl;
//		cerr<<i<<' '<<j<<endl;
//		cerr<<l<<' '<<r<<endl;
		if(mp.find(l)!=mp.end()) {
			if(mp[l].first==r) {
				ans+=mp[l].second;
//				cerr<<mp[l].second<<' '<<ans<<endl;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

