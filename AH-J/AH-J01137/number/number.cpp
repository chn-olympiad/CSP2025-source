#include <bits/stdc++.h>
#define endl '\n';
#define ll long long 
using namespace std;
string s;
char c[1000005];
int len;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			c[++len]=s[i];
		}
	}
	sort(c+1,c+len+1);
	for(int i=len; i>=1; i--) cout << c[i];
	return 0;
}
