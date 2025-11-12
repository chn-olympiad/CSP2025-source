#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans;
string s[N][2];
map<pair<string,string>,int>mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n>>q;
	for (int i=1;i<=n;i++) {
		cin >>s[i][0]>>s[i][1];
		mp[{s[i][0],s[i][1]}]++;
	}
	while (q--) {
		string t1,t2;
		cin >>t1>>t2;
		int S=0,T=0,ans=0;
		for (int i=0;i<t1.size();i++) {
			if (t1[i]!=t2[i]) {
				S=i;
				break; 
			}
		}
		for (int i=t1.size()-1;i>=0;i--) {
			if (t1[i]!=t2[i]) {
				T=i;
				break; 
			}
		}
//		cout <<S<<" "<<T<<"\n";
		for (int i=0;i<=S;i++) {
			string cnt1="",cnt2="";
			for (int j=i;j<t1.size();j++) {
				cnt1+=t1[j],cnt2+=t2[j];
//				cout <<cnt1<<" "<<cnt2<<"\n";
				if (j>=T) {
					ans+=mp[{cnt1,cnt2}];
				}
			}
		}
		cout <<ans<<"\n";
	}
	return 0;
}
