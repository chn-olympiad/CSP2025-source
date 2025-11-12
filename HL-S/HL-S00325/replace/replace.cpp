#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string a[100000], b[100000], s, d;
int n;

void solve() {
	cin>>s>>d;
	int m = s.size(), ans = 0;
	s = " " + s;
//	cout<<s.substr(1, 0)<<"\n";
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m - a[i].size() + 1;j++) {
			bool h = 1;
			for(int k = 0;k < a[i].size();k++) {
				if(s[j + k] != a[i][k]) { h = 0; break; }
			}
			ans += (h && s.substr(1, j - 1) + b[i] + s.substr(j + a[i].size()) == d);
		}
	}
	cout<<ans<<"\n";
}

/*

4 2
xabcx
xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/

/*

3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int q;
	cin>>n>>q;
	for(int i = 1;i <= n;i++) {
		cin>>a[i]>>b[i];
	}
	while(q--) solve();
	return 0;
}