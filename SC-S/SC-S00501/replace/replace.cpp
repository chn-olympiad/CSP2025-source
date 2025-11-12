#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s1[200005],s2[200005];
int dfs(string s,string sd) {
	for(unsigned i=0; i<s.size(); i++) {
		if(s[i]!=sd[i]) {
			int ans=0;
			for(int li=1; li<=n; li++) {
				int flag=1;
				for(unsigned j1=i,j2=0; j2<s1[li].size(); j1++,j2++) {
					if(s[j1]!=s1[li][j2]) {
						flag=0;
						break;
					}
				}
				if(flag) {
					for(unsigned j1=i,j2=0; j2<s1[li].size(); j1++,j2++) {
						s[j1]=s2[li][j2];
					}
					ans+=(s==sd);
					for(unsigned j1=i,j2=0; j2<s1[li].size(); j1++,j2++) {
						s[j1]=s1[li][j2];
					}
				}
			}
			return ans+(s==sd);
		}
	}
	return (s==sd);
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		string sx1,sx2;
		cin>>sx1>>sx2;
		int flag=1;
		for(unsigned j=0; j<sx1.size(); j++) {
			if(sx1[j]!=sx2[j]) {
				flag=0;
			}
			if(flag) {
				continue;
			}
			s1[i]+=sx1[j];
			s2[i]+=sx2[j];
		}
	}
	while(q--) {
		string a,b;
		cin>>a>>b;
		cout<<dfs(a,b)<<"\n";
	}
	return 0;
}
