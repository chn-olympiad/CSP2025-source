#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,q;
string s1[N],s2[N];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s1[i]>>s2[i];
	}
	while(q--) {
		int ans = 0;
		string s,c;
		cin>>s>>c;
		for(int i=1; i<=n; i++) {
			int x = s.find(s1[i]);
			if(x == -1) {
				continue;
			}
			while(x != -1) {
				string ss,cc;
				ss = "",cc = "";
				for(int j = 0; j<x-1; i++) {
					ss += s[j];
				}
				for(int j = x + s1[i].size(); j<s.size(); j++) {
					cc += s[j];
				}
				if(ss + s2[i] + cc == c) {
					ans++;
				}
				x = s.find(s1[i],x+1);
				if(x == -1) {
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
