#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,q;
string s[2],sub[2];
map<pair<string,string>,int> mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>s[0]>>s[1],mp[make_pair(s[0],s[1])]++;
	int len;
	while (q--) {
		cin>>s[0]>>s[1];
		len=s[0].size(); int mxl=0,mnr=len-1;
		for (int i=0;i<len;i++)
			if (s[0][i]!=s[1][i]) {mxl=i;break;}
		for (int i=len-1;i>=0;i--)
			if (s[0][i]!=s[1][i]) {mnr=i;break;}
		ll ans=0;
		for (int l=0;l<=mxl;l++) {
			sub[0]=sub[1]="\0";
			for (int i=l;i<mnr;i++) sub[0]+=s[0][i],sub[1]+=s[1][i];
			for (int r=mnr;r<len;r++) {sub[0]+=s[0][r],sub[1]+=s[1][r]; ans+=mp[make_pair(sub[0],sub[1])];}
		}
		cout<<ans<<"\n";
	}
	return 0;
}