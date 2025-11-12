#include<bits/stdc++.h>
using namespace std;
map<string, int> mp;
int n, q, ans = 0;
string s[200005][2], qi, ho;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 1; i <= q; i++) {
		ans=0;
		cin >> qi >> ho;
		int l1 = 0, r1 = qi.size() - 1;
		while (qi[l1] == ho[l1]) {
			l1++;
		}
		while (qi[r1] == ho[r1]) {
			r1--;
		}
		string st = "", st1 = "";
		for (int j = l1; j <= r1; j++) {
			st += qi[j];
			st1 += ho[j];
		}
		for (int j = 1; j <= n; j++) {
			string di="",di1="";
			for (int k = 0; k < s[j][1].size(); k++) {
				if(s[j][1][k]!=s[j][0][k]||s[j][1][k]!=qi[k]||s[j][0][k]!=qi[k]){
					di+=s[j][1][k];
					di1+=s[j][0][k];
				}
			}
//			cout<<di1<<' '<<di<<'\n';
			if (di1 == st && di == st1) {
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}