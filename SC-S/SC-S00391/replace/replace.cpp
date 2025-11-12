#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 200010;
string a[N],b[N];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++) {
		cin >> a[i] >> b[i];
	}
	while(q--) {
		string s1,s2;
		cin >> s1 >> s2;
		int ans = 0;
		for(int i=0;i<s1.size();i++) {
			for(int j=1;j<=n;j++) {
				if(s1[i] != a[j][0]) {
					continue;
				}
				string t = s1;
				if(s1.size() - i < a[j].size()) {
					continue;
				}
				string k = t.substr(i,a[j].size());
//				cout << k << " ";
				if(k == a[j]) {
					for(int k=i;k<i+a[j].size();k++) {
						t[k] = b[j][k-i];
					}
				}
//				cout << t << " " << endl;
				if(t == s2) {
//					cout << a[j] << " " << b[j] << endl;
					ans ++ ;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
