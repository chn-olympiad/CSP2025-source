#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Max = 2e5 + 9;
map <string,string> t;
string a[Max],b[Max];
int n,q;
string gets(string a,int x,int y) {
	string z = "";
	for(int i = x;i <= y;i++) z += a[i];
	return z;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) {
		string s1,s2;
		cin >> s1 >> s2;
		a[i] = s1,b[i] = s2;
		t[s1] = s2;
	}
	for(int i = 1;i <= q;i++) {
		int ans = 0;
		string s1,s2;
		cin >> s1 >> s2;
		int l = s1.length();
		s1 = " " + s1,s2 = " " + s2;
		for(int j = 1;j <= n;j++) {
			int p = a[j].length();
			for(int z = 1;z <= l - p + 1;z++) {
				if(s1[z] == a[j][0]) {
//					cout << z << "ok\n";
//					cout << gets(s1,z,z+p-1) << "\n";
					if(gets(s1,z,z+p-1) == a[j]) {
//						cout << "okok\n";
//						cout << gets(s1,1,z-1) << " " << b[z] << " " << gets(s1,z+p,l) << "\n";
//						cout << s2 << endl;
						if(gets(s1,0,z-1) + b[z] + gets(s1,z+p,l) == s2) {
//							cout << "okokok" << endl;
							ans++;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
