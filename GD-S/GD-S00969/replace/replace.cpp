#include <bits/stdc++.h>
#define ll long long
#define maxn 200010
using namespace std;

ll n,q;
struct node {
	string s1,s2;
} S[maxn];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>S[i].s1>>S[i].s2;
	while (q--) {
		ll ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if (t1.size()!=t2.size()) {
			cout<<"0\n";
			continue;
		}
		for (int i=0;i<t1.size();i++) {
			for (int j=i;j<t1.size();j++) {
				bool ok=1;
				for (int k=0;k<i;k++) {
					if (t1[k]!=t2[k]) {
						ok=0;
						break;
					}
				}
				if (!ok) continue;
				for (int k=j+1;k<t1.size();k++) {
					if (t1[k]!=t2[k]) {
						ok=0;
						break;
					}
				}
				if (!ok) continue;
				for (int k=1;k<=n;k++) {
					if (S[k].s1.size()==j-i+1) {
						bool ok2=1;
						for (int l=0;l<S[k].s1.size();l++) {
							if (t1[i+l]!=S[k].s1[l]) {
								ok2=0;
								break;
							}
						}
						if (ok2) {
							string t3=t1;
							for (int l=0;l<S[k].s1.size();l++) {
								t3[i+l]=S[k].s2[l];
							}
							for (int l=0;l<t1.size();l++) {
								if (t3[l]!=t2[l]) break;
								if (l==t3.size()-1) ans++;
							}
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
