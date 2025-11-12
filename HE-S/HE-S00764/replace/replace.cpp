#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,q,ans,cnt;
string s1,s2,s[N];
map<string,string> m;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(ll i=1; i<=n; i++) {
		cin>>s1>>s2;
		s[i]=s1;
		m[s1]=s2;
	}
	while(q--) {
		cnt=0;
		ans=0;
		cin>>s1>>s2;
		for(ll i=1; i<=n; i++) {
			cnt=s1.find(s[i]);
			if(cnt==0) {
				if(m.count(s1)==0) break;
				else if(m[s1]==s2) {
					ans++;
				}
			} else {
				string t=s1.substr(0,cnt)+m[s[i]]+s1.substr(cnt+m[s[i]].size());
				if(t==s2) {
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
