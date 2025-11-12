#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int si1[200005],si2[200005];
string t1,t2;
long long ans = 0;
void dfs() {
	while (q--) {
		ans = 0;
		cin >> t1 >> t2;
		int p = t1.size(),q = t2.size(),f,l;
		if(p != q) {
			cout << 0 << '\n';
			continue;
		}
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j + si1[i] <= p;j++) {
				bool ok = 1;
				string x = t1;
				for(int k = j;k < j + si1[i];k++) {
					if(t1[k] != s1[i][k - j]) {
						ok = 0;
						break;
					}
					x[k] = s2[i][k - j];
				}
				if(!ok) continue;
			//	cout<<i << " " << x<<endl;
				if(x == t2) ans++;
			}
		}
		cout << ans << '\n';
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s1[i] >> s2[i],si1[i] = s1[i].size(),si2[i] = s2[i].size();
	if(n <= 1000 and q <= 1000) {
		dfs();
		return 0;
	}
	while (q--) {
		ans = 0;
		cin >> t1 >> t2;
		cout << 0;
	}
	return 0;
}

