#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

int n,q;
map<string,string> m;

void solve(){
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		m[s1] = s2;
	}
	while(q--){
		string t1,t2;
		int ans = 0;
		cin >> t1 >> t2;
		int len = t1.size(),lenn = t2.size();
		if(len != lenn){
			cout << 0 << '\n';
			continue;
		}		
		for(int i=0;i<len;i++){
			string s = "";
			for(int j=i;j<len;j++){
				s += t1[j];
				if(m.find(s) != m.end()){
					string ss = "";
					for(int k=0;k<i;k++)ss += t1[k];
					ss += m[s];
					for(int k=j+1;k<len;k++)ss += t1[k];
					if(ss == t2)ans++;
				}
			}
		}
		cout << ans << '\n';
		ans = 0;
	}
	return;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
