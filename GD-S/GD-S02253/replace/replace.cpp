#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+10;
int n,q;
map<pair<string,string>,vector<int> >mp;
string s,t,a[200010],b[200010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i=1;i<=n;i++){
		cin >> s >> t;
		int ln=s.length(),l=-1,r=-1;
		for (int j=0;j<ln;j++){
			if (s[j]!=t[j]){
				if (l==-1) l=j;
				r=j;
			}
		}
//		cout << l << " " << r << "\n";
		if (l==-1&&r==-1) continue;
		mp[{s.substr(l,r-l+1),t.substr(l,r-l+1)}].push_back(i);
	}
	int tp=0;
	for (int i=1;i<=q;i++){
		cin >> s >> t;
		int ln=s.length(),lm=t.length(),l=-1,r=-1;
		if (ln!=lm){
			cout << 0 << '\n';
			continue;
		}
		for (int j=0;j<ln;j++){
			if (s[j]!=t[j]){
				if (l==-1) l=j;
				r=j;
			}
		}
//		cout << l << " " << r << " ";
		int ans=mp[{s.substr(l,r-l+1),t.substr(l,r-l+1)}].size();
//		if (tp==0) for (int j:mp[{s.substr(l,r-l+1),t.substr(l,r-l+1)}]) cout << j << ' ',tp=1;
		cout << ans << '\n';
	}
}
