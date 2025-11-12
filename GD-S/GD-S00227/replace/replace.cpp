#include <bits/stdc++.h>
using namespace std;
pair <string,string> s[200010];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0; i<n; i++) {
		cin>>s[i].first>>s[i].second;
	}
	while(q--) {
		string a,b;
		cin>>a>>b;
		long long ans=0;
		for(int i=0; i<n; i++) {
			if(a.find(s[i].first)!=string::npos) {
				for(int j=0; j<=a.length()-s[i].first.length(); j++) {
					if(a.substr(j,s[i].first.length())==s[i].first) {
						string x="";
						x=x+a.substr(0,j)+s[i].second+a.substr(j+s[i].first.length());
						if(x==b) {
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}
