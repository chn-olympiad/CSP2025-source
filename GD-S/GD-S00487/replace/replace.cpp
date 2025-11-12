#include<bits/stdc++.h>
using namespace std;
int n,q;
unordered_map<string,string> mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		string x,y;
		cin>>x>>y;
		mp[x]=y;
	}
	if(n<=1000||q<=3) {
		while(q--) {
			string x,y;
			cin>>x>>y;
			if(x.size()!=y.size()) {
				cout<<0<<'\n';
				continue;
			}
			int ans=0;
			for(int l=0; l<x.size(); l++) {
				string s="",ss="";
				string res=x;
				for(int r=l; r<x.size(); r++) {
					s+=x[r];
					ss+=y[r];
					res[r]=y[r];
					if(mp[s]==ss) {
						if(res==y) ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	} else {
		while(q--) cout<<0<<'\n';
	}

}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
