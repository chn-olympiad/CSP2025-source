#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int n,q;
string s1[N],s2[N];
string t1,t2;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s1[i]>>s2[i];
	}
	while(q--) {
		int ans = 0;
		cin >> t1 >> t2;
		for(int t = 1; t <= n; t++) {
			for(int i = 0; i < t1.size(); i++) {
				if(t1[i] == s1[t][0]) {
					int flag = 1;
					for(int j = 1; j < s1[t].size(); j++) {
						if(t1[i + j] == s1[t][j])continue;
						flag = 0;
						break;
					}
					if(flag) {
						string tt = t1;
						for(int j = 0; j < s1[t].size(); j++) {
							tt[i + j] = s2[t][j];
						}
						if(tt == t2)ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
