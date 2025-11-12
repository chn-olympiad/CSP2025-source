#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e5+5;
int n, q;
string s[N][2];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s[i][0]>>s[i][1];
	while(q--) {
		string t, to;
		cin>>t>>to;
		int res=0;
		for(int i=1;i<=n;++i) {
			auto it=t.find(s[i][0]);
			if(it!=string::npos) {
				auto _t=t;
				_t.replace(it, s[i][0].size(), s[i][1]);
				if(_t==to)	++res;
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}

