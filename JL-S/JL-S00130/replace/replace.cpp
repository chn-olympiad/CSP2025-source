#include <bits/stdc++.h>
using namespace std;
string s[200005][3];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while (q--) {
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for (int i=1;i<=n;i++) {
			int lent=t1.size(),lens=s[i][1].size();
			if (lent<lens) continue;
			else if (lent==lens && t1==s[i][1] && t2==s[i][2]) ans++;
			else {
				for (int l=0;l+lens-1<lent;l++) {
					string s1=t1.substr(l,lens),s2=t2.substr(l,lens);
					if (s1!=s[i][1] || s2!=s[i][2]) continue;
					else if (t1.substr(0,l)==t2.substr(0,l) && t1.substr(l+lens,lent-lens-l)==t2.substr(l+lens,lent-lens-l)) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
